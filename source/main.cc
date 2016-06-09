#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<fstream>
#include<sstream>
#include"network.hh"

using namespace std;

int main(int argc, char** argv){
  basic_istream<char> input(nullptr);
  fstream file("");

  if(argc > 1){
    file.open(argv[1]);
    input.rdbuf(file.rdbuf());
  } else {
    input.rdbuf(cin.rdbuf());
  }

  vector<pair<double, double> > vals;
  string str;
  while(input >> str){
    size_t idx = str.find(',');
    double x = stod(str.substr(0, idx));
    double y = stod(str.substr(idx + 1));
    vals.emplace_back(x, y);
  }

  return 0;
}

