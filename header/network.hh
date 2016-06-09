#ifndef __NETWORK_HH__
#define __NETWORK_HH__

#include<vector>
#include<random>
#include<glm/mat...>

class network{
private:
	std::vector<unsigned int> mSizes;
	std::vector<unsigned int> mBiases;
	std::vector<unsigned int> mWeights;

public:
	template<class iterator>
  network(iterator begin, iterator end):
		mSizes(begin, end){
		std::random_device rd;
		std::mt19937 rate(rd());
		std::normal_distributian<> gene(0, 1);
	}
};

#endif

