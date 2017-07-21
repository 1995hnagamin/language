template < typename T >
struct X
{
  void f() ;
  void g() ;

} ;


int main()
{
  typedef X< int > type ; //  X<int>の実体化は必要ない
  type a ; // X<int>の実体化が必要
  X< char > * b ; // X<char>の実体化は必要ない
  X< double > * p ; // X<double>の実体化は必要ない

  a.f() ; // X<int>::f()の実体化が必要
  b->f() ; // X<char>::f()の実体化が必要

}
