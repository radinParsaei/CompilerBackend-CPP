#include <CompilerBackend.h>

using namespace std;
using namespace CompilerBackend;

int main() {
  Base* a[] = {
    new Print(new Text("Hello"))
  };

  cout << "PROGRAM:\n";
  vector<Value> prog = a[0]->toVMByteCode();
  for (size_t pc = 0; pc < prog.size(); pc++) {
    cout << VM::disassemble(prog[pc].getLong(), (prog.size() - 1) == pc? 0:prog[pc + 1]) << endl;
    if (prog[pc].getLong() == PUT) pc++;
  }

  cout << "\nRUN:\n";
  VM vm;
  vector<Value> mem;
  vm.attachMem(&mem);
  vm.run(prog);
}
