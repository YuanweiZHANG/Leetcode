#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/**
* 2020-04-28
* Veronica
*/
class FirstUnique {
public:
	queue<int> que;
	unordered_map<int/*num*/, int/*counts*/> count;
	FirstUnique(vector<int>& nums) {
		for (auto num : nums) {
			if (++count[num] == 1)
				que.push(num);
		}
	}

	int showFirstUnique() {
		while (!que.empty() && count[que.front()] > 1) // not unique
			que.pop();
		if (que.empty())
			return -1;
		else
			return que.front();
	}

	void add(int value) {
		if (++count[value] == 1)
			que.push(value);
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