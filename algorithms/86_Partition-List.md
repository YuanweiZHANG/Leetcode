##86. [Partition List](https://leetcode.com/problems/partition-list/) 

> Medium

Given a linked list and a value *x*, partition it such that all nodes less than *x* come before nodes greater than or equal to *x*.

You should preserve the original relative order of the nodes in each of the two partitions.

**Example:**

```
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
```



**Solutions:**

`small` is the head of the List smaller than `x`; `big` is the head of the List bigger than `x`. Then link the `small` and `big`.

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
	ListNode * partition(ListNode* head, int x) {
		if (!head)
			return head;
		ListNode *p = head;
		ListNode *small = new ListNode(-1);
		ListNode *big = new ListNode(-1);
		
		ListNode *smallIndex = small;
		ListNode *bigIndex = big;
		while (p) {
			if (p->val < x) {
				smallIndex->next = p;
				p = p->next;
				smallIndex = smallIndex->next;
			}
			else {
				bigIndex->next = p;
				p = p->next;
				bigIndex = bigIndex->next;
				bigIndex->next = NULL;
			}
			smallIndex->next = big->next;
		}
		head = small->next;
		delete small, big;
		return head;
	}
};
```

