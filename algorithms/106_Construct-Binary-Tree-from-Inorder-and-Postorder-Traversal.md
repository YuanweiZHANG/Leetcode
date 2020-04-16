## 106. [Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

> Medium

Given inorder and postorder traversal of a tree, construct the binary tree.

**Note:**
You may assume that duplicates do not exist in the tree.

For example, given

```
inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
```

Return the following binary tree:

```
    3
   / \
  9  20
    /  \
   15   7
```



**Solutions:**

Similar as Problem No.105.

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
	TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder) {
		int n = postorder.size();
		map<int, int> inorderMap;
		for (int i = 0; i < n; ++i) {
			inorderMap[inorder[i]] = i;
		}
		return buildTreeCore(inorderMap, postorder, 0, 0, n);
	}
	TreeNode* buildTreeCore(map<int,int>& inorderMap, vector<int>& postorder, int inorderBegin, int postorderBegin, int num) {
		if (num == 0)
			return NULL;
		TreeNode* root = new TreeNode(postorder[postorderBegin + num - 1]);
		int inorderIndex = inorderMap.find(root->val)->second;
		root->left = buildTreeCore(inorderMap, postorder, inorderBegin, postorderBegin, inorderIndex - inorderBegin);
		root->right = buildTreeCore(inorderMap, postorder, inorderIndex + 1, postorderBegin + inorderIndex - inorderBegin, num - (inorderIndex - inorderBegin) - 1);
		return root;
	}
};
```

