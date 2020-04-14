#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-14
* Veronica
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * reverseBetween(ListNode* head, int m, int n) {
		ListNode *preHead = new ListNode(0);
		preHead->next = head;
		ListNode *pre = preHead;
		for (int i = 1; i < m; ++i) {
			if (!pre->next)
				break;
			pre = pre->next;
		}
		ListNode *p = pre->next;
		for (int i = m; i < n; ++i) {
			ListNode *tmp = p->next;
			p->next = p->next->next;
			tmp->next = pre->next;
			pre->next = tmp;
		}
		head = preHead->next;
		delete preHead;
		return head;
	}
};

void printList(ListNode *head) {
	ListNode *pointer = head;
	while (pointer != NULL) {
		cout << pointer->val << " ";
		pointer = pointer->next;
	}
	cout << endl;
}

void deleteList(ListNode *head) {
	if (!head)
		return;
	ListNode *pointer = head->next;
	ListNode *delete_p = head;
	while (delete_p != NULL) {
		delete_p->next = NULL;
		delete delete_p;
		delete_p = pointer;
		if (pointer)
			pointer = pointer->next;
	}
	head = NULL;
}

int main() {
	Solution solution;

	ListNode *head = new ListNode(1);
	ListNode *p = head;
	for (int i = 2; i <= 5; ++i) {
		p->next = new ListNode(i);
		p = p->next;
	}
	int m = 2, n = 4;
	head = solution.reverseBetween(head, m, n);
	printList(head);

	deleteList(head);
	p = NULL;

	return 0;
}