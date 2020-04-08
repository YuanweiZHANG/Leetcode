## 46. [Permutations](https://leetcode.com/problems/permutations/)

> Medium

Given a collection of **distinct** integers, return all possible permutations.

**Example:**

```
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```



**Solutions:**

Use stack to DFS. My code can handle duplicated `nums` even though `nums` is a collection of distinct integers :).

Here is my solution class:

```c++
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> results;
		int len = nums.size();
		if (len == 0)
			return results;
		
		vector<int> curr;
		vector<bool> visited(len, false);
		stack<Status> stk;
		
		for (int i = 0; i < len; ++i) {
			if (i < len - 1 && nums[i] == nums[i + 1] && !visited[i + 1])
				continue;
			curr.push_back(nums[i]);
			visited[i] = true;
			stk.push(Status(curr, visited));
			visited[i] = false;
			curr.pop_back();
		}
		
		while (!stk.empty()) {
			Status p = stk.top();
			stk.pop();
			if (p.curr.size() == len) {
				results.push_back(p.curr);
			}
			else {
				for (int i = 0; i < len; ++i) {
					if (!p.visited[i]) {
						if (i < len - 1 && nums[i] == nums[i + 1] && !p.visited[i + 1])
							continue;
						p.curr.push_back(nums[i]);
						p.visited[i] = true;
						stk.push(Status(p.curr, p.visited));
						p.visited[i] = false;
						p.curr.pop_back();
					}
				}
			}
		}
		return results;
	}
	
	struct Status {
		vector<int> curr;
		vector<bool> visited;
		Status(vector<int>& curr_, vector<bool>& visited_) :
			curr(curr_), visited(visited_) {}
	};
};
```

Use recursion to DFS. I found that if define function `permuteCore` as `permute`, LeetCode will throw `Internal Error`.

Here is my solution class:

```c++
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> results;
		int len = nums.size();
		if (len == 0)
			return results;
		vector<int> curr;
		vector<bool> visited(len, false);
		for (int i = 0; i < len; ++i) {
			if (i < len - 1 && nums[i] == nums[i + 1])
				continue;
			curr.push_back(nums[i]);
			visited[i] = true;
			permuteCore(nums, results, curr, visited);
			visited[i] = false;
			curr.pop_back();
		}
		return results;
	}
	void permuteCore(vector<int>& nums, vector<vector<int>>& results, vector<int>& curr, vector<bool>& visited) {
		int len = nums.size();
		if (curr.size() == len) {
			results.push_back(curr);
			return;
		}
		else {
			for (int i = 0; i < len; ++i) {
				if (!visited[i]) {
					if (i < len - 1 && nums[i] == nums[i + 1] && !visited[i + 1])
						continue;
					curr.push_back(nums[i]);
					visited[i] = true;
					permuteCore(nums, results, curr, visited);
					visited[i] = false;
					curr.pop_back();
				}
			}
		}
	}
};
```

