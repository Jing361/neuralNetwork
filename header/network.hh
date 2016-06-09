#ifndef __NETWORK_HH__
#define __NETWORK_HH__

#include<vector>

class network{
private:
	std::vector<unsigned int> mSizes;
	std::vector<unsigned int> mBiases;
	std::vector<unsigned int> mWeights;

public:
	template<class iterator>
  network(iterator begin, iterator end):
		mSizes(begin, end){
	}
};

#endif

