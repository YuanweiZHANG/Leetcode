## 75. [Sort Colors](https://leetcode.com/problems/sort-colors/)

> Medium

Given an array with *n* objects colored red, white or blue, sort them **in-place** so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

**Note:** You are not suppose to use the library's sort function for this problem.

**Example:**

```
Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

**Follow up:**

- A rather straight forward solution is a two-pass algorithm using counting sort.
  First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
- Could you come up with a one-pass algorithm using only constant space?



**Solutions:**

`index0` is the first 1's index, and `index2` is the last 1's index. Let `i = 0` and keep `i <= index2`. If `nums[i] == 0`, firstly, change `nums[i]`'s color to `1`, Then change `nums[index0]`'s color into `0`. If `nums[i] == 2`, `nums[i] = 1`. If `nums[index2]`'s color is `0`, do processes described above. Then `nums[index2--] = 2`.

By doing so, we can pass one time to make every color `0` lie on the left, `1` on the right, and between `index0` and `index2` are all `1`'s.

Here is my solution class:

```c++
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int len = nums.size();
		int index0 = 0, index2 = len - 1;
		int i = 0;
		while (index2 >= 0 && nums[index2] == 2)
			index2--;
		while (i <= index2) {
			if (nums[i] == 0) {
				nums[i] = 1;
				nums[index0++] = 0;
			}
			else if (nums[i] == 2) {
				nums[i] = 1;
				if (nums[index2] == 0)
					nums[index0++] = 0;
				nums[index2--] = 2;
				while (index2 >= 0 && nums[index2] == 2)
					index2--;
			}
			i++;
		}
	}
};
```

Some others' solution class is much more concise than me. See below:

```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int index_zero = 0, index_one = 0, index_two = nums.size()-1;
        
        while(index_one <= index_two){
            if(nums[index_one] == 2){
                swap(nums[index_one], nums[index_two]);
                index_two--;
            }
            else if(nums[index_one] == 0){
                swap(nums[index_one], nums[index_zero]);
                index_zero++;
                index_one++;
            }
            else{
                index_one++;
            }
        }
        
    }
};
```

