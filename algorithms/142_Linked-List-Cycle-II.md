## 142. [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)

> Medium

Given a linked list, return the node where the cycle begins. If there is no cycle, return `null`.

To represent a cycle in the given linked list, we use an integer `pos` which represents the position (0-indexed) in the linked list where tail connects to. If `pos` is `-1`, then there is no cycle in the linked list.

**Note:** Do not modify the linked list.

 

**Example 1:**

```
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
```

![img](./imgs/142.png)

**Example 2:**

```
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
```

![img](./imgs/142-2.png)

**Example 3:**

```
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
```

![img](./imgs/142-3.png)

 

**Follow-up**:
Can you solve it without using extra space?



**Solutions:**

Use `fast` and `slow` pointers to judge whether the list has a cycle. If yes, when the first time  the `fast` and `slow` meet, the `fast` pointer goes farther a cycle than the `slow`. Therefore, if a pointer start by `head` and the other pointer starts by the next `ListNode` of the meeting place, they will run across at the first `ListNode` in the cycle.

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
	ListNode * detectCycle(ListNode *head) {
		if (!head)
			return NULL;
		ListNode *slow = head, *fast = head->next;
		while (fast && fast->next) {
			if (fast == slow) { // has cycle
				slow = head;
				fast = fast->next;
				while (fast != slow) {
					fast = fast->next;
					slow = slow->next;
				}
				return slow;
			}
			slow = slow->next;
			fast = fast->next->next;
		}
		return NULL;
	}
};
```

