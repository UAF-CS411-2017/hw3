#ifndef _CONTIGSUM_HPP_
#define _CONTIGSUM_HPP_

template<typename RAIter>
const int contigSum(const RAIter & begin, const RAIter & end) {
	int max = 0;
	int tempMax = 0;

	for(auto i = begin; i < end; i++) {
		tempMax += *i;

		if(tempMax < 0)
			tempMax = 0;

		if(tempMax > max)
			max = tempMax;
	}
	
	return max;
}

#endif