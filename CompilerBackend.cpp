#include "CompilerBackend.h"

using namespace std;

CompilerBackend::Number::Number(Value data) {
  this->data = data;
}

std::vector<Value> CompilerBackend::Number::toVMByteCode() {
  std::vector<Value> a;
  a.push_back(PUT);
  a.push_back(data);
  return a;
}

CompilerBackend::Print::Print(Base* data) {
  this->data = data;
}

std::vector<Value> CompilerBackend::Print::toVMByteCode() {
  std::vector<Value> a = data->toVMByteCode();
  a.push_back(PRINT);
  return a;
}
