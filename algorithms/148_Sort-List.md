## 148. [Sort List](https://leetcode.com/problems/sort-list/)

> Medium

Sort a linked list in *O*(*n* log *n*) time using constant space complexity.

**Example 1:**

```
Input: 4->2->1->3
Output: 1->2->3->4
```

**Example 2:**

```
Input: -1->5->3->4->0
Output: -1->0->3->4->5
```



**Solutions:**

Divide and Conquer.

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
	ListNode * sortList(ListNode* head) {
		if (!head)
			return NULL;
		ListNode* p = head;
		int n = 0;
		while (p) {
			n++;
			p = p->next;
		}
		return sortListCore(head, n);
	}

	ListNode * sortListCore(ListNode* head, int n) {
		if (n < 1)
			return NULL;
		else if (n == 1)
			return head;
		ListNode* leftEnd = head, *right = head;
		for (int i = 0; i < n / 2 - 1; ++i) {
			leftEnd = leftEnd->next;
			right = right->next;
		}
		right = right->next;
		leftEnd->next = NULL;
		ListNode* left = sortListCore(head, n / 2);
		right = sortListCore(right, n - n / 2);
		if (!left)
			return right;
		else if (!right)
			return left;

		if (right->val < left->val)
			swap(right, left);
		head = left;
		while (right) {
			ListNode* p = right;
			right = right->next;
			while (left->next && left->next->val < p->val)
				left = left->next;
			if (!left->next) { // left is used up
				left->next = p;
				break;
			}
			p->next = left->next;
			left->next = p;
		}
		return head;
	}
};
```

