## 145. [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/)

> Hard

Given a binary tree, return the *postorder* traversal of its nodes' values.

**Example:**

```
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
```

**Follow up:** Recursive solution is trivial, could you do it iteratively?



**Solutions:**

Similar as Problem No.144. However, this time we need to process each `TreeNode` three times in the `stack`. First time push its left child; second time, right child; third time, push itself into the `result`.

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
	vector<int> postorderTraversal(TreeNode* root) {
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
				stk.push({ curr,1 });
				if (curr->left)
					stk.push({ curr->left,0 });
			}
			else if (processTimes == 1) {
				stk.push({ curr,2 });
				if (curr->right)
					stk.push({ curr->right,0 });
			}
			else {
				result.push_back(curr->val);
			}
		}
		return result;
	}
};
```

