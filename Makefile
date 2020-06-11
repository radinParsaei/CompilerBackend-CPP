override CFLAGS := $(CFLAGS) -IVM -IVM/BigNumber/src -IVM/Value -I.

all: VM_make test
.PHONY: all

VM_make:
	@(cd VM && $(MAKE) VM.o number.o BigNumber.o) 2>&1 > /dev/null
.PHONY: VM_make

test: CompilerBackend.o test.cpp VM_make
	$(CXX) $(CFLAGS) test.cpp CompilerBackend.o VM/VM.o VM/number.o VM/BigNumber.o -ldl -pthread -o test

CompilerBackend.o: CompilerBackend.cpp
	$(CXX) $(CFLAGS) -c CompilerBackend.cpp

clean:
	$(RM) test CompilerBackend.o
