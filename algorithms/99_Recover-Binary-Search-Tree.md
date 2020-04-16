## 99. [Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/)

> Hard

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

**Example 1:**

```
Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
```

**Example 2:**

```
Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
```

**Follow up:**

- A solution using O(*n*) space is pretty straight forward.
- Could you devise a constant space solution?



**Solutions:**

There has a stupid solution:

Store BST to a `vector`, then find the two mistaken numbers, swap them.

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
	void recoverTree(TreeNode* root) {
		if (!root)
			return;
		stack<pair<TreeNode*, int>> stk;
		vector<TreeNode*> bst;
		stk.push(make_pair(root, 0));
		while (!stk.empty()) {
			TreeNode* curr = stk.top().first;
			int processTimes = stk.top().second;
			stk.pop();
			if (processTimes == 0) {
				stk.push(make_pair(curr, 1));
				if (curr->left)
					stk.push(make_pair(curr->left, 0));
			}
			else {
				bst.push_back(curr);
				if (curr->right)
					stk.push(make_pair(curr->right, 0));
			}
		}
		int n = bst.size();
		int first = 0, second = 0;
		for (first = 0; first < n - 1; ++first) {
			if (bst[first]->val > bst[first + 1]->val)
				break;
		}
		for (second = first; second < n - 1; second++) {
			if (bst[second + 1]->val > bst[first]->val)
				break;
		}
		int tempVal = bst[first]->val;
		bst[first]->val = bst[second]->val;
		bst[second]->val = tempVal;
		return;
	}
};
```

