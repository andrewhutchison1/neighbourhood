#ifndef AH1_NEIGHBOURHOOD_HPP_
#define AH1_NEIGHBOURHOOD_HPP_

#include <iterator>

#include <cassert>

#include "advance_bounded/advance_bounded.hpp"

namespace ah1 {

// Computes the left neighburhood of an element in a range, of size
// less than or equal to n. Returns an iterator to the start of the
// neighbourhood such that the start does not exceed first.
template <typename BidIt, typename Size>
auto neighbourhood_left(BidIt first, BidIt element, Size n) -> BidIt
{
	assert((n >= 0));
	advance_bounded(first, element, element, -n);
	return element;
}

// Computes the right neighbourhood of an element in a range, of size
// less than or equal to n. Returns an iterator to one past the end of the
// neighbourhood such that the end does not exceed last.
template <typename FwdIt, typename Size>
auto neighbourhood_right(FwdIt last, FwdIt element, Size n) -> FwdIt
{
	assert((n >= 0));
	advance_bounded(element, last, element, n + 1);
	return element;
}

// Computes the neighbourhood of an element consisting of at most
// n elements either side of element. Returns a pair of iterators
// [first, last) that contains element.
template <typename BidIt, typename Size>
auto neighbourhood(BidIt first, BidIt last, BidIt element, Size n)
		-> std::pair<BidIt, BidIt>
{
	assert((n >= 0));

	return {
		neighbourhood_left(first, element, n),
		neighbourhood_right(last, element, n)
	};
}

} // namespace ah1

#endif // AH1_NEIGHBOURHOOD_HPP_
