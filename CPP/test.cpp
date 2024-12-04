#include <iostream>
#include <thread>

void print_hello() { std::cout << "Hello from thread!" << std::endl; }

void print_world() { std::cout << "World from thread!" << std::endl; }

int main() {
    // Create two threads
    std::thread t1(print_hello);
    std::thread t2(print_world);

    t1.join();
    t2.join();

    std::cout << "Main thread finished!" << std::endl;

    return 0;
}
