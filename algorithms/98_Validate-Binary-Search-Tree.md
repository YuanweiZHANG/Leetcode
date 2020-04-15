##98. [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/) 

> Medium

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

- The left subtree of a node contains only nodes with keys **less than** the node's key.
- The right subtree of a node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.

 

**Example 1:**

```
    2
   / \
  1   3

Input: [2,1,3]
Output: true
```

**Example 2:**

```
    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
```



**Solutions:**

Recursion:

If `root->left` is a BST and `root->right` is a BST, as well as `root->left->biggest` < `root->val` and `root->right->smallest` > `root->val`, `root` is a BST.

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
	bool isValidBST(TreeNode* root) {
		return isVaildBSTCore(root)[0];
	}
	vector<int> isVaildBSTCore(TreeNode * root) {
		if (!root)
			return { true, 0, 0 };
		int smallest = root->val;
		int biggest = root->val;
		if (root->left) {
			vector<int> result = isVaildBSTCore(root->left);
			if (!result[0] || result[2] >= root->val)
				return { false, smallest, biggest };
			smallest = result[1];
		}
		if (root->right) {
			vector<int> result = isVaildBSTCore(root->right);
			if (!result[0] || result[1] <= root->val)
				return { false, smallest, biggest };
			biggest = result[2];
		}
		return { true, smallest, biggest };
	}
};
```

Also, we can get preorder traversal of `root` and this array is ascending sequence if and only if `root` is BST.

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
	bool isValidBST(TreeNode* root) {
		if (!root)
			return true;
		stack<pair<TreeNode*, int/*processTimes*/>> stk;
		stk.push(make_pair(root, 0));
		vector<int> nums;
		while (!stk.empty()) {
			TreeNode* curr = stk.top().first;
			int processTimes = stk.top().second;
			if (processTimes == 0) { // first time in the stack
				stk.pop();
				stk.push(make_pair(curr, 1));
				if (curr->left)
					stk.push(make_pair(curr->left, 0));
			}
			else {
				stk.pop();
				nums.push_back(curr->val);
				if (curr->right)
					stk.push(make_pair(curr->right, 0));
			}
		}
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i - 1] >= nums[i])
				return false;
		}
		return true;
	}
};
```

