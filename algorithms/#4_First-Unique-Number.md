##[First Unique Number](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/531/week-4/3313/)

> #

You have a queue of integers, you need to retrieve the first unique integer in the queue.

Implement the `FirstUnique` class:

- `FirstUnique(int[] nums)` Initializes the object with the numbers in the queue.
- `int showFirstUnique()` returns the value of **the first unique** integer of the queue, and returns **-1** if there is no such integer.
- `void add(int value)` insert value to the queue.

 

**Example 1:**

```
Input: 
["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
[[[2,3,5]],[],[5],[],[2],[],[3],[]]
Output: 
[null,2,null,2,null,3,null,-1]

Explanation: 
FirstUnique firstUnique = new FirstUnique([2,3,5]);
firstUnique.showFirstUnique(); // return 2
firstUnique.add(5);            // the queue is now [2,3,5,5]
firstUnique.showFirstUnique(); // return 2
firstUnique.add(2);            // the queue is now [2,3,5,5,2]
firstUnique.showFirstUnique(); // return 3
firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
firstUnique.showFirstUnique(); // return -1
```

**Example 2:**

```
Input: 
["FirstUnique","showFirstUnique","add","add","add","add","add","showFirstUnique"]
[[[7,7,7,7,7,7]],[],[7],[3],[3],[7],[17],[]]
Output: 
[null,-1,null,null,null,null,null,17]

Explanation: 
FirstUnique firstUnique = new FirstUnique([7,7,7,7,7,7]);
firstUnique.showFirstUnique(); // return -1
firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7]
firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3]
firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3,3]
firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7,3,3,7]
firstUnique.add(17);           // the queue is now [7,7,7,7,7,7,7,3,3,7,17]
firstUnique.showFirstUnique(); // return 17
```

**Example 3:**

```
Input: 
["FirstUnique","showFirstUnique","add","showFirstUnique"]
[[[809]],[],[809],[]]
Output: 
[null,809,null,-1]

Explanation: 
FirstUnique firstUnique = new FirstUnique([809]);
firstUnique.showFirstUnique(); // return 809
firstUnique.add(809);          // the queue is now [809,809]
firstUnique.showFirstUnique(); // return -1
```

 

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^8`
- `1 <= value <= 10^8`
- At most `50000` calls will be made to `showFirstUnique` and `add`.



**Solutions:**

Use `list` to store the unique number, `unordered_map` to store every unique number's iterator in `list`, and `set` to store every number exists in the `nums`. When `num` is unique, push it into `list`, `unordered_map` and `set`, or erase it from `list` and `unordered_map`.

Here is my solution class:

```c++
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
```

There is also another solution: 

Use `queue` to store all unique numbers, and `count` to store every number exists times. `num` is unique if and only if `count[num] == 1`.

```c++
class FirstUnique {
public:
	queue<int> que;
	unordered_map<int/*num*/, int/*counts*/> count;
	FirstUnique(vector<int>& nums) {
		for (auto num : nums) {
			que.push(num);
			count[num]++;
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
		que.push(value);
		count[value]++;
	}
};
```

