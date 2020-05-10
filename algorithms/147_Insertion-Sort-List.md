## 147. [Insertion Sort List](https://leetcode.com/problems/insertion-sort-list/)

> Medium

Sort a linked list using insertion sort.


![img](./imgs/147.gif)
A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list


**Algorithm of Insertion Sort:**

1. Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
2. At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
3. It repeats until no input elements remain.

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

`sortedHead` and `sortedTail` store the interval of sorted list. `unsortedHead` is the head of unsorted list. Sort it until `unsortedHead` is `NULL`.

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
	ListNode * insertionSortList(ListNode* head) {
		if (!head)
			return NULL;
		ListNode* unsortedHead = head->next, *unsorted = head->next;
		ListNode* sortedHead = head, *sortedTail = head;
		while (unsortedHead) {
			unsorted = unsortedHead;
			unsortedHead = unsortedHead->next;
			sortedTail->next = unsortedHead;
			ListNode* p = sortedHead;
			if (sortedHead->val > unsorted->val) {
				unsorted->next = sortedHead;
				sortedHead = unsorted;
			}
			else {
				while (p != sortedTail && p->next->val < unsorted->val)
					p = p->next;
				unsorted->next = p->next;
				p->next = unsorted;
				if (p == sortedTail)
					sortedTail = p->next;
			}
		}
		return sortedHead;
	}
};
```

