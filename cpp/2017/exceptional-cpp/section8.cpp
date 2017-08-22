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
    Stack(Stack const &other): StackImpl<T>(other.vused_) {
      while (this->vused_ < other.vused_) {
        construct(this->v_ + this->vused_, other.v_[this->vused_]);
        ++(this->vused_);
      }
    }
    Stack &operator=(Stack const &rhs) {
      Stack temp(rhs); // may throw exception
      this->Swap(temp); // noexcept
      return *this;
    }
    size_t Count() const {
      return this->vused_;
    }
    void Push(T const &item) {
      if (this->vused_ == this->vsize_) {
        size_t const vsize_new = 2 * this->vsize_ + 1;
        Stack temp(vsize_new);
        while (temp.Count() < this->vused_) {
          temp.Push(this->v_[temp.Count()]);
        }
        temp.Push(item);
        this->Swap(temp);
      } else {
        construct(this->v_ + this->vused_, item);
        ++(this->vused_);
      }
    }
    void Pop() {
      if (this->vused_ == 0) {
        throw std::domain_error("empty error");
      }
      --(this->vused_);
      destroy(this->v_ + this->used);
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
