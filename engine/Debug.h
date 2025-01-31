//#define NDEBUG //Uncomment to disable debug functions or, preferably run g++ with -DNDEBUG
#ifndef DEBUG_H
#define DEBUG_H
#ifndef NDEBUG
namespace Debug{
struct stop_struct {
 int stop_code;
 stop_struct(int e): stop_code(e) {}
};

void* warningMalloc(int size);
void warningFree(void* &voidPtr);
}
#include "Debug/Debug.cpp"
#define malloc Debug::warningMalloc
#define free Debug::warningFree
#include <cassert>
#define assertm(exp, msg) assert((void(msg), exp))
#else
#define malloc std::malloc
#define free(ptr) (std::free(ptr); (ptr) = nullptr)
#endif //NDEBUG
struct stop_struct {
 int stop_code;
 stop_struct(int e): stop_code(e) {}
};
#endif //DEBUG_H
