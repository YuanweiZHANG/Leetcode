#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

/**
* 2020-04-24
* Veronica
*/
struct LRUList {
	int key;
	int value;
	LRUList* next;
	LRUList* prev;
};

class LRUCache {
private:
	LRUList* head;
	int cap;
	unordered_map<int, LRUList*> mp;

public:
	LRUCache(int capacity) {
		cap = capacity;
		head = NULL;
	}

	int get(int key) {
		if (mp.find(key) == mp.end())
			return -1;
		LRUList* find = mp[key];
		if (find == head) // already in the head
			return find->value;
		find->next->prev = find->prev;
		find->prev->next = find->next;
		find->prev = head->prev;
		find->prev->next = find;
		find->next = head;
		find->next->prev = find;
		head = find;
		return find->value;
	}

	void put(int key, int value) {
		if (get(key) != -1) {
			mp[key]->value = value;
			return;
		}
		LRUList* insert;
		if (mp.size() == cap) {
			mp.erase(head->prev->key);
			insert = head->prev;
			head->prev = head->prev->prev;
			head->prev->next = head;
		}
		else {
			insert = new LRUList;
		}
		insert->key = key;
		insert->value = value;
		if (head) {
			insert->next = head;
			insert->prev = head->prev;
			insert->next->prev = insert;
			insert->prev->next = insert;
		}
		else {
			insert->next = insert;
			insert->prev = insert;
		}
		head = insert;
		mp[key] = insert;
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