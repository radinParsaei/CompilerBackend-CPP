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

CompilerBackend::Mul::Mul(Base* v1, Base* v2) {
  this->v1 = v1;
  this->v2 = v2;
}

std::vector<Value> CompilerBackend::Mul::toVMByteCode() {
  std::vector<Value> a = v2->toVMByteCode();
  for (Value i : v1->toVMByteCode()) {
    a.push_back(i);
  }
  a.push_back(MUL);
  return a;
}

CompilerBackend::Div::Div(Base* v1, Base* v2) {
  this->v1 = v1;
  this->v2 = v2;
}

std::vector<Value> CompilerBackend::Div::toVMByteCode() {
  std::vector<Value> a = v2->toVMByteCode();
  for (Value i : v1->toVMByteCode()) {
    a.push_back(i);
  }
  a.push_back(DIV);
  return a;
}

CompilerBackend::Mod::Mod(Base* v1, Base* v2) {
  this->v1 = v1;
  this->v2 = v2;
}

std::vector<Value> CompilerBackend::Mod::toVMByteCode() {
  std::vector<Value> a = v2->toVMByteCode();
  for (Value i : v1->toVMByteCode()) {
    a.push_back(i);
  }
  a.push_back(MOD);
  return a;
}

CompilerBackend::isEQ::isEQ(Base* v1, Base* v2) {
  this->v1 = v1;
  this->v2 = v2;
}

std::vector<Value> CompilerBackend::isEQ::toVMByteCode() {
  std::vector<Value> a = v2->toVMByteCode();
  for (Value i : v1->toVMByteCode()) {
    a.push_back(i);
  }
  a.push_back(EQ);
  return a;
}

CompilerBackend::isFEQ::isFEQ(Base* v1, Base* v2) {
  this->v1 = v1;
  this->v2 = v2;
}

std::vector<Value> CompilerBackend::isFEQ::toVMByteCode() {
  std::vector<Value> a = v2->toVMByteCode();
  for (Value i : v1->toVMByteCode()) {
    a.push_back(i);
  }
  a.push_back(FEQ);
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

CompilerBackend::SetVariable::SetVariable(std::string variableName, Base* data) {
  this->variableName = variableName;
  this->data = data;
}

std::vector<Value> CompilerBackend::SetVariable::toVMByteCode() {
  std::vector<Value> a = data->toVMByteCode();
  if (variables.find(variableName) == variables.end()) {
    variablesCounter++;
    variables.insert(std::make_pair(variableName, variablesCounter));
    a.push_back(PUT);
    a.push_back(variablesCounter);
    a.push_back(MEMPUT);
    a.push_back(MEMPUT);
  } else {
    a.push_back(REC);
    a.push_back(PUT);
    a.push_back(0);
    a.push_back(MEMGET);
    a.push_back(PUT);
    a.push_back(-1);
    a.push_back(EQ);
    a.push_back(END);
    a.push_back(PUT);
    a.push_back(0);
    a.push_back(MEMGET);
    a.push_back(PUT);
    a.push_back(-1);
    a.push_back(EQ);
    a.push_back(WFRUN);
    a.push_back(PUT);
    a.push_back(1);
    a.push_back(PUT);
    a.push_back(0);
    a.push_back(MEMSET);
    a.push_back(REC);
    a.push_back(PUT);
    a.push_back(0);
    a.push_back(MEMGET);
    a.push_back(PUT);
    a.push_back(1);
    a.push_back(ADD);
    a.push_back(PUT);
    a.push_back(0);
    a.push_back(MEMSET);
    a.push_back(BREAK);
    a.push_back(END);
    a.push_back(REC);
    a.push_back(PUT);
    a.push_back(0);
    a.push_back(MEMGET);
    a.push_back(MEMGET);
    a.push_back(PUT);
    a.push_back(variables[variableName]);
    a.push_back(EQ);
    a.push_back(IFTRUN);
    a.push_back(POP);
    a.push_back(PUT);
    a.push_back(0);
    a.push_back(MEMGET);
    a.push_back(PUT);
    a.push_back(2);
    a.push_back(ADD);
    a.push_back(PUT);
    a.push_back(0);
    a.push_back(MEMSET);
    a.push_back(END);
    a.push_back(PUT);
    a.push_back(2);
    a.push_back(MEMSIZE);
    a.push_back(DIV);
    a.push_back(REPEAT);
    a.push_back(POP);
    a.push_back(POP);
    a.push_back(POP);
    a.push_back(POP);
    a.push_back(POP);
    a.push_back(POP);
    a.push_back(POP);
    a.push_back(POP);
    a.push_back(PUT);
    a.push_back(0);
    a.push_back(MEMGET);
    a.push_back(PUT);
    a.push_back(-1);
    a.push_back(PUT);
    a.push_back(0);
    a.push_back(MEMSET);
    a.push_back(MEMSET);
  }
  return a;
}

CompilerBackend::Variable::Variable(std::string variableName) {
  this->variableName = variableName;
}

std::vector<Value> CompilerBackend::Variable::toVMByteCode() {
  std::vector<Value> a;
  if (variables.find(variableName) == variables.end()) {
    error(ERROR_VARIABLE_DOES_NOT_EXISTS, variableName);
  } else {
    a.push_back(REC);
    a.push_back(PUT);
    a.push_back(0);
    a.push_back(MEMGET);
    a.push_back(PUT);
    a.push_back(-1);
    a.push_back(EQ);
    a.push_back(END);
    a.push_back(PUT);
    a.push_back(0);
    a.push_back(MEMGET);
    a.push_back(PUT);
    a.push_back(-1);
    a.push_back(EQ);
    a.push_back(WFRUN);
    a.push_back(PUT);
    a.push_back(1);
    a.push_back(PUT);
    a.push_back(0);
    a.push_back(MEMSET);
    a.push_back(REC);
    a.push_back(PUT);
    a.push_back(0);
    a.push_back(MEMGET);
    a.push_back(PUT);
    a.push_back(1);
    a.push_back(ADD);
    a.push_back(PUT);
    a.push_back(0);
    a.push_back(MEMSET);
    a.push_back(BREAK);
    a.push_back(END);
    a.push_back(REC);
    a.push_back(PUT);
    a.push_back(0);
    a.push_back(MEMGET);
    a.push_back(MEMGET);
    a.push_back(PUT);
    a.push_back(variables[variableName]);
    a.push_back(EQ);
    a.push_back(IFTRUN);
    a.push_back(POP);
    a.push_back(PUT);
    a.push_back(0);
    a.push_back(MEMGET);
    a.push_back(PUT);
    a.push_back(2);
    a.push_back(ADD);
    a.push_back(PUT);
    a.push_back(0);
    a.push_back(MEMSET);
    a.push_back(END);
    a.push_back(PUT);
    a.push_back(2);
    a.push_back(MEMSIZE);
    a.push_back(DIV);
    a.push_back(REPEAT);
    a.push_back(POP);
    a.push_back(POP);
    a.push_back(POP);
    a.push_back(POP);
    a.push_back(POP);
    a.push_back(POP);
    a.push_back(POP);
    a.push_back(POP);
    a.push_back(PUT);
    a.push_back(0);
    a.push_back(MEMGET);
    a.push_back(PUT);
    a.push_back(-1);
    a.push_back(PUT);
    a.push_back(0);
    a.push_back(MEMSET);
    a.push_back(MEMGET);
  }
  return a;
}
