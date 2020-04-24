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
	list<pair<int, int>> lst;
	int cap;
	unordered_map<int, list<pair<int, int>>::iterator> mp;
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		if (mp.find(key) == mp.end())
			return -1;
		auto it = mp[key];
		int value = it->second;
		lst.erase(it);
		lst.push_front(make_pair(key, value));
		mp[key] = lst.begin();
		return value;
	}

	void put(int key, int value) {
		if (get(key) != -1) {
			lst.front().second = value;
			mp[key] = lst.begin();
			return;
		}
		if (lst.size() == cap) {
			mp.erase(lst.rbegin()->first);
			lst.pop_back();
		}
		lst.push_front(make_pair(key, value));
		mp[key] = lst.begin();
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