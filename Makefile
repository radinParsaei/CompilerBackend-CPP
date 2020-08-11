override CFLAGS := $(CFLAGS) -IVM -IVM/BigNumber/src -IVM/Value -I.

all: VM_make test
.PHONY: all

ifeq ($(USE_GMP_LIB),1)
override CFLAGS := $(CFLAGS) -DUSE_GMP_LIB
VM_make:
	@(cd VM && $(MAKE) EXT_CFLAGS="-DUSE_GMP_LIB" VM.o number.o BigNumber.o) 2>&1 > /dev/null
.PHONY: VM_make
test: CompilerBackend.o test.cpp VM_make
	$(CXX) $(CFLAGS) test.cpp CompilerBackend.o VM/VM.o -lgmp -lgmpxx -ldl -pthread -o test
else
test: CompilerBackend.o test.cpp VM_make
	$(CXX) $(CFLAGS) test.cpp CompilerBackend.o VM/VM.o VM/number.o VM/BigNumber.o -ldl -pthread -o test
VM_make:
	(cd VM && $(MAKE) VM.o number.o BigNumber.o) 2>&1 > /dev/null
	.PHONY: VM_make
endif


ifeq ($(USE_GMP_LIB),1)
CompilerBackend.o: CompilerBackend.cpp
	$(CXX) $(CFLAGS) -c CompilerBackend.cpp -DUSE_GMP_LIB
else
CompilerBackend.o: CompilerBackend.cpp
	$(CXX) $(CFLAGS) -c CompilerBackend.cpp
endif

clean:
	$(RM) test CompilerBackend.o
	@(cd VM && $(MAKE) clean)
