void f() try {
  throw 1;
} catch (int e) {
  throw 2;
}

void g() {
  try {
    throw 1;
  } catch (int e) {
    throw 2;
  }
}
