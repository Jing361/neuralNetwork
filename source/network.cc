#include<cmath>
#include"network.hh"

using namespace std;
using namespace Eigen;

double network::sigmoid(const VectorXd& vec){
  double sum = 0;
  for(int i = 0; i < vec.size(); ++i){
    sum += vec[i];
  }
  return 1.0 / (1 + exp(-sum) );
}

VectorXd network::feed(VectorXd a){
  for(int i = 0; i < mSizes.size(); ++i){
    a(i) = sigmoid((mWeights[i] * a) + mBiases[i]);
  }
	return a;
}

