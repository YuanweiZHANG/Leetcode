## 78. [Subsets](https://leetcode.com/problems/subsets/)

> Medium

Given a set of **distinct** integers, *nums*, return all possible subsets (the power set).

**Note:** The solution set must not contain duplicate subsets.

**Example:**

```
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
```



**Solutions:**

Similar as Problem No.77. However, push `curr` into `results` when get into a new recursion.

Here is my solution class:

```c++
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> results;
		vector<int> curr;
		subsetsCore(results, curr, nums, 0);
		return results;
	}
	void subsetsCore(vector<vector<int>>& results, vector<int>& curr, vector<int>& nums, int start) {
		results.push_back(curr);
		for (int i = start; i < nums.size(); ++i) {
			curr.push_back(nums[i]);
			subsetsCore(results, curr, nums, i + 1);
			curr.pop_back();
		}
	}
};
```

Also there is another solution.

```c++`
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        res.push_back(tmp);
        int len, j;
        for(int i = 0; i< nums.size(); i++){
            len = res.size();
            j = 0;
            while(j<len){
                tmp = res[j++];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        
        return res;
    }
};
```

