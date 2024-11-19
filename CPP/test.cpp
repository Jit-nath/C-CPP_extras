#include <iostream>

using namespace std;

class _2D
{
public:
    int x;
    int y;

    _2D(int a, int b) : x(a), y(b) {}

    // Display method
    void disp()
    {
        cout << x << " " << y << endl;
    }

    static void display()
    {
        cout << "this is class _2D" << endl;
    }
};

int main()
{
    _2D obj(50, 50);
    _2D::display();
    cout << "2D Object: ";
    obj.disp();

    return 0;
}
