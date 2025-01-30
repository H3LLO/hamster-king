#include <stdlib.h>
#include <iostream>

namespace Debug {
 void* warningMalloc(int size) {
  void* pokeTheVoid = std::malloc(size);
  if (pokeTheVoid == NULL) {
   std::cout << "Malloc failed" << std::endl;
   throw stop_struct(1);
  }
  return pokeTheVoid;
 }

 void warningFree(void* &voidPtr) {
  if (voidPtr == NULL || voidPtr == nullptr) {
   std::cout << "Attempting to free a null, likely a double free" << std::endl;
   throw stop_struct(2);
  }
  std::free(voidPtr);
  voidPtr = nullptr;
 }
}
