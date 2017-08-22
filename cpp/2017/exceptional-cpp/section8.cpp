#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <stdexcept>
#include <string>

template <class T1, class T2>
void construct(T1 *p, T2 const &value) {
  new (p) T1(value);
}

template <class T>
void destroy(T *p) {
  p->~T();
}

template <class FwdIter>
void destroy(FwdIter first, FwdIter last) {
  while (first != last) {
    destroy(&*first);
    ++first;
  }
}

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
class StackImpl {
  protected:
    StackImpl(size_t size = 0):
      v_(static_cast<T*>(
            size == 0 ?
                nullptr
              : operator new(sizeof(T) * size))),
      vsize_(size),
      vused_(0)
    {}
    ~StackImpl() {
      destroy(v_, v_ + vused_); // do not throw exceptions
      operator delete(v_);
    }
    StackImpl(StackImpl const &) = delete;
    StackImpl &operator=(StackImpl const &) = delete;
    void Swap(StackImpl &other) noexcept {
      using std::swap;
      swap(v_, other.v_);
      swap(vsize_, other.vsize_);
      swap(vused_, other.vused_);
    }
    T *v_;
    size_t vsize_;
    size_t vused_;
};

template <class T>
class Stack : private StackImpl<T> {
  public:
    Stack(size_t size = 0): StackImpl<T>(size) {
    }
    ~Stack() = default;
    Stack(Stack const &other): StackImpl<T>(other.vsize_) {
      std::copy(other.v_, other.v_ + other.vused_, this->v_);
    }
    Stack &operator=(Stack const &rhs) {
      StackImpl<T> stack_new(rhs.vsize_);
      std::copy(rhs.v_, rhs.v_ + rhs.vused_, stack_new.v_);
      this->Swap(stack_new);
    }
    size_t Count() const {
      return this->vused_;
    }
    void Push(T const &item) {
      if (this->vused_ == this->vsize_) {
        size_t const vsize_new = 2 * this->vsize_ + 1;
        StackImpl<T> stack_new(vsize_new);
        this->Swap(stack_new);
      }
      this->v_[this->vused_] = item;
      ++(this->vused_);
    }
    void Pop() {
      if (this->vused_ == 0) {
        throw std::domain_error("empty error");
      }
      destroy(this->v_ + this->used - 1);
    }
    T &Top() {
      if (this->vused_ == 0) {
        throw std::domain_error("empty error");
      }
      return this->v_[this->used_ - 1];
    }
    T const &Top() const {
      if (this->vused_) {
        throw std::domain_error("empty error");
      }
      return this->v_[this->vused_ - 1];
    }
    bool Empty() const {
      return Count() == 0;
    }
};

int main() {
  Stack<std::string> s;
  Stack<std::string> t = s;
  Stack<std::string> u;
  s = u;
  return 0;
}
