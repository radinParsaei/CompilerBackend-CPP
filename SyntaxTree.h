#ifndef SYNTAX_TREE_H
#define SYNTAX_TREE_H

#include <VM.h>
#include <map>
#include <Errors.h>

using namespace std;

namespace SyntaxTree {
  inline std::map<std::string, int> variables;
  inline int variablesCounter;

  class Base {
  public:
    virtual std::vector<Value> toVMByteCode() = 0;
  };

  class Number : public Base {
  private:
    Value data;
  public:
    Number(Value data);
    std::vector<Value> toVMByteCode() override;
  };

  class Text : public Base {
  private:
    Value data;
  public:
    Text(Value data);
    std::vector<Value> toVMByteCode() override;
  };

  class Boolean : public Base {
  private:
    Value data;
  public:
    Boolean(Value data);
    std::vector<Value> toVMByteCode() override;
  };

  class Null : public Base {
  public:
    std::vector<Value> toVMByteCode() override;
  };

  class Add : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    Add(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class Sub : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    Sub(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class Mul : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    Mul(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class Div : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    Div(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class Mod : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    Mod(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class Equals : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    Equals(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class StrictEquals : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    StrictEquals(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class GreaterThan : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    GreaterThan(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class GreaterThanOrEqual : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    GreaterThanOrEqual(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class LesserThan : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    LesserThan(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class LesserThanOrEqual : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    LesserThanOrEqual(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class And : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    And(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class Or : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    Or(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class Xor : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    Xor(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class BitwiseAnd : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    BitwiseAnd(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class BitwiseOr : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    BitwiseOr(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class LeftShift : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    LeftShift(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class RightShift : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    RightShift(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class Not : public Base {
  private:
    Base* v;
  public:
    Not(Base* v);
    std::vector<Value> toVMByteCode() override;
  };

  class Negative : public Base {
  private:
    Base* v;
  public:
    Negative(Base* v);
    std::vector<Value> toVMByteCode() override;
  };

  class BitwiseNot : public Base {
  private:
    Base* v;
  public:
    BitwiseNot(Base* v);
    std::vector<Value> toVMByteCode() override;
  };

  class Print : public Base {
  private:
    Base* data;
  public:
    Print(Base* data);
    std::vector<Value> toVMByteCode() override;
  };

  class Exit : public Base {
  private:
    Base* data;
  public:
    Exit(Base* data);
    std::vector<Value> toVMByteCode() override;
  };

  class SetVariable : public Base {
  private:
    std::string variableName;
    Base* data;
  public:
    SetVariable(std::string variableName, Base* data);
    std::vector<Value> toVMByteCode() override;
  };

  class Variable : public Base {
  private:
    std::string variableName;
  public:
    Variable(std::string variableName);
    std::vector<Value> toVMByteCode() override;
  };
}

#endif
