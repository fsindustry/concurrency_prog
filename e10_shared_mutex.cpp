//
// Created by fsindustry on 2021/10/28.
//

#include <mutex>
#include <iostream>
#include <map>
#include <thread/shared_mutex.hpp>

class read_cache {
private:
    std::map<std::string,std::string> cache;
    mutable boost::shared_mutex cache_mutex;
public:
    std::string  get(std::string key){
      // add read lock
      boost::shared_lock<boost::shared_mutex> s_lock(cache_mutex);
      std::map<std::string,std::string>::const_iterator iter =  cache.find(key);
      return (iter == cache.end()) ? NULL: iter->second;
    }

    void set(std::string key, std::string value){
      // add write lock
      std::lock_guard<boost::shared_mutex> x_lock(cache_mutex);
      cache[key] = value;
    }
};

int main() {
  read_cache r;
  r.set("key1", "value1");
  std::cout<< r.get("key1")<<std::endl;
}