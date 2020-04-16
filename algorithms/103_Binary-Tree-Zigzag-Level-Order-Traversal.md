## 103. [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

> Medium

Given a binary tree, return the *zigzag level order* traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7
```

return its zigzag level order traversal as:

```
[
  [3],
  [20,9],
  [15,7]
]
```



**Solutions:**

Define two stacks. Each stack stores a layer. However, first one is pushed from left children to right children, and second one is pushed from right to left.

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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> results;
		if (!root)
			return results;
		vector<stack<TreeNode*>> stk(2);
		stk[0].push(root);
		while (!stk[0].empty() || !stk[1].empty()) {
			for (int i = 0; i < 2; ++i) {
				if (!stk[i].empty()) {
					vector<int> level;
					while (!stk[i].empty()) {
						TreeNode* curr = stk[i].top();
						level.push_back(curr->val);
						if (i == 0){
							if (curr->left)
								stk[1 - i].push(curr->left);
							if (curr->right)
								stk[1 - i].push(curr->right);
						}
						else {
							if (curr->right)
								stk[1 - i].push(curr->right);
							if (curr->left)
								stk[1 - i].push(curr->left);
						}
						stk[i].pop();
					}
					if (!level.empty())
						results.push_back(level);
				}
			}
		}
		return results;
	}
};
```

