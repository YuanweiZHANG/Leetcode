## 42. [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)

> Hard

Given *n* non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

![img](./imgs/42.png)
The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. **Thanks Marcos** for contributing this image!

**Example:**

```
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
```



**Solutions:**

Scanning `height` from both side.

From left to right: `i` is the left wall. Find `j` that first meet the condition `height[j] >= height[i]`. Then, calculate water volumn between `i` and `j`.

From right to left: `i` is the right wall. Find `j` that first meet the condition `height[j] > height[i]`. Then, calculate water volumn between `j` and `i`.

This kind of solution can cover all water based on the left wall `i` and the right wall `i`.

Here is my solution class:

```c++
class Solution {
public:
	int trap(vector<int>& height) {
		int len = height.size();
		if (len == 0)
			return 0;
		int i = 0;
		int water = 0;
		while (i < len - 1) {
			int j = i + 1;
			while (j < len && height[i] > height[j])
				j++;
			if (j != len) {
				water += height[i] * (j - i - 1);
				for (int k = i + 1; k < j; ++k)
					water -= height[k];
				i = j;
			}
			else // height[i] is the highest among height[i]...height[len-1]
				break;
		}
		i = len - 1;
		while (i > 1) {
			int j = i - 1;
			while (j >= 0 && height[i] >= height[j])
				j--;
			if (j != -1) {
				water += height[i] * (i - j - 1);
				for (int k = j + 1; k < i; ++k)
					water -= height[k];
				i = j;
			}
			else
				break;
		}
		return water;
	}
};
```

However, there is also a solution can solve this problem very well.

Store maximum height from 0 to `i` into `left[i]`; store maximum height from `i` to `n - 1` into `right[i]`. Then calculate water volumn on `height[i]`.

```c++
class Solution {
public:
    int trap(vector<int>& a){
    int i,area=0,n=a.size();
    if(!n) return 0;
    vector<int>left(n,0);         // left-max
    vector<int>right(n,0);       // right-max

    left[0]=a[0];
    for(i=1;i<n;i++)
        left[i] = max(a[i], left[i-1]);
    
    right[n-1] = a[n-1];
    for(i=n-2;i>=0;i--)
        right[i] = max(a[i], right[i+1]);
    
    for(i=0;i<n;i++)
        area += min(left[i], right[i]) - a[i];
    
    return area;
    }
};
```

**Comparison:**

My solution's time complexity is $O(n)$, space complexity is $O(1)$. This solution's time complexity is $O(n)$, space complexity is $O(n)$, which means **mine is better** in space complexity.