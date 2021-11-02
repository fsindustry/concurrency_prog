//
// Created by fsindustry on 2021/10/14.
//
#include <iostream>
#include <thread>
#include <unistd.h>

class backgroup_task {
public:
    void operator()() const {
        std::cout << "Hello Concurrent World" << std::endl;
        sleep(2);
    }
};

int main() {
    backgroup_task t;
    std::thread t1(t);
    std::thread t2 = std::move(t1);
    t2.join();
    std::cout << "thread t2 finished." << std::endl;
}
