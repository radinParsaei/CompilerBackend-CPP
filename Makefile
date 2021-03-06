override CFLAGS := $(CFLAGS) -IVM -IVM/BigNumber/src -IVM/Value -I.

all: VM_make test
.PHONY: all

ifeq ($(USE_GMP_LIB),1)
override CFLAGS := $(CFLAGS) -DUSE_GMP_LIB
VM_make:
	@(cd VM && $(MAKE) EXT_CFLAGS="-DUSE_GMP_LIB" VM.o number.o BigNumber.o) 2>&1 > /dev/null
.PHONY: VM_make
test: SyntaxTree.o test.cpp VM_make
	$(CXX) $(CFLAGS) test.cpp SyntaxTree.o VM/VM.o -lgmp -lgmpxx -ldl -pthread -o test
else
test: SyntaxTree.o test.cpp VM_make
	$(CXX) $(CFLAGS) test.cpp SyntaxTree.o VM/VM.o VM/number.o VM/BigNumber.o -ldl -pthread -o test
VM_make:
	(cd VM && $(MAKE) VM.o number.o BigNumber.o) 2>&1 > /dev/null
	.PHONY: VM_make
endif


ifeq ($(USE_GMP_LIB),1)
SyntaxTree.o: SyntaxTree.cpp
	$(CXX) $(CFLAGS) -c SyntaxTree.cpp -DUSE_GMP_LIB
else
SyntaxTree.o: SyntaxTree.cpp
	$(CXX) $(CFLAGS) -c SyntaxTree.cpp
endif

clean:
	$(RM) test SyntaxTree.o
	@(cd VM && $(MAKE) clean)
