#include <iostream>
using namespace std;

int main()
{
    char *p = new char[100];

    char *t = p;

    *p = 'a';
    p++;
    *p = 'b';
    p++;
    *p = '\0';
    while (*t != '\0')
    {
        cout << *t;
        t++;
    }

    delete[] p;
    return 0;
}
