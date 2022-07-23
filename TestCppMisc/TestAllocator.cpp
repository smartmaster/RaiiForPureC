

#include <memory>
#include <list>
#include <string>
#include <cstdlib>
#include <cassert>
#include <iostream>



using namespace ::std;

class MemAlloc
{
private:
	char mem[1024 * 64] = { 0 };
	size_t _offset{ 0 };

	static constexpr size_t ALLIGNMENT = 15; //allign must be of (2^N - 1)
	template<typename SZ>
	SZ AllignSize(SZ len)
	{
		return (len + ALLIGNMENT) & (~ALLIGNMENT);
	}

public:
	void deallocate(void* const _Ptr, const size_t _Count) {

		memset(_Ptr, -1, AllignSize(_Count));
	}

	void* allocate(const size_t _Count) {

		void* ret = nullptr;
		auto count = AllignSize(_Count);
		if (_offset + count <= sizeof(mem))
		{
			ret = mem + _offset;
			_offset += count;
		}
		return ret;
	}

	void* begin()
	{
		return mem;
	}

	void* end()
	{
		return mem + sizeof(mem);
	}
};

//#define _HAS_DEPRECATED_ALLOCATOR_MEMBERS 1

template <class _Ty, class _TMemAlloc>
class sss_allocator {
public:
	shared_ptr<_TMemAlloc> _memAlloc; //althogh public, do not use the member outside of the class

public:
	static_assert(!is_const_v<_Ty>, "The C++ Standard forbids containers of const elements "
		"because sss_allocator<const T> is ill-formed.");

	using _From_primary = sss_allocator;

	using value_type = _Ty;

#if _HAS_DEPRECATED_ALLOCATOR_MEMBERS
	_CXX17_DEPRECATE_OLD_ALLOCATOR_MEMBERS typedef _Ty* pointer;
	_CXX17_DEPRECATE_OLD_ALLOCATOR_MEMBERS typedef const _Ty* const_pointer;

	_CXX17_DEPRECATE_OLD_ALLOCATOR_MEMBERS typedef _Ty& reference;
	_CXX17_DEPRECATE_OLD_ALLOCATOR_MEMBERS typedef const _Ty& const_reference;
#endif // _HAS_DEPRECATED_ALLOCATOR_MEMBERS

	using size_type = size_t;
	using difference_type = ptrdiff_t;

	using propagate_on_container_move_assignment = true_type;
	using is_always_equal _CXX20_DEPRECATE_IS_ALWAYS_EQUAL = true_type;

#if _HAS_DEPRECATED_ALLOCATOR_MEMBERS
	template <class _Other>
	struct _CXX17_DEPRECATE_OLD_ALLOCATOR_MEMBERS rebind {
		using other = sss_allocator<_Other, _TMemAlloc>;
	};

	_CXX17_DEPRECATE_OLD_ALLOCATOR_MEMBERS _NODISCARD _Ty* address(_Ty& _Val) const noexcept {
		return _STD addressof(_Val);
	}

	_CXX17_DEPRECATE_OLD_ALLOCATOR_MEMBERS _NODISCARD const _Ty* address(const _Ty& _Val) const noexcept {
		return _STD addressof(_Val);
	}
#endif // _HAS_DEPRECATED_ALLOCATOR_MEMBERS

	constexpr sss_allocator() noexcept :
		_memAlloc{ make_shared<_TMemAlloc>() } //ssssssssssss
	{
	}

	constexpr sss_allocator(const sss_allocator&) noexcept = default;

	template <class _Other>
	constexpr sss_allocator(const sss_allocator<_Other, _TMemAlloc>& other) noexcept
	{
		_memAlloc = other._memAlloc; //ssssssssssss
	}

	_CONSTEXPR20 ~sss_allocator() = default;
	_CONSTEXPR20 sss_allocator& operator=(const sss_allocator&) = default;

	void* begin()
	{
		return _memAlloc->begin();
	}

	void* end()
	{
		return _memAlloc->end();
	}

	_CONSTEXPR20 void deallocate(_Ty* const _Ptr, const size_t _Count) {
		//if (_memAlloc)
		//{
		_memAlloc->deallocate(_Ptr, sizeof(_Ty) * _Count);
		//}
		//else
		//{
		//    _STL_ASSERT(_Ptr != nullptr || _Count == 0, "null pointer cannot point to a block of non-zero size");
		//    // no overflow check on the following multiply; we assume _Allocate did that check
		//    _Deallocate<_New_alignof<_Ty>>(_Ptr, sizeof(_Ty) * _Count);
		//}
	}

	_NODISCARD _CONSTEXPR20 __declspec(allocator)_Ty* allocate(_CRT_GUARDOVERFLOW const size_t _Count) {
		//if (_memAlloc)
		//{
		return static_cast<_Ty*>(_memAlloc->allocate(sizeof(_Ty) * _Count));
		//}
		//else
		//{
		//    return static_cast<_Ty*>(_Allocate<_New_alignof<_Ty>>(_Get_size_of_n<sizeof(_Ty)>(_Count)));
		//}

	}

#if _HAS_CXX23
	_NODISCARD constexpr allocation_result<_Ty*> allocate_at_least(_CRT_GUARDOVERFLOW const size_t _Count) {
		return { allocate(_Count), _Count };
	}
#endif // _HAS_CXX23

#if _HAS_DEPRECATED_ALLOCATOR_MEMBERS
	_CXX17_DEPRECATE_OLD_ALLOCATOR_MEMBERS _NODISCARD __declspec(allocator)_Ty* allocate(
		_CRT_GUARDOVERFLOW const size_t _Count, const void*) {
		return allocate(_Count);
	}

	template <class _Objty, class... _Types>
	_CXX17_DEPRECATE_OLD_ALLOCATOR_MEMBERS void construct(_Objty* const _Ptr, _Types&&... _Args) {
		::new (_Voidify_iter(_Ptr)) _Objty(_STD forward<_Types>(_Args)...);
	}

	template <class _Uty>
	_CXX17_DEPRECATE_OLD_ALLOCATOR_MEMBERS void destroy(_Uty* const _Ptr) {
		_Ptr->~_Uty();
	}

	_CXX17_DEPRECATE_OLD_ALLOCATOR_MEMBERS _NODISCARD size_t max_size() const noexcept {
		return static_cast<size_t>(-1) / sizeof(_Ty);
	}
#endif // _HAS_DEPRECATED_ALLOCATOR_MEMBERS

	static constexpr size_t _Minimum_allocation_alignment = _Asan_granularity;
};



void CaseTestAlloc()
{
	list<string, sss_allocator<string, MemAlloc>> lstr;
	auto allocator = lstr.get_allocator();

	for (int ii = 0; ii < 100; ++ii)
	{
		lstr.emplace_back(std::to_string(ii));
	}

	
	for (const auto& str : lstr)
	{
		cout << str << endl;

		const void* pdata = str.data();
		assert(pdata >= allocator.begin() && pdata < allocator.end());

		pdata = &str;
		assert(pdata >= allocator.begin() && pdata < allocator.end());
	}
}