#pragma once

#include <cassert>
#include "smlColorBuffer.h"

namespace SmartLib
{

	template<typename T = double>
	class ColorBuffertest
	{
	public:

		template<typename T>
		static bool IsCloseFloat(T val1, T val2, T relTol, T absTol)
		{
			//
			T relTolVal = relTol * std::max(std::abs(val1), std::abs(val2));
			return std::abs(val1 - val2) <= std::max(relTolVal, absTol);
		}

		static void Case3()
		{
			ColorBuffer<T> cb;
			int sh = 267;
			int sv = 357;
			int msaaHalfH = 3;
			int msaaHalfV = 2;
			cb.SetBufferSize(sh, sv, msaaHalfH, msaaHalfV);

			T hh[] = { -1.0, 1.0 };
			T vv[] = { -1.0, 1.0 };
			Vec<T, 4> color{ .5, .6, .7, 1.0 };
			for (T h : hh)
			{
				for (T v : vv)
				{
					cb.SetNdcColor(h, v, color);
					color._data[0] += 0.1;
				}
			}


			{
				int shh[] = { 0, sh };
				int svv[] = { sv, 0 };
				T expected = 0.5;
				for (auto hh : shh)
				{
					for (auto vv : svv)
					{
						auto color = cb.GetScreenColor(hh, vv);
						assert(IsCloseFloat(expected, color._data[0], 1e-9, 1e-6));
						expected += 0.1;
					}
				}

			}
		}

		static void Case2()
		{
			ColorBuffer<T> cb;
			int sh = 267;
			int sv = 357;
			int msaaHalfH = 3;
			int msaaHalfV = 2;
			cb.SetBufferSize(sh, sv, msaaHalfH, msaaHalfV);

			T hh[] = { -1.0, 0.0, 1.0 };
			T vv[] = { -1.0, 0.0, 1.0 };
			Vec<T, 4> color{ .5, .6, .7, 1.0 };
			for (T h : hh)
			{
				for (T v : vv)
				{
					cb.SetNdcColor(h, v, color);
				}
			}
		}

		static void Case1()
		{
			ColorBuffer<T> cb;
			int sh = 267;
			int sv = 987;
			int msaaHalfH = 17;
			int msaaHalfV = 31;
			cb.SetBufferSize(sh, sv, msaaHalfH, msaaHalfV);

			int hn1 = cb.NdcToMsaaH(-1.0);
			assert(msaaHalfH == hn1);
			int hp1 = cb.NdcToMsaaH(1.0);
			assert((sh + 1) * (2 * msaaHalfH + 1) - msaaHalfH - 1 == hp1);
			int h0 = cb.NdcToMsaaH(0.0);
			assert(int((hn1 + hp1) / 2.0 + 0.5) == h0);

			int vn1 = cb.NdcToMsaaV(-1.0);
			assert((sv + 1) * (2 * msaaHalfV + 1) - msaaHalfV - 1 == vn1);
			int vp1 = cb.NdcToMsaaV(1.0);
			assert(msaaHalfV == vp1);
			int v0 = cb.NdcToMsaaV(0.0);
			assert(int((vn1 + vp1) / 2.0 + 0.5) == v0);
		}


		static void Case0()
		{
			ColorBuffer<T> cb;
			cb.SetBufferSize(100, 200, 0, 0);

			int hn1 = cb.NdcToMsaaH(-1.0);
			assert(0 == hn1);
			int h0 = cb.NdcToMsaaH(0.0);
			assert(50 == h0);
			int hp1 = cb.NdcToMsaaH(1.0);
			assert(100 == hp1);

			int vn1 = cb.NdcToMsaaV(-1.0);
			assert(200 == vn1);
			int v0 = cb.NdcToMsaaV(0.0);
			assert(100 == v0);
			int vp1 = cb.NdcToMsaaV(1.0);
			assert(0 == vp1);
		}
	};
}