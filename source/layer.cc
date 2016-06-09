#include"neuron.hh"
#include"layer.hh"

using namespace std;

layer::layer(int size){
  for(;size > 0; --size){
    neurons.emplace_back(make_shared<neuron>());
  }
}

void layer::connect(const layer& other){
  for(auto n:neurons){
    for(auto l:other.neurons){
      n->connect(l);
    }
  }
  (void)other;
}

