#include "CompilerBackend.h"

CompilerBackend::Number::Number(Value data) {
  this->data = data;
}

std::vector<Value> CompilerBackend::Number::toVMByteCode() {
  std::vector<Value> a;
  a.push_back(PUT);
  a.push_back(data);
  return a;
}

CompilerBackend::Text::Text(Value data) {
  this->data = data;
}

std::vector<Value> CompilerBackend::Text::toVMByteCode() {
  std::vector<Value> a;
  a.push_back(PUT);
  a.push_back(data);
  return a;
}

CompilerBackend::Add::Add(Base* v1, Base* v2) {
  this->v1 = v1;
  this->v2 = v2;
}

std::vector<Value> CompilerBackend::Add::toVMByteCode() {
  std::vector<Value> a = v2->toVMByteCode();
  for (Value i : v1->toVMByteCode()) {
    a.push_back(i);
  }
  a.push_back(ADD);
  return a;
}

CompilerBackend::Sub::Sub(Base* v1, Base* v2) {
  this->v1 = v1;
  this->v2 = v2;
}

std::vector<Value> CompilerBackend::Sub::toVMByteCode() {
  std::vector<Value> a = v2->toVMByteCode();
  for (Value i : v1->toVMByteCode()) {
    a.push_back(i);
  }
  a.push_back(SUB);
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
