## 105. [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

> Medium

Given preorder and inorder traversal of a tree, construct the binary tree.

**Note:**
You may assume that duplicates do not exist in the tree.

For example, given

```
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
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

Recursion.

The first element of `preorder` is `root`. Use `preoder[preorderBegin]` can separate left children and right children in `inorder`.

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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		return buildTreeCore(preorder, inorder, 0, 0, n);
	}
	TreeNode* buildTreeCore(vector<int>& preorder, vector<int>& inorder, int preorderBegin, int inorderBegin, int num) {
		if (num == 0)
			return NULL;
		TreeNode* root = new TreeNode(preorder[preorderBegin]);
		
		for (int i = 0; i < num; ++i) {
			if (inorder[i + inorderBegin] == root->val) {
				root->left = buildTreeCore(preorder, inorder, preorderBegin + 1, inorderBegin, i);
				root->right = buildTreeCore(preorder, inorder, preorderBegin + i + 1, inorderBegin + i + 1, num - i - 1);
			}
		}
		return root;
	}
};
```

Someone stores `inorder` into a map, where key is `inorder`'s value, value is `inorder`'s index. This can fast the searching process.