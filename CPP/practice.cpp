#include <iostream>
using namespace std;

void print(const char* string){
    cout << string ;
}
void println(const char* string){
    cout<< string << endl;
}
int main()
{
    println("hello world with newline");
    print("hello world");
    return 0;
}

