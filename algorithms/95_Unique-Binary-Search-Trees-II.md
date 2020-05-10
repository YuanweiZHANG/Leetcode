## 95. [Unique Binary Search Trees II]

> Medium

Given an integer *n*, generate all structurally unique **BST's** (binary search trees) that store values 1 ... *n*.

**Example:**

```
Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```



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
private:
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0)
			return {};
		return generateTreesCore(1, n);
	}

	vector<TreeNode*> generateTreesCore(int start, int end) {
		if (start > end)
			return { NULL };
		vector<TreeNode*> roots;
		for (int i = start; i <= end; ++i) {
			vector<TreeNode*> lefts = generateTreesCore(start, i - 1);
			vector<TreeNode*> rights = generateTreesCore(i + 1, end);
			for (auto left : lefts) {
				for (auto right : rights) {
					TreeNode *root = new TreeNode(i);
					root->left = left;
					root->right = right;
					roots.push_back(root);
				}
			}
		}
		return roots;
	}
};
```

