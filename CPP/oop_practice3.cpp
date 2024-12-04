#include <iostream>
using namespace std;
class magic;
class fun {
    float x;

  public:
    fun(float val) {
        x = val;
    }
    friend void compare(fun f, magic m);
};

class magic {
    float y;

  public:
    magic(float val) {
        y = val;
    }
    friend void compare(fun f, magic m);
};
void compare(fun f, magic m) {
    if (f.x > m.y) {
        cout << "f is greater than m" << endl;
    } else {
        cout << "m is greater than f" << endl;
    }
}

int main() {
    fun f(20.35);
    magic m(30.20);

    compare(f, m);

    return 0;
}