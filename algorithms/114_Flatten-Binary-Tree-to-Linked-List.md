## 114. [Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)

> Medium

Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

```
    1
   / \
  2   5
 / \   \
3   4   6
```

The flattened tree should look like:

```
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
```



**Solutions:**

Use stack to traversal the Tree, and use queue to store every nodes' address. Then flatten all TreeNodes.

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
	void flatten(TreeNode* root) {
		if (!root)
			return;
		stack<pair<TreeNode*, int>> stk;
		queue<TreeNode*> que;
		stk.push(make_pair(root, 0));
		while (!stk.empty()) {
			TreeNode* curr = stk.top().first;
			int processTimes = stk.top().second;
			stk.pop();
			if (processTimes == 0) {
				que.push(curr);
				stk.push(make_pair(curr, 1));
				if (curr->left)
					stk.push(make_pair(curr->left, 0));
			}
			else {
				if (curr->right) {
					stk.push(make_pair(curr->right, 0));
				}
			}
		}
		TreeNode* preHead = new TreeNode(0);
		TreeNode* pre = preHead;
		while (!que.empty()) {
			pre->right = que.front();
			pre = pre->right;
			pre->left = NULL;
			pre->right = NULL;
			que.pop();
		}
		root = preHead->right;
		delete preHead;
		return;
	}
};
```

