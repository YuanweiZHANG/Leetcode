## 56. [Merge Intervals](https://leetcode.com/problems/merge-intervals/)

> Medium

Given a collection of intervals, merge all overlapping intervals.

**Example 1:**

```
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
```

**Example 2:**

```
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

**NOTE:** input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.



**Solutions:**

Sort `intervals` first. Then mark the `start` and `end` as the two sides of a new interval. Add `i` when `end >= intervals[i+1][1]`.

**`[](vector<int>& x, vector<int>& y) {return x[0] < y[0];}` is Lambda expression**.  

Here is my solution class:

```c++
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [](vector<int>& x, vector<int>& y) {return x[0] < y[0]; });
		int len = intervals.size();
		vector<vector<int>> results;
		int start = 0, end = 0;
		for (int i = 0; i < len; ++i) {
			start = intervals[i][0];
			end = intervals[i][1];
			while (i < len - 1 && end >= intervals[i + 1][0]) {
				end = max(end, intervals[i + 1][1]);
				i++;
			}
			results.push_back({ start, end });
		}
		return results;
	}
};
```

