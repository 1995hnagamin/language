#include <bitset>
#include <cassert>
#include <iostream>
#include <random>

using board = std::bitset<64>;

board func1(board b, int target) {
  int sum = 0;
  for (int n = 0; n < 64; ++n) {
    if (b[n]) {
      sum = sum ^ n;
    }
  }
  const auto diff = sum ^ target;
  assert(diff < 64);
  b.flip(diff);
  return b;
}

int func2(board b) {
  int sum = 0;
  for (int n = 0; n < 64; ++n) {
    if (b[n]) {
      sum = sum ^ n;
    }
  }
  return sum;
}

bool check(board b, int target) {
  const auto b2 = func1(b, target);
  if ((b ^ b2).count() != 1) {
    return false;
  }
  const auto ans = func2(b2);
  return ans == target;
}

int main() {
  std::random_device rnd;
  std::mt19937 mt(rnd());
  std::uniform_int_distribution<> rand64(0, 63);
  std::mt19937_64 mt64(rnd());
  std::uniform_int_distribution<unsigned long long> randull;
  for (int i = 0; i < 100; ++i) {
    const auto b = board(randull(mt64));
    const auto target = rand64(mt);
    std::cout << b << ", " << target << std::endl;
    if (!check(b, target)) {
      std::cout << "NG" << std::endl;
    }
  }
  std::cout << "OK" << std::endl;
  return 0;
}
