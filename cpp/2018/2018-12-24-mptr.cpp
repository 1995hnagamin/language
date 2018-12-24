// http://eel.is/c++draft/dcl.mptr
// https://twitter.com/non_archimedean/status/1077094877530214400

struct X {
  int f(int);
  int g(int) const;
  int a;
};

using F = int(int);
using Fc = int(int) const;

int main() {
  int X:: *pmi = &X::a;
  int (X:: *pmf)(int) = &X::f;
  int (X:: *pmg)(int) const = &X::g;
  /* [dcl.mptr]/1
   * T: ?
   */
  Fc X:: *pmg2 = &X::g;
  /* [dcl.mptr]/1
   * T: "Fc"
   * D: "X:: * D1"
   * D1: "pmg2"
   * T D1: "Fc pmg2" ~= "int pmg2(int) const"
   */

  Fc X:: *a[3] = { &X::g, &X::g, &X::g };
  int (X:: *a2[3])(int) const = { &X::g, &X::g, &X::g };
}
