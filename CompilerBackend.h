#ifndef COMPILER_BACKEND_H
#define COMPILER_BACKEND_H

#include <VM.h>
#include <map>
#include <Errors.h>

using namespace std;

namespace CompilerBackend {
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

  class isEQ : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    isEQ(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class isFEQ : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    isFEQ(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class isGT : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    isGT(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class isGE : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    isGE(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class isLT : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    isLT(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class isLE : public Base {
  private:
    Base* v1;
    Base* v2;
  public:
    isLE(Base* v1, Base* v2);
    std::vector<Value> toVMByteCode() override;
  };

  class Not : public Base {
  private:
    Base* v;
  public:
    Not(Base* v);
    std::vector<Value> toVMByteCode() override;
  };

  class Print : public Base {
  private:
    Base* data;
  public:
    Print(Base* data);
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
