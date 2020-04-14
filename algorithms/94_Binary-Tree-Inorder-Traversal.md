##94. [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/) 

> Medium

Given a binary tree, return the *inorder* traversal of its nodes' values.

**Example:**

```
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
```

**Follow up:** Recursive solution is trivial, could you do it iteratively?



**Solutions:**

Recursive is so easy. Here I implement iterative solution. 

Every `TreeNode` has a parameter named `processTimes`. `processTimes == 0` means it is the first time push into the stack, so we need to handle its left child first. `processTimes == 1` means we have already handle its left child, so at this time, print it and then handle its right child.

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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> results;
		if (!root)
			return results;
		stack<pair<TreeNode*, int/*process times*/>> stk;
		stk.push(make_pair(root, 0));
		while (!stk.empty()) {
			TreeNode *curr = stk.top().first;
			int processTimes = stk.top().second;
			if (processTimes == 0) {
				stk.pop();
				stk.push(make_pair(curr, processTimes + 1));
				if (curr->left) {
					stk.push(make_pair(curr->left,0));
				}
			}
			else {
				results.push_back(curr->val);
				stk.pop();
				if (curr->right) {
					stk.push(make_pair(curr->right,0));
				}
			}
		}
		return results;
	}
};
```

