#ifndef X_H
#define X_H

#include <iostream>
#include <ostream>
#include <list>

#include "a.h"
#include "b.h"
#include "c.h"
#include "d.h"
#include "e.h"

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
    std::list<C> clist_;
    D d_;
};

inline std::ostream &operator<<(std::ostream &os, const X &x)
{
  return x.print(os);
}

#endif /* !X_H */
