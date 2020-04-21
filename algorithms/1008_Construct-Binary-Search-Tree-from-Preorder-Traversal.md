## 1008. [Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)

> Medium

Return the root node of a binary **search** tree that matches the given `preorder` traversal.

*(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)*

 

**Example 1:**

```
Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
```

![img](./imgs/1008.png)

**Note:** 

1. `1 <= preorder.length <= 100`
2. The values of `preorder` are distinct.



**Solutions:**

Use stack to emulate preorder traversal. If `preorder[i] < curr->val`, `preorder[i]` must be `curr`'s left child. If `preorder[i] > curr->val`, find the TreeNode `curr` in stack where `preorder[i] < curr->val`, then `preorder[i]` must be `curr->left`'s farthest right children.

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
	TreeNode * bstFromPreorder(vector<int>& preorder) {
		if (preorder.empty())
			return NULL;
		int n = preorder.size();
		TreeNode* root = new TreeNode(preorder[0]);
		stack<TreeNode*> stk;
		stk.push(root);
		for (int i = 1; i < n; ++i) {
			if (stk.empty())
				break;
			TreeNode* curr = stk.top();
			if (preorder[i] < curr->val) { // left children
				curr->left = new TreeNode(preorder[i]);
				stk.push(curr->left);
			}
			else {
				while (!stk.empty() && preorder[i] > stk.top()->val) {
					curr = stk.top();
					stk.pop();
				}
				if (stk.empty()) { // root
					curr = root;
				}
				while (curr->right)
					curr = curr->right;
				curr->right = new TreeNode(preorder[i]);
				stk.push(curr->right);
			}	
		}
		return root;
	}
};
```

