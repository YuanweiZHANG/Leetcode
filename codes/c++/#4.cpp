#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/**
* 2020-04-28
* Veronica
*/
class FirstUnique {
public:
	unordered_map<int, list<int>::iterator> mp;
	list<int> lst;
	unordered_set<int> set;
	FirstUnique(vector<int>& nums) {
		for (auto num : nums) {
			if (set.find(num) == set.end()) { // shows first time
				lst.push_back(num);
				mp[num] = --lst.end();
				set.insert(num);
			}
			else {
				if (mp.find(num) != mp.end()) {
					lst.erase(mp[num]);
					mp.erase(num);
				}
			}
		}
	}

	int showFirstUnique() {
		if (lst.empty())
			return -1;
		else
			return lst.front();
	}

	void add(int value) {
		if (set.find(value) == set.end()) {
			lst.push_back(value);
			mp[value] = --lst.end();
			set.insert(value);
		}
		else {
			if (mp.find(value) != mp.end()) {
				lst.erase(mp[value]);
				mp.erase(value);
			}
		}
	}
};

/**
* Your FirstUnique object will be instantiated and called as such:
* FirstUnique* obj = new FirstUnique(nums);
* int param_1 = obj->showFirstUnique();
* obj->add(value);
*/

int main() {
	vector<int> nums = { 7,7,7,7,7,7 };
	FirstUnique firstUnique(nums);

	cout << firstUnique.showFirstUnique() << endl;
	firstUnique.add(7);
	firstUnique.add(3);
	firstUnique.add(3);
	firstUnique.add(7);
	firstUnique.add(17);
	cout << firstUnique.showFirstUnique() << endl;

	return 0;
}