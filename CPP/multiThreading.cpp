#include <iostream>
#include <thread>

void printToTen() {
    int i = 0;
    while (i < 10) {
        std::cout << i << std::endl;
        i++;
    }
}

int main() {
    // Create two threads
    std::thread t1(printToTen);
    std::thread t2(printToTen);
    t1.join();
    t2.join();
    return 0;
}
