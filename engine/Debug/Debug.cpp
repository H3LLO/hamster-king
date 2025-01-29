#include <stdlib.h>
#include <iostream>

namespace Debug {
 void* warningMalloc(int size) {
  void* pokeTheVoid = std::malloc(size);
  if (pokeTheVoid == NULL) {
   std::cout << "Malloc failed" << std::endl;
   throw exception(1);
  }
  return pokeTheVoid;
 }
}
