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
class StackImpl {
  public:
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
class Stack {
  public:
    Stack(size_t size = 0): impl_(size) {
    }
    ~Stack() = default;
    Stack(Stack const &other): impl_(other.impl_.vused_) {
      while (impl_.vused_ < other.impl_.vused_) {
        construct(impl_.v_ + impl_.vused_, other.impl_.v_[impl_.vused_]);
        ++(impl_.vused_);
      }
    }
    Stack &operator=(Stack const &rhs) {
      Stack temp(rhs); // may throw exception
      impl_.Swap(temp.impl_); // noexcept
      return *this;
    }
    size_t Count() const {
      return impl_.vused_;
    }
    void Push(T const &item) {
      if (impl_.vused_ == impl_.vsize_) {
        size_t const vsize_new = 2 * impl_.vsize_ + 1;
        Stack temp(vsize_new);
        while (temp.Count() < impl_.vused_) {
          temp.Push(impl_.v_[temp.Count()]);
        }
        temp.Push(item);
        impl_.Swap(temp);
      } else {
        construct(impl_.v_ + impl_.vused_, item);
        ++(impl_.vused_);
      }
    }
    void Pop() {
      if (impl_.vused_ == 0) {
        throw std::domain_error("empty error");
      }
      --(impl_.vused_);
      destroy(impl_.v_ + impl_.used);
    }
    T &Top() {
      if (impl_.vused_ == 0) {
        throw std::domain_error("empty error");
      }
      return impl_.v_[impl_.used_ - 1];
    }
    T const &Top() const {
      if (impl_.vused_) {
        throw std::domain_error("empty error");
      }
      return impl_.v_[impl_.vused_ - 1];
    }
    bool Empty() const {
      return Count() == 0;
    }
  private:
    StackImpl<T> impl_;
};

int main() {
  Stack<std::string> s;
  Stack<std::string> t = s;
  Stack<std::string> u;
  s = u;
  return 0;
}
