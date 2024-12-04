#include <iostream>
using namespace std;

class MyClass1 {
    int x;
    int y;

  public:
    void setValue(int x, int y);
    void display();
};
class MyClass2 {
    int x;
    int y;

  public:
    void setValue(int x, int y);
    void display();
};

inline void MyClass1::setValue(int x, int y) {
    this->x = x;
    this->y = y;
}
inline void MyClass1::display() {
    cout << x << " " << y << endl;
}
inline void MyClass2::setValue(int x, int y) {
    this->x = x;
    this->y = y;
}
inline void MyClass2::display() {
    cout << x << " " << y << endl;
}

int main() {
    MyClass1 obj1;
    MyClass2 obj2;

    obj1.setValue(10, 20);
    obj2.setValue(20, 30);

    obj1.display();
    obj2.display();
}