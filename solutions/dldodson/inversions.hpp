#ifndef _INVERSIONS_HPP_
#define _INVERSIONS_HPP_

/*
 * This is a modified version of
 * Dr. Chappell's Merge Sort algorithm.
 */

#include <vector>
using std::vector;

template <typename RAIter>
const size_t stableMerge(const RAIter & begin, const RAIter & middle, const RAIter & end) {
	auto count = 0;
	using Value = typename std::remove_reference<decltype(*begin)>::type;
	
	vector<Value> buffer(distance(begin, end));
	
	auto in1 = begin;
	auto in2 = middle;
	auto out = buffer.begin();
	
	while(in1 != middle && in2 != end) {
		if(*in2 < *in1) {
			*out++ = *in2++;
			count += (middle - in1);
		}
		else
			*out++ = *in1++;
	}
	
	copy(in1, middle, out);
	copy(in2, end, out);
	
	copy(buffer.begin(), buffer.end(), begin);
	
	return count;
}

template <typename RAIter>
const size_t mergeSort(const RAIter & begin, const RAIter & end) {
	auto count = 0;
	
	auto size = distance(begin, end);
	
	if(size <= 1)
		return 0;
	
	auto middle = begin;
	advance(middle, size/2);
	
	count += mergeSort(begin, middle);
	count += mergeSort(middle, end);
	
	return stableMerge(begin, middle, end) + count;
}


template<typename RAIter>
const size_t inversions(const RAIter & begin, const RAIter & end) {
	return mergeSort(begin, end);
}

#endif