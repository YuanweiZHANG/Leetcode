## 108. [Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)

> Easy

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of *every* node never differ by more than 1.

**Example:**

```
Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
```



**Solutions:**

Since input array is already sorted, we don't need to implement a balanced binary search tree's operations, like insert, delete, rotate, and so on. The only thing we need to do is find the middle of array, and let it be the root, then recursion.

Here is my solution class:

```c++
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode * sortedArrayToBST(vector<int>& nums) {
		return sortedArrayToBSTCore(nums, 0, nums.size() - 1);
	}
	TreeNode *sortedArrayToBSTCore(vector<int>& nums, int left, int right) {
		if (left > right)
			return NULL;
		int mid = (left + right) >> 1;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = sortedArrayToBSTCore(nums, left, mid - 1);
		root->right = sortedArrayToBSTCore(nums, mid + 1, right);
		return root;
	}
};
```

