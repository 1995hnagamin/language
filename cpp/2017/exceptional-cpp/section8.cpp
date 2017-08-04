#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <string>

template <class T>
T *NewCopy(T const *src, size_t srcsize, size_t dstsize) {
  assert(dstsize >= srcsize);
  T *dst = new T[dstsize];
    // `operator new[]` may throw std::bad_alloc
    // `T::T` may throw some exceptions
  try {
    std::copy(src, src + srcsize, dst);
  } catch (...) {
    delete[] dst; // don't throw exceptions
    throw;
  }
  return dst;
}

template <class T>
class Stack {
  public:
    Stack():
      v_(new T[initial_stack_size]),
      vsize_(initial_stack_size),
      vused_(0)
    {}
    ~Stack() {
      delete[] v_;
    }
    Stack(Stack const &other):
      v_(NewCopy(other.v_, other.vused_, other.vsize_)),
      vsize_(other.vsize_),
      vused_(other.vused_)
    {}
    Stack &operator=(Stack const &rhs) {
      if (this != &rhs) {
        T *v_new = NewCopy(rhs.v_, rhs.vused_, rhs.vsize_);
          // may throw
        delete[] v_;
        v_ = v_new;
        vsize_ = rhs.vsize_;
        vused_ = rhs.vused_;
      }
      return *this;
    }

  private:
    static size_t const initial_stack_size = 10;
    T *v_;
    size_t vsize_;
    size_t vused_;
};

int main() {
  Stack<std::string> s;
  Stack<std::string> t = s;
  Stack<std::string> u;
  s = u;
  return 0;
}