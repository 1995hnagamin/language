#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define FOR(i,a,b) for (int i=(a),for_##i##_max=(b);i<=(for_##i##_max);++i)
#define RFOR(i,a,b) for (int i=(a),rfor_##i##_min=(b);i>=(rfor_##i##_min);--i)
#define REP(i,n) for (int i=0,rep_##i##_len=(n);i<(rep_##i##_len);++i)
#define RREP(i,n) for (int i=(n)-1;i>=0;--i)

namespace { // Basics

template<typename T>
void chmin(T &x, T y) {
  x = std::min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
  x = std::max(x, y);
}

template<typename T>
__attribute__((unused))
const auto minimum = static_cast<T const &(*)(T const &, T const &)>(std::min);

template<typename T>
__attribute__((unused))
const auto maximum = static_cast<T const &(*)(T const &, T const &)>(std::max);

template<typename T>
int cmp3(T lhs, T rhs) { return (lhs == rhs) ? 0 : (lhs > rhs) ? 1 : -1; }

template<typename T>
__attribute__((unused))
T constexpr infty = std::numeric_limits<T>::max / 3;
template<>
__attribute__((unused))
auto constexpr infty<int> = 1'100'100'100;
template<>
__attribute__((unused))
auto constexpr infty<long long int> = 100'500'400'300'200'100LL;

using lli = long long int;
using ld = long double;

} // namespace
namespace  { // Mod

template<int mod>
class modulo {
  public:
    constexpr modulo(): num(0) {}
    constexpr modulo(int n): num(n >= 0 ? n%mod : mod-((-n)%mod)) {}
    constexpr modulo(modulo const &) = default;
    constexpr int data() const { return num; }
    constexpr modulo &operator+=(modulo other) {
      num = (num + other.num) % mod;
      return *this;
    }
    constexpr modulo &operator-=(modulo other) {
      num = (num + mod - other.num) % mod;
      return *this;
    }
    constexpr modulo &operator*=(modulo other) {
      long long n = ((long long)num) * ((long long)other.num);
      num = n % mod;
      return *this;
    }
    constexpr modulo &operator/=(modulo other) {
      *this *= other.inverse();
      return *this;
    }
    constexpr static modulo pow(modulo a, int n, modulo res) {
      if (n == 0) { return res; }
      return pow(a*a, n/2, (n&1)?(res*a):res);
    }
    constexpr modulo inverse() const {
      return pow(*this, mod-2, modulo(1));
    }
  private:
    int num;
};

template<int mod>
constexpr modulo<mod> const operator+(modulo<mod> a, modulo<mod> b) {
  a += b;
  return a;
}

template<int mod>
constexpr modulo<mod> const operator-(modulo<mod> a, modulo<mod> b) {
  a -= b;
  return a;
}

template<int mod>
constexpr modulo<mod> const operator*(modulo<mod> a, modulo<mod> b) {
  a *= b;
  return a;
}

template<int mod>
constexpr modulo<mod> const pow(modulo<mod> a, int n) {
  return modulo<mod>::pow(a, n, 1);
}

template<int mod>
constexpr modulo<mod> const operator/(modulo<mod> a, modulo<mod> b) {
  a /= b;
  return a;
}

template<int mod, int size>
struct factorial {
  using Mod = modulo<mod>;
  Mod fact[size];
  Mod invfact[size];
  constexpr factorial(): fact(), invfact() {
    fact[0] = 1;
    for (int i = 1; i < size; ++i) {
      fact[i] = Mod(i) * fact[i-1];
    }
    invfact[size-1] = fact[size-1].inverse();
    for (int i = size - 1; i > 0; --i) {
      invfact[i-1] = invfact[i] * Mod(i);
    }
  }
  Mod const comb(int n, int k) const {
    assert(k <= n && n < size);
    return fact[n] * invfact[k] * invfact[n-k];
  }
};

} // namespace

using Mod = modulo<1'000'000'009>;

std::vector<Mod> zt(std::vector<Mod> const &v) {
  auto const N = v.size();
  std::vector<Mod> w(N, 0);
  REP(s, N) REP(i, N) {
    w[s] += v[i] * pow(Mod(s), i);
  }
  return w;
}

std::vector<Mod> conv(std::vector<Mod> const &a, std::vector<Mod> const &b) {
  auto const N = a.size();
  std::vector<Mod> v(N);
  REP(i, N) FOR(j, 0, i) {
    v[i] += a[i] * b[i-j];
  }
  return v;
}

void print(std::vector<Mod> const &v) {
  std::cout << "[";
  for (auto &&x : v) {
    std::cout << x.data() << ", ";
  }
  std::cout << "]" << std::endl;;
}

int main() {
  std::vector<Mod> a = { 3, 1, 4, 1, 5, 9, 2, 6, },
                   b = { 5, 3, 5, 8, 9, 7, 9, 3, };
  print(conv(a, b));
  print(zt(a));
  print(zt(b));
  print(zt(conv(a, b)));
  return 0;
}
