class Complex
{
public:
  Complex(double real, double imaginary = 0)
    : _real(real), _imaginary(imaginary)
  {
  }
  void operator+(Complex other)
  {
    _real = _real + other.real;
    _imaginary = _imaginary + other._imaginary
  }
  void operator<<(ostream os)
  {
    os << "(" << _real << "," << _imaginary << ")";
  }
  Complex operator++()
  {
    ++_real;
    return *this;
  }
  Complex operator++(int)
  {
    Complex temp = *this;
    ++_real;
    return temp;
  }
private:
  double _real, _imaginary;
};

/*
 * [ ] メンバー名がアンダースコアから始まっている
 * [ ] `operator+` が引数を値渡ししている
 * [ ] `operator+` の返り値型がvoid
 * [ ] `operator<<` が引数のストリームを値渡ししている
 * [ ] `operator<<` の返り値型がvoid
 * [ ] インクリメント演算子が参照ではなく値を返している
 */
