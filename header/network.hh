#ifndef __NETWORK_HH__
#define __NETWORK_HH__

#include"layer.hh"

class network{
private:
  layer mInput;
  layer mOutput;

public:
  network(unsigned int inSize, unsigned int outSize);

  template<class iterator>
  void train(iterator begin, iterator end){
    while(*begin != *end){
      train(begin->first, begin->second);
      ++begin;
    }
  }
  void train(double input, double output);
  double ask(double val) const;
};

#endif

