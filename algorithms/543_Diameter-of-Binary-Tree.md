## 543. [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)

> Easy

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the **longest** path between any two nodes in a tree. This path may or may not pass through the root.

**Example:**
Given a binary tree

```
          1
         / \
        2   3
       / \     
      4   5    
```

Return **3**, which is the length of the path [4,2,1,3] or [5,2,1,3].

**Note:** The length of path between two nodes is represented by the number of edges between them.



**Solutions:**

DFS and calculate all nodes' depths. Define `NULL`'s depth is 0. Then the diameter of a node is it's left child's depth plus right child's depth.

Here is my solution class:

```c++
class Solution {
public:
	int diameterOfBinaryTree(TreeNode* root) {
		int diameter = 0;
		depth(root, diameter);
		return diameter;
	}
	int depth(TreeNode* root, int& diameter) {
		if (!root) {
			diameter = 0;
			return 0;
		}
		else {
			int diameterLeft = 0, diameterRight = 0;
			int depthLeft = depth(root->left, diameterLeft);
			int depthRight = depth(root->right, diameterRight);
			diameter = max(max(diameterLeft, diameterRight), depthLeft + depthRight);
			return max(depthLeft, depthRight) + 1;
		}
	}
};
```

