## neighbourhood

`neighbourhood` is a simple C++ algorithm to return a subrange of the elements
a specified number of positions either side of a given element. `neighbourhood`
 depends only on the STL and
[`advance_bounded`](https://github.com/andrewhutchison1/advance_bounded).

#### Usage

```
template <typename BidIt, typename Size>
	requires BidrectionalIterator<BidIt>
auto neighbourhood(BidIt first, BidIt last, BidIt element, Size n)
	-> std::pair<BidIt, BidIt>;

template <typename BidIt, typename Size>
	requires BidrectionalIterator<BidIt>
auto neighbourhood_left(BidIt first, BidIt element, Size n) -> BidIt;

template <template InIt, typename Size>
	requires InputIterator<InIt>
auto neighbourhood_right(InIt last, InIt element, Size n) -> InIt;
```

`neighbourhood` returns a `std::pair` of iterators that determine the range
of the elements at most `n` elements around `element`.

* `first` is an iterator to the lower bound of the range to restrict the
neighbourhood within
* `last` is an iterator to one-past-the-end of the upper bound of the range
to restrict the neighbourhood within
* `element` is an iterator to the element to compute the neighbourhood of
(i.e. the centre of the neighbourhood)
* `n` is the maximum number of elements to include either side of `element`

`neighbourhood_left` returns an iterator to the lower bound of the
neighbourhood. `neighbourhood_right` returns an iterator to the (exclusive)
upper bound of the neighbourhood. `first` must be strictly less than `last`
(so that `[first, last)` is a valid range). Some examples follow:

```
std::string const s{"0123456789"};
auto iter = std::find(s.begin(), s.end(), '5'); // iter points to '5'

// Get the range of one element either side of '5'
auto nhood = ah1::neighbourhood(s.begin(), s.end(), iter, 1);
assert(std::string{nhood.first, nhood.last} == "456");

iter = std::find(s.begin(), s.end(), '9'); // iter points to '9'

// Get the range of 3 elements either side of '9'
nhood = ah1::neighbourhood(s.begin(), s.end(), iter, 3);

// The returned range will not exceed [s.begin(), s.end())
assert(std::string{nhood.first, nhood.last} == "6789");
```

#### Installation

Place the header `neighbourhood.hpp` anywhere on you project's include path.
Ensure `advance_bounded.hpp` is visible to your compiler. A C++14 compliant
compiler is required.
