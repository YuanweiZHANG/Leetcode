## 144. [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/)

> Medium

Given a binary tree, return the *preorder* traversal of its nodes' values.

**Example:**

```
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
```

**Follow up:** Recursive solution is trivial, could you do it iteratively?



**Solutions:**

`stack`. Every `TreeNode` must be processed twice in the `stack`. The first time, push it into the `result` and push its left child into the `stack`; the second time push its right child into the `stack`.

Here is my solution class:

```c++
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		if (!root)
			return result;
		stack<pair<TreeNode*, int>> stk;
		stk.push({ root, 0 });
		while (!stk.empty()) {
			TreeNode *curr = stk.top().first;
			int processTimes = stk.top().second;
			stk.pop();
			if (processTimes == 0) {
				result.push_back(curr->val);
				stk.push({ curr,1 });
				if (curr->left)
					stk.push({ curr->left, 0 });
			}
			else {
				if (curr->right)
					stk.push({ curr->right,0 });
			}
		}
		return result;
	}
};
```

