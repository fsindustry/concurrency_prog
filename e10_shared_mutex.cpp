//
// Created by fsindustry on 2021/10/28.
//

#include <mutex>
#include <iostream>
#include <map>

class read_cache {
private:
    std::map<std::string,std::string> cache;
    mutable boost::shared_mutex cache_mutex;
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