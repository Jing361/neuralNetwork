#ifndef __NETWORK_HH__
#define __NETWORK_HH__

#include<vector>
#include<random>
#include<Eigen/Dense>

class network{
private:
  std::vector<unsigned long long> mSizes;
  std::vector<Eigen::VectorXd> mBiases;
  std::vector<Eigen::MatrixXd> mWeights;

  Eigen::VectorXd sigmoid(const Eigen::VectorXd& vec);

public:
  template<class iterator>
  network(iterator begin, iterator end):
    mSizes(begin, end){
    std::random_device rd;
    std::mt19937 rate(rd());
    std::normal_distribution<> gene(0, 1);

    for(int i = 0; i < mSizes.size(); ++i){
      auto it = mSizes[i];
      mBiases.emplace_back(it - 1, 1);
      mWeights.emplace_back(it - 1, it - 1);

      for(int i = 1; i < it; ++i){
        mBiases.back()(i, 0) = gene(rate);
      }

      for(int j = 0; j < mSizes.size() - 1; ++j){
        for(int k = 1; k < mSizes.size(); ++k){
          mWeights.back()(k, j) = gene(rate);
        }
      }
    }
  }

  Eigen::VectorXd feed(Eigen::VectorXd a);
};

#endif

