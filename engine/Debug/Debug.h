//#define NDEBUG //Uncomment to disable debug functions or, preferably run g++ with -DNDEBUG
#ifndef DEBUG_H
#define DEBUG_H
#ifndef NDEBUG
namespace Debug{
struct exception {
 int error_code;
 exception(int e): error_code(e) {}
};

void* warningMalloc(int size);
}
#include "Debug.cpp"
#define malloc Debug::warningMalloc
#include <cassert>
#define assertm(exp, msg) assert((void(msg), exp))
#else
#define malloc std::malloc
#endif //NDEBUG
struct exception {
 int error_code;
 exception(int e): error_code(e) {}
};
#endif //DEBUG_H
