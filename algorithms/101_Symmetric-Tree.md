## 101. [Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)

> Easy

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree `[1,2,2,3,4,4,3]` is symmetric:

```
    1
   / \
  2   2
 / \ / \
3  4 4  3
```

 

But the following `[1,2,2,null,3,null,3]` is not:

```
    1
   / \
  2   2
   \   \
   3    3
```



**Solutions:**

When `curr->left->val == curr->right->val` and `curr-left->left` is symmetric to `curr->right->right`  and `curr->left->right` is symmetric to `curr->right->left`, `curr` is a mirror of itself.

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
	bool isSymmetric(TreeNode* root) {
		if (!root)
			return true;
		return isSymmetricCore(root->left, root->right);
	}
	bool isSymmetricCore(TreeNode* p, TreeNode* q) {
		if (!p && !q)
			return true;
		if (!p || !q || p->val != q->val)
			return false;
		return isSymmetricCore(p->left, q->right) && isSymmetricCore(p->right, q->left);
	}
};
```

