#include <vector>
#include <functional>
#include <algorithm>

#include <string>
#include <random>
#include <type_traits>
#include <cassert>

using namespace ::std;

class MulSortAlg
{
private:
	vector<size_t> _k;
	vector<size_t> _kinverse;
	vector<bool> _placed;

private:
	template<typename T>
	void PlaceElement(vector<T>& data, size_t m, T& val)
	{
		static int xxxUseRecur = 0;
		if (xxxUseRecur)
		{
			if (!_placed[m])
			{
				_placed[m] = true;
				std::swap(data[m], val);
				size_t kim = _kinverse[m];
				PlaceElement(data, kim, val);
			}

		}
		else
		{
			while (!_placed[m])
			{
				_placed[m] = true;
				std::swap(data[m], val);
				m = _kinverse[m];
			}
		}

	}

public:
	template<typename T>
	void SortK(const vector<T>& data, function<bool(const T&, const T&)> cmp)
	{
		_k.resize(data.size());
		for (size_t ii = 0; ii < _k.size(); ++ii)
		{
			_k[ii] = ii;
		}

		auto cmpk = [&](size_t i0, size_t i1)
		{
			return cmp(data[i0], data[i1]);
		};
		std::sort(_k.begin(), _k.end(), cmpk);

		_kinverse.resize(data.size());
		for (size_t ii = 0; ii < _k.size(); ++ii)
		{
			_kinverse[_k[ii]] = ii;
		}
	}

	template<typename T>
	void Place(vector<T>& data)
	{
		_placed.clear();
		_placed.resize(_k.size());
		for (size_t ii = 0; ii < _k.size(); ++ii)
		{
			if (!_placed[ii])
			{
				T val = data[_k[ii]];
				PlaceElement(data, ii, val);
			}
		}
	}
};

//#######################################################################
template<typename ITER>
static void FillRandom(ITER begin, ITER end, remove_cvref_t<decltype(*begin)> scalar, long long minval, long long maxval, long long invalidVal)
{
	random_device randDevice;
	mt19937_64 randEngine(randDevice());
	uniform_int_distribution<long long> randDistrib(minval, maxval);

	while (begin != end)
	{
		long long randVal = randDistrib(randEngine);
		if (randVal != invalidVal)
		{
			*begin = randVal * scalar;
			++begin;
		}
	}
}


template<typename T>
static bool VerfyOrder(const vector<T>& data, function<bool(const T&, const T&)> cmp)
{
	bool ok = true;
	for (size_t ii = 1; ii < data.size(); ++ii)
	{
		ok = cmp(data[ii-1], data[ii]);
		if (!ok)
		{
			assert(false);
			break;
		}
	}
	return ok;
}

void TestSort()
{
	constexpr int SIZE = 17*19;
	vector<int> veci(SIZE);
	FillRandom(veci.begin(), veci.end(), 1, -SIZE*10, SIZE*10, 0);

	vector<string> vecs;
	for (auto ii : veci)
	{
		vecs.emplace_back(to_string(ii));
	}


	MulSortAlg alg;
	alg.SortK<int>(veci, [](int i0, int i1) {
		return i0 < i1;
		});
	alg.Place(veci);
	alg.Place(vecs);

	assert(VerfyOrder<int>(veci, [](int i0, int i1) {
		return i0 <= i1;
		}));

	for (size_t ii = 0; ii < veci.size(); ++ii)
	{
		assert(to_string(veci[ii]) == vecs[ii]);
	}
}