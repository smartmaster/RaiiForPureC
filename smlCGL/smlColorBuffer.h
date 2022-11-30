#pragma once

#include <memory>

namespace SmartLib
{
	template<typename T, int LEN>
	struct Vec
	{
		T _data[LEN];

		Vec() :
			_data{ 0 }
		{
		}

		template<typename... TARGS>
		Vec(TARGS&& ... args) :
			_data{ std::forward<TARGS>(args)... }
		{

		}

		const Vec& operator+=(const Vec& other)
		{
			for (int ii = 0; ii < LEN; ++ ii)
			{
				_data[ii] += other._data[ii];
			}

			return *this;
		}


		Vec operator+(const Vec& other) const
		{
			Vec rv = *this;
			for (int ii = 0; ii < LEN; ++ii)
			{
				rv._data[ii] += other._data[ii];
			}

			return rv;
		}

		const Vec& operator-=(const Vec& other)
		{
			for (int ii = 0; ii < LEN; ++ii)
			{
				_data[ii] -= other._data[ii];
			}

			return *this;
		}

		Vec operator-(const Vec& other) const
		{
			Vec rv = *this;
			for (int ii = 0; ii < LEN; ++ii)
			{
				rv._data[ii] -= other._data[ii];
			}

			return rv;
		}


		const Vec& operator/=(T div)
		{
			for (int ii = 0; ii < LEN; ++ii)
			{
				_data[ii] /= div;
			}

			return *this;
		}

		Vec operator/(T div) const
		{
			Vec rv = *this;
			for (int ii = 0; ii < LEN; ++ii)
			{
				rv._data[ii] /= div;
			}

			return rv;
		}
	};

	template<typename T>
	class ColorBuffertest;

	template<typename T>
	class ColorBuffer
	{
		friend class ColorBuffertest<T>;
	private:
		int _screenSizeH{ 0 };
		int _screenSizeV{ 0 };
		int _msaaHalfH{ 0 };
		int _msaaHalfV{ 0 };

		int _screenPointsH{ 0 };
		int _screenPointsV{ 0 };

		int _msaaH{ 0 };
		int _msaaV{ 0 };
		int _msaaHVSize{ 0 };

		int _screenMsaaPointsH{ 0 };
		int _screenMsaaPointsV{ 0 };

		int _screenMsaaPointFirstH{ 0 };
		int _screenMsaaPointLastH{ 0 };
		int _screenMsaaPointSizeH{ 0 };

		int _screenMsaaPointFirstV{ 0 };
		int _screenMsaaPointLastV{ 0 };
		int _screenMsaaPointSizeV{ 0 };


		T* _colorRaw{ nullptr };
		Vec<T, 4>* _color{ nullptr };

	private:
		// [-1, 1] --> [_screenMsaaPointFirstH, _screenMsaaPointLastH]
		int NdcToMsaaH(T ndch) const
		{
			return int(_screenMsaaPointSizeH * (ndch + 1) / 2 + _screenMsaaPointFirstH + T{ 0.5 });
		}


		// [-1, 1] --> [_screenMsaaPointLastV, _screenMsaaPointFirstV]
		int NdcToMsaaV(T ndcv) const
		{
			return int(_screenMsaaPointLastV - _screenMsaaPointSizeV * (ndcv + 1) / 2 + T{ 0.5 });
		}

		int ScreenToMsaaLeftH(int sh) const
		{
			return (sh * _msaaH)/* + _msaaHalfH*/;
		}

		int ScreenToMsaaTopV(int sv) const
		{
			return (sv * _msaaV)/* + _msaaHalfV*/;
		}


		const Vec<T, 4>& At(int hh, int vv) const
		{
			return _color[vv * _screenMsaaPointsH + hh];
		}

		Vec<T, 4>& At(int hh, int vv)
		{
			return _color[vv * _screenMsaaPointsH + hh];
		}

	public:

		virtual ~ColorBuffer()
		{
			if (_colorRaw)
			{
				_color = nullptr;
				free(_colorRaw);
				_colorRaw = nullptr;
			}
		}
		void SetBufferSize(int screenSizeH, int screenSizeV, int msaaHalfH, int msaaHalfV)
		{
			_screenSizeH = screenSizeH;
			_screenSizeV = screenSizeV;
			_msaaHalfH = msaaHalfH;
			_msaaHalfV = msaaHalfV;

			_screenPointsH = screenSizeH + 1;
			_screenPointsV = screenSizeV + 1;

			_msaaH = 2 * msaaHalfH + 1;
			_msaaV = 2 * msaaHalfV + 1;
			_msaaHVSize = _msaaH * _msaaV;

			_screenMsaaPointsH = _screenPointsH * _msaaH;
			_screenMsaaPointsV = _screenPointsV * _msaaV;

			_screenMsaaPointFirstH = msaaHalfH;
			_screenMsaaPointLastH = _screenMsaaPointsH - msaaHalfH - 1;
			_screenMsaaPointSizeH = _screenMsaaPointLastH - _screenMsaaPointFirstH;

			_screenMsaaPointFirstV = msaaHalfV;
			_screenMsaaPointLastV = _screenMsaaPointsV - msaaHalfV - 1;
			_screenMsaaPointSizeV = _screenMsaaPointLastV - _screenMsaaPointFirstV;
		}

		void SetNdcColor(T ndcH, T ndcV, const Vec<T, 4>& color)
		{
			if (nullptr == _color)
			{
				int bufferSizeBytes = _screenMsaaPointsH * _screenMsaaPointsV * 4 * sizeof(T);
				_colorRaw = (T*)malloc(bufferSizeBytes);
				memset(_colorRaw, 0, bufferSizeBytes);
				_color = reinterpret_cast<Vec<T,4>*>(_colorRaw);
			}
			int ih = NdcToMsaaH(ndcH);
			int iv = NdcToMsaaV(ndcV);

			ih -= _msaaHalfH;
			iv -= _msaaHalfV;

			auto* prow = &At(ih, iv);
			for (int vv = 0; vv < _msaaV; ++vv)
			{
				auto* pcolumn = prow;
				for (int hh = 0; hh < _msaaH; ++hh)
				{
					*pcolumn = color;
					++pcolumn;
				}
				prow += _screenMsaaPointsH;
			}
		}

		Vec<T, 4> GetScreenColor(int sh, int sv) const
		{
			Vec<T, 4> rv{};// {0, 0, 0, 0};

			int msaaLeftH = ScreenToMsaaLeftH(sh);
			int msaaTopV = ScreenToMsaaTopV(sv);


			const auto* prow = &At(msaaLeftH, msaaTopV);
			for (int vv = 0; vv < _msaaV; ++vv)
			{
				const auto* pcolumn = prow;
				for (int hh = 0; hh < _msaaH; ++hh)
				{
					rv += *pcolumn;
					++pcolumn;
				}
				prow += _screenMsaaPointsH;
			}

			rv /= T(_msaaHVSize);

			return rv;
		}
	};
}