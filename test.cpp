#include <CompilerBackend.h>

using namespace std;
using namespace CompilerBackend;

int main() {
  Base* a[] = {
    new SetVariable("a", new Text("Hello")),
    new SetVariable("a", new Number(10)),
    new Print(new Text("Text")),
    new Print(new Add(new Variable("a"), new Number(100)))
  };

  cout << "PROGRAM:\n";
  vector<Value> prog;
  prog.push_back(PUT);
  prog.push_back(-1);
  prog.push_back(MEMPUT);
  for (int i = 0; i < sizeof(a) / sizeof(Base*); i++) {
    for (Value v : a[i]->toVMByteCode()) {
      prog.push_back(v);
    }
  }

  for (size_t pc = 0; pc < prog.size(); pc++) {
    cout << VM::disassemble(prog[pc].getLong(), (prog.size() - 1) == pc? 0:prog[pc + 1]) << endl;
    if (prog[pc].getLong() == PUT) pc++;
  }

  cout << "\nRUN:\n";
  VM vm;
  vector<Value> mem;
  vm.attachMem(&mem);
  vm.run(prog);
  cout << "\nMEM:\n";
  for (Value i : mem) {
    cout << i << endl;
  }
}
