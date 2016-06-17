#include<cmath>
#include"network.hh"

using namespace std;
using namespace Eigen;

VectorXd network::sigmoid(const VectorXd& vec){
  double sum = 0;
  for(int i = 0; i < vec.size(); ++i){
    sum += vec[i];
  }
  return 1.0 / (1 + exp(-sum) );
}

MatrixXd network::feed(VectorXd a){
  for(int i = 0; i < mSizes.size(); ++i){
    a = sigmoid(mWeights[i].dot(a) + mBiases[i]);
  }
	return a;
}

