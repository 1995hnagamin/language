#include <algorithm>
#include <cstdlib>

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
      v_(new T[other.vsize_]),
      vsize_(other.vsize_),
      vused_(other.vused_)
    {
      for (size_t i = 0; i < vsize_; ++i) {
        v_[i] = other.v_[i];
      }
    }
    Stack &operator=(Stack const &rhs) {
      Swap(rhs);
      return *this;
    }

  private:
    static size_t const initial_stack_size = 10;
    T *v_;
    size_t vsize_;
    size_t vused_;
    void Swap(Stack const &other) {
      using std::swap;
      swap(v_, other.v_);
      swap(vsize_, other.vsize_);
      swap(vused_, other.vused_);
    }
};

int main() {
}