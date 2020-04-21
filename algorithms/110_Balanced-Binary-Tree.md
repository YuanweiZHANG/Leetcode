## 110. [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)

> Easy

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

> a binary tree in which the left and right subtrees of *every* node differ in height by no more than 1.

 

**Example 1:**

Given the following tree `[3,9,20,null,null,15,7]`:

```
    3
   / \
  9  20
    /  \
   15   7
```

Return true.
**Example 2:**

Given the following tree `[1,2,2,3,3,null,null,4,4]`:

```
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
```

Return false.



**Solutions:**

Recursion.

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
	bool isBalanced(TreeNode* root) {
		if (!root)
			return true;
		int h = height(root);
		if (h == -1)
			return false;
		else
			return true;
	}
	int height(TreeNode* root) {
		if (!root)
			return 0;
		int left = height(root->left);
		int right = height(root->right);
		if (left == -1 || right == -1)
			return -1;
		if (abs(left - right) > 1)
			return -1;
		return max(height(root->left), height(root->right)) + 1;
	}
};
```

