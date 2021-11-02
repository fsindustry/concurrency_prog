//
// Created by fsindustry on 2021/10/15.
//

#include <thread>
#include <iostream>
#include <unistd.h>

class thread_guard {
    std::thread t;
public:
    explicit thread_guard(std::thread t_) : t(std::move(t_)) {}

    virtual ~thread_guard() {
        // wait for t before destory
        if (t.joinable()) {
            t.join();
            std::cout << "thread t finished." << std::endl;
        }
    }

    // do not allowed copiable constructor
    thread_guard(thread_guard const &) = delete;
    thread_guard& operator=(thread_guard const&)=delete;
};

class backgroup_task {
public:
    void operator()() const {
        std::cout << "Hello Concurrent World." << std::endl;
        sleep(1);
    }
};

int main(){
    thread_guard guard((std::thread(backgroup_task())));
}