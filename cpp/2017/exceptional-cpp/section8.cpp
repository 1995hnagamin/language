#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <stdexcept>
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
class StackImpl {
  protected:
    StackImpl(size_t size = 0):
      v_(new T[size]),
      vsize_(size),
      vused_(size)
    {}
    ~StackImpl() {
      delete[] v_;
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
    size_t Count() const {
      return vused_;
    }
    void Push(T const &item) {
      if (vused_ == vsize_) {
        size_t const vsize_new = vsize_ * 2 + 1;
        T *v_new = NewCopy(v_, vused_, vsize_new);
        delete[] v_;
        v_ = v_new;
        vsize_ = vsize_new;
      }
      v_[vused_] = item;
        // ここで失敗するかもしれないが、
        // その場合ただ領域が大きくなるだけで
        // 実害はない
      ++vused_;
    }
    void Pop() {
      if (!vused_) {
        throw std::domain_error("Pop empty stack");
      }
      --vused_;
    }
    T &Top() {
      if (!vused_) {
        throw std::domain_error("Empty stack");
      }
      return v_[vused_ - 1];
    }
    T const &Top() const {
      if (!vused_) {
        throw std::domain_error("Empty stack");
      }
      return v_[vused_ - 1];
    }
    bool Empty() const {
      return (vused_ == 0);
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
