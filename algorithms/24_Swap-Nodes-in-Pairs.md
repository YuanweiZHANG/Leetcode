## 24. [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)

> Medium

Given a linked list, swap every two adjacent nodes and return its head.

You may **not** modify the values in the list's nodes, only nodes itself may be changed.

 

**Example:**

```
Given 1->2->3->4, you should return the list as 2->1->4->3.
```



**Solutions:**

Link problems always have so many traps :)

When manipulating pointers, **be careful**:

- head == NULL
- head has 1 element
- head has odd elements

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
	ListNode * swapPairs(ListNode* head) {
		if (!head) 
			return NULL;
		ListNode *result = head->next;
		if (!result) {
			return head;
		}
		ListNode *pre = NULL;
		
		while (head && head->next) {
			ListNode *temp = head->next->next;
			head->next->next = head;
			if (pre)
				pre->next = head->next;
			head->next = temp;
			pre = head;
			head = head->next;
		}
		return result;
	}
};
```

