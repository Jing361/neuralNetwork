#ifndef __NEURON_HH__
#define __NEURON_HH__

#include<map>
#include<memory>

class neuron{
private:
  class neuronComp{
  public:
    bool operator()(const std::shared_ptr<neuron>& lhs, const std::shared_ptr<neuron>& rhs){
      return lhs->mID < rhs->mID;
    }
  };

  static long IDcounter;
  long mID;
  std::map<std::shared_ptr<neuron>, std::pair<double, double>, neuronComp> mInputs;

public:
  neuron();
  virtual ~neuron();

  void connect(std::shared_ptr<neuron> other, double weight = 0.0, double bias = 0.0);
  void fire();
};

#endif

