#include<cmath>
#include"network.hh"

using namespace std;

double network::sigmoid(Eigen::MatrixXd z){
  return 1.0 / (1 + exp(-z));
}

Eigen::MatrixXd network::feed(Eigen::MatrixXd a){
  for(int i = 0; i < mSizes.size(); ++i){
    a = sigmoid(mWeights[i].dot(a) + mBiases[i]);
  }
}

