## 117. [Populating Next Right Pointers in Each Node II](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)

> Medium

Given a binary tree

```
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to `NULL`.

Initially, all next pointers are set to `NULL`.

 

**Follow up:**

- You may only use constant extra space.
- Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.

 

**Example 1:**

![img](./imgs/117.png)

```
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
```

 

**Constraints:**

- The number of nodes in the given tree is less than `6000`.
- `-100 <= node.val <= 100`



**Solutions:**

Same as Problem No.116.

Here is my solution class:

```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
	Node * connect(Node* root) {
		if (!root)
			return root;
		root->next = NULL;
		vector<queue<Node*>> que(2);
		que[0].push(root);
		while (!que[0].empty() || !que[1].empty()) {
			for (int i = 0; i < 2; ++i) {
				if (!que[i].empty()) {
					while (!que[i].empty()) {
						Node* curr = que[i].front();
						que[i].pop();
						if (curr->left) {
							que[1 - i].push(curr->left);
						}
						if (curr->right) {
							que[1 - i].push(curr->right);
						}
						if (!que[i].empty())
							curr->next = que[i].front();
						else
							curr->next = NULL;
					}
				}
			}
		}
		return root;
	}
};
```

