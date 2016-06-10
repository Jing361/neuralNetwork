#include<cmath>
#include<unsupported/Eigen/MatrixFunctions>
#include"network.hh"

using namespace std;

double network::sigmoid(Eigen::MatrixXd z){
  return 1.0 / (1 + (-z).exp());
}

Eigen::MatrixXd network::feed(Eigen::MatrixXd a){
  for(int i = 0; i < mSizes.size(); ++i){
    a = sigmoid(mWeights[i].dot(a) + mBiases[i]);
  }
}

