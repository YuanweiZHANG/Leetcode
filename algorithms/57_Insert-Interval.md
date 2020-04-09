## 57. [Insert Interval](https://leetcode.com/problems/insert-interval/)

> Hard

Given a set of *non-overlapping* intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

**Example 1:**

```
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
```

**Example 2:**

```
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
```

**NOTE:** input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.



**Solutions:**

Use binary search to find the first `intervals[index][0] <= newInterval[0]`. If `newInterval[0]` is the smallest, `index = -1`. Then move `intervals[0]` to `intervals[index - 1]` to `results`. Merge `intervals[index]` and `newInterval`; merge `newInterval` and `intervals[index+1]` to `intervals[len - 1]`.

*Special input:*

```
Input: intervals = [], newInterval = [5,7]
Output: [[5,7]]
Cautious: when intervals is empty, return {newInterval}.
```

```
Input: intervals = [[1,5]], newInterval = [0,0]
Output: [[0,0],[1,5]]
Explanation: when newInterval[0] is the smallest, merge newInterval with all intervals.
```

Here is my solution class:

```c++
class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		int len = intervals.size();
		if (len == 0)
			return { newInterval };
		int index = binarySearch(intervals, newInterval[0]);
		vector<vector<int>> results;
		for (int i = 0; i < index; ++i) {
			results.push_back(intervals[i]);
		}
		if (index == -1) { // newInterval[0] is the smallest
			index = 0;
		}
		else {
			if (intervals[index][1] >= newInterval[0]) {
				newInterval[0] = min(intervals[index][0], newInterval[0]);
				newInterval[1] = max(intervals[index][1], newInterval[1]);
				index++;
			}
			else {
				results.push_back(intervals[index++]);
			}
		}
		while (index < len && newInterval[1] >= intervals[index][0]) {
			newInterval[1] = max(newInterval[1], intervals[index++][1]);
		}
		results.push_back(newInterval);
		for (int i = index; i < len; ++i) {
			results.push_back(intervals[i]);
		}
		return results;
	}
	int binarySearch(vector<vector<int>>& intervals, int key) {
		int left = 0, right = intervals.size() - 1;
		while (left <= right) {
			int mid = (left + right) >> 1;
			if (intervals[mid][0] == key)
				return mid;
			else if (intervals[mid][0] > key) {
				right = mid - 1;
			}
			else {
				if (mid == intervals.size() - 1)
					return mid;
				if (intervals[mid + 1][0] > key)
					return mid;
				else {
					left = mid + 1;
				}
			}
		}
		return -1;
	}
};
```

