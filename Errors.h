#ifndef ERRORS_H
#define ERRORS_H
#include <ErrorCodes.h>
inline void error(char errcode, std::string arg = "") {
  switch (errcode) {
    case ERROR_VARIABLE_DOES_NOT_EXISTS:
      std::cout << "Variable " << arg << " not defined\n";
      exit(1);
      break;
  }
}
#endif
