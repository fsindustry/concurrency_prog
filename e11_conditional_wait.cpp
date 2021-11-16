//
// Created by fsindustry on 11/16/21.
//


#include <condition_variable>
#include <queue>
#include <iostream>
#include <thread>

std::mutex cond_mutex;
std::condition_variable condition;
std::queue<std::string> data_queue;

void produce(int size) {
    for (int i = 0; i < size; i++) {
        std::string data = "hello " + std::to_string(i);
        std::lock_guard<std::mutex> lk(cond_mutex);
        std::cout << "produce data: " << data << std::endl;
        data_queue.push(data);
        condition.notify_one();
    }
}

void consume(int size) {
    for (int i = 0; i < size; i++) {
        std::unique_lock<std::mutex> lk(cond_mutex);
        // when waiting, the lock will be released;
        // after wakeup, the lock will be getted again;
        condition.wait(lk, [] { return !data_queue.empty(); });
        std::cout << "consume data: " << data_queue.front() << std::endl;
        data_queue.pop();
        lk.unlock();
    }
}

int main() {
    std::thread p(produce, 10);
    std::thread c(consume, 10);
    p.join();
    c.join();
}