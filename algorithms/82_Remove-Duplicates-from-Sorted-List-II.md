## 82. [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)

> Medium

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only *distinct* numbers from the original list.

Return the linked list sorted as well.

**Example 1:**

```
Input: 1->2->3->3->4->4->5
Output: 1->2->5
```

**Example 2:**

```
Input: 1->1->1->2->3
Output: 2->3
```



**Solutions:**

If `p->val == p->next->val`, we need to delete all `ListNode` whose `val` is `p->val`.

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
		ListNode *pre = new ListNode(-1);
		pre->next = p;
		ListNode *preHead = pre;
		while (p && p->next) {
			if (p->val == p->next->val) {
				while (p->next && p->val == p->next->val) {
					ListNode *del = p->next;
					p->next = p->next->next;
					del->next = NULL;
					delete del;
				}
				pre->next = p->next;
				p->next = NULL;
				delete p;
				p = pre->next;
			}
			else {
				pre = pre->next;
				p = p->next;
			}
		}
		head = preHead->next;
		preHead->next = NULL;
		delete preHead;
		return head;
	}
};
```

