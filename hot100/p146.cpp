#include <list>
#include <unordered_map>
using namespace std;
class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cacheList;  // 按使用时间排序，front=最新，back=最旧
    unordered_map<int, list<pair<int, int>>::iterator> map;  // key -> list 中的位置
    
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        auto it = map.find(key);
        // 如果不存在
        if(it == map.end()){
            return -1;
        }
        // 如果存在，更新list顺序
        cacheList.splice(cacheList.begin(), cacheList, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        // 如果存在，更新
        if(it != map.end()){
            it->second->second = value;
            cacheList.splice(cacheList.begin(), cacheList, it->second);
            return;
        }
        // 如果满，弹出最久不使用
        if(cacheList.size() == capacity){
            auto last = cacheList.back();
            map.erase(last.first);
            cacheList.pop_back();
        }
        // 插入新节点
        cacheList.push_front({key, value});
        map[key] = cacheList.begin();
        return;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */