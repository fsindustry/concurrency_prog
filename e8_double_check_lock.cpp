//
// Created by fsindustry on 2021/10/28.
//

#include <mutex>
#include <iostream>

class singleton{
private:
    static std::mutex mutex;
    static singleton* instance;
    singleton(){}
public:
    // 二次检查锁定
    static singleton* get_instance(){
        if(nullptr == instance)
        {
            std::lock_guard<std::mutex> lk(mutex);
            if(nullptr == instance){
                instance = new singleton;
            }
        }
        return instance;
    }
    void do_something(){
        std::cout<<"do something"<<std::endl;
    }
};
singleton* singleton::instance = nullptr;
std::mutex singleton::mutex;
int main(){
    singleton* s =  singleton::get_instance();
    s->do_something();
}