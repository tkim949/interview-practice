#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>

using namespace std;

class LRUCache {

private:
    list<int> _lst;
    unordered_map<int, pair<int, list<int>::iterator>> _mp;
    int _capacity;

public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) {

        if(_mp.find(key) == _mp.end()) return -1;
        //if found the key
        _lst.erase(_mp[key].second);
        _lst.push_front(key);
        _mp[key].second = _lst.begin(); //update the order/address

        return _mp[key].first; //return value

    }

    void put(int key, int val) {

        if(_mp.find(key) != _mp.end()) {
            _lst.erase(_mp[key].second);
        } else{
            if(_lst.size() == _capacity) {
                int last = _lst.back();
                _lst.pop_back();
                _mp.erase(last); //how this is possible? because erase can take either key or iterator!!!
            }
        }
        _lst.push_front(key); //add into front
        _mp[key] = {val, _lst.begin()}; //update

    }

};


int main() {
    std::cout << "Least Recently Used Cache" << std::endl;

    LRUCache *cache = new LRUCache(2);
    cache->put(1, 1);
    cache->put(2, 2);
    cout<<"1. get 1: " <<cache->get(1)<<endl;
    cache->put(3, 3);
    cout<<"2. get 2: "<<cache->get(2)<<endl;
    cache->put(4, 4);
    cout<<"3. get 1: " <<cache->get(1)<<endl;
    cout<<"4. get 3: "<<cache->get(3)<<endl;
    cout<<"5. get 4: "<<cache->get(4)<<endl;


    return 0;
}