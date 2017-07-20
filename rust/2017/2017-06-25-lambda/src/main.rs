#![feature(unboxed_closures)]
#![feature(fn_traits)]

use std::ops::{FnOnce, FnMut, Fn};

struct Closure {
    x: isize,
}

impl FnOnce<(isize,)> for Closure {
    type Output = isize;
    extern "rust-call" fn call_once(self, (arg, ): (isize,)) -> Self::Output {
        self.x + arg
    }
}

impl FnMut<(isize,)> for Closure {
    extern "rust-call" fn call_mut(&mut self, (arg, ):(isize,)) -> Self::Output {
        self.x + arg
    }
}

impl Fn<(isize,)> for Closure {
    extern "rust-call" fn call(&self, (arg, ):(isize,)) -> Self::Output {
        self.x + arg
    }
}

fn main() {
    let x = 1;
    let cls = Closure { x: x };
    for i in 0..10 {
        // let cls = Closure {i: i};
        println!("{}", cls(i));
    }
}
