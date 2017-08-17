template <typename T>
inline T const& max(T const& a, T const& b) {
  return a < b ? b : a;
}

namespace BigMath {

class BigNumber {
  public:
    int to_int() const;
};

bool operator <(BigNumber const& a, BigNumber const& b) {
  return a.to_int() < b.to_int();
}

} // namespace BigMath

using BigMath::BigNumber;

void g(BigNumber const& a, BigNumber const& b) {
  BigNumber x = max(a, b); // ADL
}
