#ifndef COMPILER_BACKEND_H
#define COMPILER_BACKEND_H

#include <VM.h>

using namespace std;

namespace CompilerBackend {
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

  class Print : public Base {
  private:
    Base* data;
  public:
    Print(Base* data);
    std::vector<Value> toVMByteCode() override;
  };
}

#endif
