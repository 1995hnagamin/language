template<typename T>
class Point3D {
public:
  Point3D();
  Point3D(T, T, T);
  T accumulate();
private:
  T x, y, z;
};

template<typename T>
Point3D<T>::Point3D():
  x(0), y(0), z(0)
{}

template<typename T>
Point3D<T>::Point3D(T p, T q, T r):
  x(p), y(q), z(r)
{}

template<typename T>
T Point3D<T>::accumulate() {
  return x + y + z;
}

template<>
Point3D<int>::Point3D() __attribute__((weak));

template<>
Point3D<int>::Point3D():
  x(0), y(0), z(0)
{}

template<>
Point3D<int>::Point3D(int p, int q, int r) __attribute__((weak));

template<>
Point3D<int>::Point3D(int p, int q, int r):
  x(p), y(q), z(r)
{}

template<>
int Point3D<int>::accumulate() __attribute__((weak));

template<>
int Point3D<int>::accumulate() {
  return x + y + z;
}


Point3D<int> origin();
