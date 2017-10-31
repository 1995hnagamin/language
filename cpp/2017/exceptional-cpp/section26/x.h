#ifndef X_H
#define X_H

#include <iosfwd>
#include <list>

#include "a.h"
#include "b.h"

class E;

struct XImpl;

class X : public A, private B
{
  public:
    X(const C &);
    B f(int, char *);
    C f(int, C);
    C &g(B);
    E h(E);
    virtual std::ostream &print(std::ostream &) const;
  private:
    struct XImpl *pimpl_;
};

inline std::ostream &operator<<(std::ostream &os, const X &x)
{
  return x.print(os);
}

#endif /* !X_H */
