struct hoge {int x; int y;};
struct hoge f() { struct hoge v = {1, 2}; return v; }
int g() { return f().x; }
