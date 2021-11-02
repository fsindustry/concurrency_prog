#include <iostream>
#include <thread>

// c++ thread uses function as a task.
void hello() {
    std::cout << "Hello Concurrent World" << std::endl;
}

int main() {
    // create a new thread and run hello().
    std::thread t(hello);
    // let main thread wait for thread t finished.
    t.join();
}