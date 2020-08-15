#include "SyntaxTree.h"

SyntaxTree::Number::Number(Value data) {
  this->data = data;
}

std::vector<Value> SyntaxTree::Number::toVMByteCode() {
  std::vector<Value> a;
  a.push_back(PUT);
  a.push_back(data);
  return a;
}

SyntaxTree::Text::Text(Value data) {
  this->data = data;
}

std::vector<Value> SyntaxTree::Text::toVMByteCode() {
  std::vector<Value> a;
  a.push_back(PUT);
  a.push_back(data);
  return a;
}

SyntaxTree::Boolean::Boolean(Value data) {
  this->data = data;
}

std::vector<Value> SyntaxTree::Boolean::toVMByteCode() {
  std::vector<Value> a;
  a.push_back(PUT);
  a.push_back(data);
  return a;
}

std::vector<Value> SyntaxTree::Null::toVMByteCode() {
  std::vector<Value> a;
  a.push_back(PUT);
  a.push_back(null);
  return a;
}

SyntaxTree::Add::Add(Base* v1, Base* v2) {
  this->v1 = v1;
  this->v2 = v2;
}

std::vector<Value> SyntaxTree::Add::toVMByteCode() {
  std::vector<Value> a = v2->toVMByteCode();
  for (Value i : v1->toVMByteCode()) {
    a.push_back(i);
  }
  a.push_back(ADD);
  return a;
}

SyntaxTree::Sub::Sub(Base* v1, Base* v2) {
  this->v1 = v1;
  this->v2 = v2;
}

std::vector<Value> SyntaxTree::Sub::toVMByteCode() {
  std::vector<Value> a = v2->toVMByteCode();
  for (Value i : v1->toVMByteCode()) {
    a.push_back(i);
  }
  a.push_back(SUB);
  return a;
}

SyntaxTree::Mul::Mul(Base* v1, Base* v2) {
  this->v1 = v1;
  this->v2 = v2;
}

std::vector<Value> SyntaxTree::Mul::toVMByteCode() {
  std::vector<Value> a = v2->toVMByteCode();
  for (Value i : v1->toVMByteCode()) {
    a.push_back(i);
  }
  a.push_back(MUL);
  return a;
}

SyntaxTree::Div::Div(Base* v1, Base* v2) {
  this->v1 = v1;
  this->v2 = v2;
}

std::vector<Value> SyntaxTree::Div::toVMByteCode() {
  std::vector<Value> a = v2->toVMByteCode();
  for (Value i : v1->toVMByteCode()) {
    a.push_back(i);
  }
  a.push_back(DIV);
  return a;
}

SyntaxTree::Mod::Mod(Base* v1, Base* v2) {
  this->v1 = v1;
  this->v2 = v2;
}

std::vector<Value> SyntaxTree::Mod::toVMByteCode() {
  std::vector<Value> a = v2->toVMByteCode();
  for (Value i : v1->toVMByteCode()) {
    a.push_back(i);
  }
  a.push_back(MOD);
  return a;
}

SyntaxTree::Equals::Equals(Base* v1, Base* v2) {
  this->v1 = v1;
  this->v2 = v2;
}

std::vector<Value> SyntaxTree::Equals::toVMByteCode() {
  std::vector<Value> a = v2->toVMByteCode();
  for (Value i : v1->toVMByteCode()) {
    a.push_back(i);
  }
  a.push_back(EQ);
  return a;
}

SyntaxTree::StrictEquals::StrictEquals(Base* v1, Base* v2) {
  this->v1 = v1;
  this->v2 = v2;
}

std::vector<Value> SyntaxTree::StrictEquals::toVMByteCode() {
  std::vector<Value> a = v2->toVMByteCode();
  for (Value i : v1->toVMByteCode()) {
    a.push_back(i);
  }
  a.push_back(FEQ);
  return a;
}

SyntaxTree::GreaterThan::GreaterThan(Base* v1, Base* v2) {
  this->v1 = v1;
  this->v2 = v2;
}

std::vector<Value> SyntaxTree::GreaterThan::toVMByteCode() {
  std::vector<Value> a = v2->toVMByteCode();
  for (Value i : v1->toVMByteCode()) {
    a.push_back(i);
  }
  a.push_back(GT);
  return a;
}

SyntaxTree::GreaterThanOrEqual::GreaterThanOrEqual(Base* v1, Base* v2) {
  this->v1 = v1;
  this->v2 = v2;
}

std::vector<Value> SyntaxTree::GreaterThanOrEqual::toVMByteCode() {
  std::vector<Value> a = v2->toVMByteCode();
  for (Value i : v1->toVMByteCode()) {
    a.push_back(i);
  }
  a.push_back(GE);
  return a;
}

SyntaxTree::LesserThan::LesserThan(Base* v1, Base* v2) {
  this->v1 = v1;
  this->v2 = v2;
}

std::vector<Value> SyntaxTree::LesserThan::toVMByteCode() {
  std::vector<Value> a = v2->toVMByteCode();
  for (Value i : v1->toVMByteCode()) {
    a.push_back(i);
  }
  a.push_back(LT);
  return a;
}

SyntaxTree::LesserThanOrEqual::LesserThanOrEqual(Base* v1, Base* v2) {
  this->v1 = v1;
  this->v2 = v2;
}

std::vector<Value> SyntaxTree::LesserThanOrEqual::toVMByteCode() {
  std::vector<Value> a = v2->toVMByteCode();
  for (Value i : v1->toVMByteCode()) {
    a.push_back(i);
  }
  a.push_back(LE);
  return a;
}

SyntaxTree::And::And(Base* v1, Base* v2) {
  this->v1 = v1;
  this->v2 = v2;
}

std::vector<Value> SyntaxTree::And::toVMByteCode() {
  std::vector<Value> a = v2->toVMByteCode();
  for (Value i : v1->toVMByteCode()) {
    a.push_back(i);
  }
  a.push_back(LAND);
  return a;
}

SyntaxTree::Not::Not(Base* v) {
  this->v = v;
}

std::vector<Value> SyntaxTree::Not::toVMByteCode() {
  std::vector<Value> a = v->toVMByteCode();
  a.push_back(LNOT);
  return a;
}

SyntaxTree::BitwiseNot::BitwiseNot(Base* v) {
  this->v = v;
}

std::vector<Value> SyntaxTree::BitwiseNot::toVMByteCode() {
  std::vector<Value> a = v->toVMByteCode();
  a.push_back(NOT);
  return a;
}

SyntaxTree::Negative::Negative(Base* v) {
  this->v = v;
}

std::vector<Value> SyntaxTree::Negative::toVMByteCode() {
  std::vector<Value> a = v->toVMByteCode();
  a.push_back(NEG);
  return a;
}

SyntaxTree::Print::Print(Base* data) {
  this->data = data;
}

std::vector<Value> SyntaxTree::Print::toVMByteCode() {
  std::vector<Value> a = data->toVMByteCode();
  a.push_back(PRINT);
  return a;
}

SyntaxTree::SetVariable::SetVariable(std::string variableName, Base* data) {
  this->variableName = variableName;
  this->data = data;
}

std::vector<Value> SyntaxTree::SetVariable::toVMByteCode() {
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

SyntaxTree::Variable::Variable(std::string variableName) {
  this->variableName = variableName;
}

std::vector<Value> SyntaxTree::Variable::toVMByteCode() {
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
