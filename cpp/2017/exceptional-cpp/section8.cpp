#include <cstdlib>

template <class T>
class Stack {
  public:
    Stack():
      v_(nullptr),
      vsize_(0),
      vused_(0)
    {}
    ~Stack() {
      delete[] v_;
    }

  private:
    T *v_;
    size_t vsize_;
    size_t vused_;
};