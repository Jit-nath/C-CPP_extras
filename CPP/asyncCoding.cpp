#include <iostream>
#include <future>
#include <thread>

void printToTen() {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "Computationally heavy task running asynchronously..." << std::endl;
}

int main() {
    std::future<void> result = std::async(std::launch::async, printToTen);

    // Simulate other work in the main thread
    for (int i = 0; i < 5; i++) {
        std::cout << "Main thread working..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    result.get();
    return 0;
}
