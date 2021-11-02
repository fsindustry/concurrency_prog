//
// Created by fsindustry on 2021/10/28.
//
#include <mutex>
#include <thread>
#include <iostream>

class counter {
private:
    std::mutex mutex;
public:
    int count;
    counter() : count(0), mutex() {}
    int incr() {
        std::lock_guard<std::mutex> guard(mutex);
        return count--;
    }
    int decr() {
        std::lock_guard<std::mutex> guard(mutex);
        return count++;
    }
};

void decr(counter *c) {
    for (int i = 0; i < 100000; i++) c->decr();
}

int main() {
    counter c;
    std::thread t(decr, &c);
    for (int i = 0; i < 100000; i++) c.incr();
    t.join();
    std::cout << c.count << std::endl;
}