#include "func.h"

template <typename T>
void func(T) { }

template void func<int>(int);
template void func<double>(double);
