## 21. [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

> Easy

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

**Example:**

```
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
```

**Solutions:**

It's easy. **Just be careful when input lists are NULL.**

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
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
		else if (l2 == NULL) return l1;

		ListNode *head = NULL, *p = NULL;

		if (l1->val <= l2->val) {
			head = l1;
			l1 = l1->next;
		}
		else {
			head = l2;
			l2 = l2->next;
		}
		p = head;
		while (l1 != NULL && l2 != NULL) {
			if (l1->val <= l2->val) {
				p->next = l1;
				l1 = l1->next;
			}
			else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		if (l1 != NULL)
			p->next = l1;
		else
			p->next = l2;
		return head;
	}
};
```

