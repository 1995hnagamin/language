#include "ff++.hpp"
#include "AFunction_ext.hpp"
#include "iostream"

class Greeting : public OneOperator {
public:
  class Op : public E_F0info {
  public:
    static int const n_name_param = 2;
    static basicAC_F0::name_and_type name_param[];
    Expression nargs[n_name_param];

    long argl(int i, Stack stack, long a) const {
      return nargs[i]
        ? GetAny<long>((*nargs[i])(stack))
        : a;
    }

    Op(basicAC_F0 const &args): precon(nullptr) {
      args.SetNameParam(n_name_param, name_param, nargs);

      if (nargs[1]) {
        Polymorphic *op = dynamic_cast<Polymorphic *>(nargs[1]);
        ffassert(op);
        OneOperator const *code = op->Find("(", ArrayOfaType(atype<long>(), false));
        precon = code;
      }
    }

    AnyType operator()(Stack stack) const {
      if (precon) {
        std::cout << "precon" << std::endl;
      }
      long repeat = argl(0, stack, 1);
      for (long i = 0; i < repeat; ++i) {
        std::cout << "Hello" << std::endl;
      }
      return 0L;
    }

  private:
    OneOperator const *precon;
  };

  Greeting(): OneOperator(atype<long>()) {
  }

  E_F0 *code(basicAC_F0 const &args) const {
    return new Op(args);
  }
};

basicAC_F0::name_and_type Greeting::Op::name_param[] = {
  { "repeat", &typeid(long) },
  { "precon", &typeid(Polymorphic *)},
};

static void init() {
  Global.Add( "aisatu", "(", new Greeting);
}
LOADFUNC(init);
