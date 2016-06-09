#include<iostream>
#include"neuron.hh"

using namespace std;

neuron::neuron():
  mID(IDcounter++){
}

neuron::~neuron(){
}

void neuron::connect(shared_ptr<neuron> other, double weight, double bias){
  mInputs[other] = make_pair(weight, bias);
}

void neuron::fire(){
}

long neuron::IDcounter = 0;

