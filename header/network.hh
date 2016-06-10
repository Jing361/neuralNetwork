#ifndef __NETWORK_HH__
#define __NETWORK_HH__

#include<vector>
#include<random>
#include<eigen/Dense>

class network{
private:
  std::vector<unsigned long long> mSizes;
  std::vector<Eigen::MatrixXd> mBiases;
  std::vector<Eigen::MatrixXd> mWeights;

public:
  template<class iterator>
  network(iterator begin, iterator end):
    mSizes(begin, end){
    std::random_device rd;
    std::mt19937 rate(rd());
    std::normal_distribution<> gene(0, 1);

    for(auto it:mSizes){
      mBiases.emplace_back(it - 1, 1);
      for(int i = 1; i < it; ++i){
        mBiases.back()(i, 0) = gene(rate);
      }
    }

    for(int i = 0; i < mSizes.size(); ++i){
      auto it = mSizes[i];
      mWeights.emplace_back(it - 1, it - 1);
      for(int j = 0; j < mSizes.size() - 1; ++j){
        for(int k = 1; k < mSizes.size(); ++k){
          mWeights.back()(k, j) = gene(rate);
        }
      }
    }
  }
};

#endif

