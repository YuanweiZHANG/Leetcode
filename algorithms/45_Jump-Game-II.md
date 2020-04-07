## 45. [Jump Game II](https://leetcode.com/problems/jump-game-ii/)

> Hard

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

**Example:**

```
Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Note:**

You can assume that you can always reach the last index.



**Solutions:**

Firstly, considering BFS. The BFS code is below:

```c++
class Solution {
public:
	int jump(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 0;
		queue<Position> que;
		que.push(Position(0,0));
		while (!que.empty()) {
			Position curr = que.front();
			if (curr.index == len - 1)
				return curr.steps;
			for (int i = nums[curr.index]; i > 0; --i) {
				int next_index = curr.index + i;
				if (next_index == len - 1)
					return curr.steps + 1;
				else if (next_index < len - 1) {
					que.push(Position(next_index, curr.steps + 1));
				}
				else
					break;
			}
			que.pop();
		}
		return -1;
	}
	
	struct Position {
		int index;
		int steps;
		Position(int index_, int steps_) :index(index_), steps(steps_) {};
	};
};
```

However, this cannot pass test 80 because of Time Limit Exceeded. Then consider another method.

Define `farthest` as the farthest location when step into `i - 1`th of `nums`. Then if `nums[i] + i > farthest` which means current `i` can jump out of the farthest location, write down the steps: `steps[j] = steps[i] + 1`.

Here is my solution class:

```c++
class Solution {
public:
	int jump(vector<int>& nums) {
		int len = nums.sizemp
		if (len == 0)
			return 0;
		vector<int> steps(len, 10000);
		steps[0] = 0;
		int farthest = 0;
		for (int i = 0; i < len; ++i) {
			if (nums[i] + i > farthest) {
				int j = 0;
				for (j = farthest + 1; j < len && j <= nums[i] + i; ++j) {
					steps[j] = steps[i] + 1;
					farthest = j;
				}
			}
		}
		return steps[len - 1];
	}
};
```
