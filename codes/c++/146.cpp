#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

/**
* 2020-04-24
* Veronica
*/
class LRUCache {
public:
	list<int> lst;
	int cap;
	unordered_map<int, int> mp;
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		if (mp.find(key) == mp.end())
			return -1;
		lst.remove(key);
		lst.push_front(key);
		return mp[key];
	}

	void put(int key, int value) {
		if (get(key) != -1) {
			mp[key] = value;
			return;
		}
		if (lst.size() == cap) {
			mp.erase(lst.back());
			lst.pop_back();
		}
		lst.push_front(key);
		mp[key] = value;
	}
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/

int main() {
	int capacity = 2;
	LRUCache cache = LRUCache(capacity);

	cout << cache.get(2) << endl;
	cache.put(2, 6);
	cout << cache.get(1) << endl;
	cache.put(1, 5);
	cache.put(1, 2);
	cout << cache.get(1) << endl;
	cout << cache.get(2) << endl;
	
	return 0;
}