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
template<int size>
struct sieve {
  sieve(): factor(), primes() {
    factor[0] = factor[1] = 1;
    for (long long int p = 2; p < size; ++p) {
      if (factor[p]) { continue; }
      primes.push_back(p);
      for (long long n = p*(long long)p; n < size; n += p) {
        factor[n] = p;
      }
    }
  }
  long long int limit() const {
    const auto p = static_cast<long long int>(primes.back());
    return p * p;
  }
  long long int divisor(long long int n) const {
    assert(1 < n && n <= limit());
    if (n < size) { return factor[n]? factor[n]:n; }
    for (auto &&p : primes) {
      if (n % p == 0) { return p; }
    }
    return n;
  }
  bool is_prime(long long int n) const {
    assert(1 < n && n <= limit());
    return divisor(n) == n;
  }
  std::vector<long long int> prime_factors(long long int n) const {
    assert(0 < n && n <= limit());
    std::vector<long long int> ans;
    while (n > 1) {
      const auto p = divisor(n);
      ans.push_back(p);
      while (n % p == 0) { n /= p; }
    }
    return ans;
  }
  long long int factor[size];
  std::vector<long long int> primes;
};

using namespace std;

int main() {
  // cout << fixed << setprecision(10);

  using Sieve = sieve<1'000'000'00>;
  std::unique_ptr<Sieve> p = std::make_unique<Sieve>();
  long long int center = 1'000'000'000'000'000;
  long long int delta = 200;
  for (long long int n = center - delta; n < center + delta; ++n) {
    if (p->is_prime(n)) {
      cout << n << endl;
    }
  }
  return 0;
}
