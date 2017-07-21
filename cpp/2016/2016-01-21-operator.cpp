class Complex {
  private:
    double re, im;
  public:
    Complex(double real, double imag);
    double real();
    double imag();
    Complex operator*(Complex oth);
};

Complex operator+(Complex v, Complex w) {
  return Complex(v.real() + w.real(), v.imag() + v.imag());
}
