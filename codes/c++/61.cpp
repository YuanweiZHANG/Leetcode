#include <iostream>
using namespace std;

/**
* 2020-04-10
* Veronica
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * rotateRight(ListNode* head, int k) {
		if (!head)
			return head;
		int len = 1;
		ListNode *p = head;
		while (p->next) {
			p = p->next;
			len++;
		}
		k %= len;
		ListNode *newTail = head;
		for (int i = 0; i < len - k - 1; ++i) {
			newTail = newTail->next;
		}
		p->next = head;
		head = newTail->next;
		newTail->next = NULL;
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
	for (int i = 2; i < 6; ++i) {
		p->next = new ListNode(i);
		p = p->next;
	}
	int k = 2;

	head = solution.rotateRight(head, k);
	printList(head);
	deleteList(head);

	p = NULL;

	return 0;
}
