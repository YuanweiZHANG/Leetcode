## 138. [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/)

> Medium

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a [**deep copy**](https://en.wikipedia.org/wiki/Object_copying#Deep_copy) of the list.

The Linked List is represented in the input/output as a list of `n` nodes. Each node is represented as a pair of `[val, random_index]` where:

- `val`: an integer representing `Node.val`
- `random_index`: the index of the node (range from `0` to `n-1`) where random pointer points to, or `null` if it does not point to any node.

 

**Example 1:**

![img](./imgs/138.png)

```
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
```

**Example 2:**

![img](./imgs/138-2.png)

```
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
```

**Example 3:**

**![img](./imgs/138-3.png)**

```
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
```

**Example 4:**

```
Input: head = []
Output: []
Explanation: Given linked list is empty (null pointer), so return null.
```

 

**Constraints:**

- `-10000 <= Node.val <= 10000`
- `Node.random` is null or pointing to a node in the linked list.
- Number of Nodes will not exceed 1000.



**Solutions:**

Use map to store the relationship between old list and new list.

Here is my solution class:

```c++
/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
*/

class Solution {
public:
	Node * copyRandomList(Node* head) {
		if (!head)
			return NULL;
		Node* newHead = new Node(head->val);
		map<Node*, Node*> mp;
		mp[NULL] = NULL; // trick
		mp[head] = newHead;
		Node* p = head;
		while (p) {
			if (mp.find(p->next) == mp.end())
				mp[p->next] = new Node(p->next->val);
			if (mp.find(p->random) == mp.end())
				mp[p->random] = new Node(p->random->val);
			mp[p]->next = mp[p->next];
			mp[p]->random = mp[p->random];
			p = p->next;
		}
		return newHead;
	}
};
```

