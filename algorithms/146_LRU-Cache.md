## 146. [LRU Cache](https://leetcode.com/problems/lru-cache/)

> Medium

Design and implement a data structure for [Least Recently Used (LRU) cache](https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU). It should support the following operations: `get` and `put`.

`get(key)` - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
`put(key, value)` - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a **positive** capacity.

**Follow up:**
Could you do both operations in **O(1)** time complexity?

**Example:**

```
LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
```



**Solutions:**

List `lst` stores all validated `key`. When get a `key`, remove it from the `lst` and push it in the front of the `lst`. Map `mp` stores the `key, value`.

Here is my solution class:

```c++
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
```

We can also implement `mp` as storing the pointer to the list's element, which can faster because of avoiding searching in the list:

```c++
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
```

Also, we can implement double linked list by ourselves:

```c++
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
```

