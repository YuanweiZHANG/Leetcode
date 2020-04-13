## 84. [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)

> Hard

Given *n* non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

 

![img](./imgs/84.png)
Above is a histogram where width of each bar is 1, given height = `[2,1,5,6,2,3]`.

 

![img](./imgs/84-2.png)
The largest rectangle is shown in the shaded area, which has area = `10` unit.

 

**Example:**

```
Input: [2,1,5,6,2,3]
Output: 10
```



**Solutions:**

The first solution I figured out is divide and conquer algorithm.

Firstly, fine the `lowest` index between `left` and `right`, then calculate the max area in `[left, lowest - 1]` and `[lowest + 1, right]`.

Here is my solution class:

```c++
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		return largetRectangleAreaCore(heights, 0, heights.size() - 1);
	}
	int largetRectangleAreaCore(vector<int>& heights, int left, int right) {
		if (left == right)
			return heights[left];
		else if (left > right) {
			return 0;
		}
		int lowest = left;
		for (int i = left + 1; i <= right; ++i) {
			if (heights[i] < heights[lowest]) {
				lowest = i;
			}
		}
		int area = heights[lowest] * (right - left + 1);
		return max(max(area, largetRectangleAreaCore(heights, left, lowest - 1)), largetRectangleAreaCore(heights, lowest + 1, right));
	}
};
```

However, divide and conquer algorithm cannot pass the problem due to `Time Limited Exceeded`.

Well, let's explain a common solution from the Internet.

The area of a rectangle is $S = l * s$. We cannot easily judge which one's area is larger when $l_1<l_2$ and $s_1>s_2$. Therefore, we need to calculate them all. If the interval `[left, right]` is ascending sequence, the largest area of a rectangle is `height[left] * (right - left + 1)`. Only when `heights[i] > heights[i+1]`, we need to calculate which one is larger. 

According to this principle, the solution below calculate every rectangle's area whos right side is `i - 1` and left side is higher than `heights[i]`. 

```c++
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		heights.push_back(0);
		int len = heights.size();
		int largestArea = 0;
		stack<int> lefts;
		for (int i = 0; i < len; ++i) {
			while (!lefts.empty() && heights[lefts.top()] > heights[i]) {
				int h = heights[lefts.top()];
				lefts.pop();
				int left = lefts.empty() ? -1 : lefts.top();
				largestArea = max(largestArea, h * (i - left - 1));
			}
			lefts.push(i);
		}
		return largestArea;
	}
};
```

