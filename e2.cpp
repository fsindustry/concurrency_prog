//
// Created by fsindustry on 2021/10/14.
//
#include <iostream>
#include <thread>

class backgroup_task {
public:
    void operator()() const {
        std::cout << "Hello Concurrent World" << std::endl;
    }
};

int main() {
    backgroup_task t;
    std::thread my_thread(t);
    my_thread.join();
}
