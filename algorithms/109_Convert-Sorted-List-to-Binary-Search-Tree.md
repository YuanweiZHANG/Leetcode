## 109. [Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)

> Medium

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of *every* node never differ by more than 1.

**Example:**

```
Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
```



**Solutions:**

Same as Problem No.108.

Here is my solution class:

```c++
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
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
	TreeNode* sortedListToBST(ListNode* head) {
		ListNode* p = head;
		int n = 0;
		while (p) {
			n++;
			p = p->next;
		}
		return sortedListToBSTCore(head, n);
	}
	TreeNode* sortedListToBSTCore(ListNode* head, int n) {
		if (n == 0)
			return NULL;
		int mid = n >> 1;
		ListNode* p = head;
		for (int i = 0; i < mid; ++i) {
			p = p->next;
		}
		TreeNode* root = new TreeNode(p->val);
		root->left = sortedListToBSTCore(head, mid);
		root->right = sortedListToBSTCore(p->next, n - mid - 1);
		return root;
	}
};
```

