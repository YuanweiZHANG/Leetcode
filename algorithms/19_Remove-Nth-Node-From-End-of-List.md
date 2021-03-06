## 19. [Remode Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

> Medium

Given a linked list, remove the *n*-th node from the end of list and return its head.

**Example:**

```
Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
```

**Note:**

Given *n* will always be valid.

**Follow up:**

Could you do this in one pass?



**Solutions:**

Yes, I can do this in one pass hahaha. 

Define two pointer: `first`, `second`. Let `first` go ahead `second` n steps. Then both of them start to move. When `first->next` becomes `NULL`, `second->next` is the node to be deleted. 

Be careful when the `head` is the one we need to delete.

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
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL) return head;
		ListNode *first = head;
		ListNode *second = head;
		for (int i = 0; i < n; ++i) {
			first = first->next;
		}
		if (first == NULL) {
			ListNode * ret = head->next;
			head->next = NULL;
			delete head;
			return ret;
		}
		while (first->next != NULL) {
			first = first->next;
			second = second->next;
		}
		ListNode *delete_p = second->next;
		second->next = second->next->next;
		delete_p->next = NULL;
		delete delete_p;
		delete_p = NULL;
		return head;
	}
};
```

