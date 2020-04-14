##92. [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/) 

> Medium

Reverse a linked list from position *m* to *n*. Do it in one-pass.

**Note:** 1 ≤ *m* ≤ *n* ≤ length of list.

**Example:**

```
Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
```



**Solutions:**

Move `p->next` to `pre->next` m - n times.

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
	ListNode * reverseBetween(ListNode* head, int m, int n) {
		ListNode *preHead = new ListNode(0);
		preHead->next = head;
		ListNode *pre = preHead;
		for (int i = 1; i < m; ++i) {
			if (!pre->next)
				break;
			pre = pre->next;
		}
		ListNode *p = pre->next;
		for (int i = m; i < n; ++i) {
			ListNode *tmp = p->next;
			p->next = p->next->next;
			tmp->next = pre->next;
			pre->next = tmp;
		}
		head = preHead->next;
		delete preHead;
		return head;
	}
};
```

