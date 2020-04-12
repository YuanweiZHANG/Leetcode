## 83. [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

> Easy

Given a sorted linked list, delete all duplicates such that each element appear only *once*.

**Example 1:**

```
Input: 1->1->2
Output: 1->2
```

**Example 2:**

```
Input: 1->1->2->3->3
Output: 1->2->3
```



**Solutions:**

Ignore `pre` pointer in Problem No.82.

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
	ListNode * deleteDuplicates(ListNode* head) {
		if (!head || !head->next)
			return head;
		ListNode *p = head;
		while (p && p->next) {
			while (p->next && p->val == p->next->val) {
				ListNode *del = p->next;
				p->next = p->next->next;
				del->next = NULL;
				delete del;
			}
			p = p->next;
		}
		return head;
	}
};
```

