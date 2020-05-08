##1232. [Check If It Is a Straight Line](https://leetcode.com/problems/check-if-it-is-a-straight-line/) 

> Easy

You are given an array `coordinates`, `coordinates[i] = [x, y]`, where `[x, y]` represents the coordinate of a point. Check if these points make a straight line in the XY plane.

 

 

**Example 1:**

![img](./imgs/1232.jpg)

```
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
```

**Example 2:**

**![img](./imgs/1232-2.jpg)**

```
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
```

 

**Constraints:**

- `2 <= coordinates.length <= 1000`
- `coordinates[i].length == 2`
- `-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4`
- `coordinates` contains no duplicate point.



**Solutions:**

Calculate the slope and judge whether they are all the same.

`abs(d1 - d2) < 1e-5` equals to `d1 == d2`, where `d1` and `d2` are `double`.

Here is my solution class:

```c++
class Solution {
public:
	bool checkStraightLine(vector<vector<int>>& coordinates) {
		double k = (double)(coordinates[1][1] - coordinates[0][1]) / (double)(coordinates[1][0] - coordinates[0][0]);
		int n = coordinates.size();
		for (int i = 1; i < n - 1; ++i) {
			double newK = (double)(coordinates[i + 1][1] - coordinates[i][1]) / (double)(coordinates[i + 1][0] - coordinates[i][0]);
			if (abs(newK - k) > 1e-5)
				return false;
		}
		return true;
	}
};
```

