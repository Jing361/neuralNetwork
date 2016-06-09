#include"layer.hh"
#include"network.hh"

network::network(unsigned int inSize, unsigned int outSize):
  mInput(inSize),
  mOutput(outSize){
  mOutput.connect(mInput);
}

double network::ask(double val) const{
  (void)val;
  return 0.0;
}

void network::train(double input, double output){
  (void)input;
  (void)output;
}

