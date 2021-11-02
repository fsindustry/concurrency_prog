//
// Created by fsindustry on 2021/10/28.
//

#include <mutex>
#include <iostream>

class singleton {
private:
    static std::once_flag flag;
    static singleton *instance;
    singleton() {}
public:
    // 二次检查锁定
    static singleton *get_instance() {
        std::call_once(flag, [] { instance = new singleton; });
        return instance;
    }
    void do_something() {
        std::cout << "do something" << std::endl;
    }
};
singleton *singleton::instance = nullptr;
std::once_flag singleton::flag;
int main() {
    singleton *s = singleton::get_instance();
    s->do_something();
}