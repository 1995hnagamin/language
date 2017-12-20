class Complex
{
public:
  explicit Complex(double real, double imaginary = 0)
    : real_(real), imaginary_(imaginary)
  {
  }
  Complex &operator+=(const Complex &other)
  {
    real_ = other.real_;
    imaginary_ = other.imaginary_;
    return *this;
  }
  Complex operator++()
  {
    ++_real;
    return *this;
  }
  Complex operator++(int)
  {
    Complex temp(*this);
    ++(*this);
    return temp;
  }
  ostream &Print(ostream &os) const
  {
    return os << "(" << real_ << ", " << imaginary_ << ")";
  }
private:
  double real_;
  double imaginary_;
};

const Complex operator+(const Complex &lhs, const Complex &rhs)
{
  Complex ret(lhs);
  ret += rhs;
  return ret;
}

ostream &operator<<(ostream &os, const Complex &c)
{
  return c.Print(os);
}

/*
 * [o] メンバー名がアンダースコアから始まっている
 * [o] `operator+` が引数を値渡ししている
 * [o] `operator+` の返り値型がvoid
 * [o] `operator<<` が引数のストリームを値渡ししている
 * [o] `operator<<` の返り値型がvoid
 * [o] インクリメント演算子が参照ではなく値を返している
 *     `double`からの暗黙の型変換が存在する
 *     @=ではなく@を使っている
 *     `operator+`がメンバー関数
 *     `operator+`がインスタンスの状態を変更している
 *     `operator+`があるのに`operator+=`がない
 *     `operator<<`がメンバー関数
 *     後置インクリメントが非const値を返している
 *     後置インクリメントが前置インクリメントを使わずに定義されている
 */
