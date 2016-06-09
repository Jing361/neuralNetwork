#ifndef __LAYER_HH__
#define __LAYER_HH__

#include<vector>
#include<memory>
#include"neuron.hh"

class layer{
private:
  std::vector<std::shared_ptr<neuron> > neurons;

public:
  layer(int size);

  void connect(const layer& other);
};

#endif

