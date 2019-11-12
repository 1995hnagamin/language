template <typename T>
class Room {
  public:
  Room(T x): body(x) {}
  T body;
};

int main() {
  Room r(100);
  return 0;
}
