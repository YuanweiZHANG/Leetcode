## 143. [Reorder List](https://leetcode.com/problems/reorder-list/)

> Medium

Given a singly linked list *L*: *L*0→*L*1→…→*L**n*-1→*L*n,
reorder it to: *L*0→*L**n*→*L*1→*L**n*-1→*L*2→*L**n*-2→…

You may **not** modify the values in the list's nodes, only nodes itself may be changed.

**Example 1:**

```
Given 1->2->3->4, reorder it to 1->4->2->3.
```

**Example 2:**

```
Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
```



**Solutions:**

This problem can be solved through `stack`.

Here is my solution class:

```c++
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
	void reorderList(ListNode* head) {
		if (!head)
			return;
		stack<ListNode*> stk;
		ListNode *p = head;
		while (p) {
			stk.push(p);
			p = p->next;
		}
		p = head;
		while (!stk.empty()) {
			ListNode* back = stk.top();
			if (p == back) {
				p->next = NULL;
				return;
			}
			else if (p->next == back) {
				p->next->next = NULL;
				return;
			}
			else {
				back->next = p->next;
				p->next = back;
				p = back->next;
			}
			stk.pop();
		}
	}
};
```

