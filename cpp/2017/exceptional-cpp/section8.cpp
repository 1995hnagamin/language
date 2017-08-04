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

  private:
    static size_t const initial_stack_size = 10;
    T *v_;
    size_t vsize_;
    size_t vused_;
};

int main() {
}