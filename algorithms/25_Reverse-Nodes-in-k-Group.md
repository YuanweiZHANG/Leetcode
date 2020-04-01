## 25. [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)

> Hard

Given a linked list, reverse the nodes of a linked list *k* at a time and return its modified list.

*k* is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of *k* then left-out nodes in the end should remain as it is.


**Example:**

Given this linked list: `1->2->3->4->5`

For *k* = 2, you should return: `2->1->4->3->5`

For *k* = 3, you should return: `3->2->1->4->5`

**Note:**

- Only constant extra memory is allowed.
- You may not alter the values in the list's nodes, only nodes itself may be changed.



**Solutions:**

Use stack to reverse in k-group.

`if (i != k)` is the key to ensure not reverse left-out nodes.

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
class Solution {
public:
	ListNode * reverseKGroup(ListNode* head, int k) {
		if (!head || k == 1) return head;
		stack<ListNode *> stk;
		ListNode *result = NULL, *pre_head = new ListNode(0);
		pre_head->next = head;
		ListNode *pre_tail = pre_head;
		int i = 0;
		while (pre_tail->next) {
			ListNode *p = pre_tail;
			for (i = 0; i < k; ++i) {
				if (!p->next) // If I put this sentence behind p = p->next, it can cause wrong
					break;
				stk.push(p->next);
				p = p->next;
			}
			if (i != k) 
				break;
			ListNode *temp = stk.top()->next;
			while (!stk.empty()) {
				ListNode *curr = stk.top();
				stk.pop();
				if (!stk.empty()) {
					curr->next = stk.top();
				}
				else {
					curr->next = temp;
				}
				pre_tail->next = curr;
				pre_tail = pre_tail->next;
			}
		}
		result = pre_head->next;
		delete pre_head;
		return result;
	}
};
```

However, because I use stack data structure, it could cost much. I found others' solution is better. Every time insert curr->next behind pre. After k - 1 times, k-group is reversed.

```c++
for(int i=1; i<k; i++) {
    cur->next = nex->next;
    nex->next = pre->next;
    pre->next = nex;
    nex = cur->next;
}
```

