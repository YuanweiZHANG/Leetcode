#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-13
* Veronica
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

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
	p->next = new ListNode(4);
	p = p->next;
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(5);
	p = p->next;
	p->next = new ListNode(2);
	p = p->next;
	int x = 3;
	head = solution.partition(head, x);
	printList(head);

	deleteList(head);
	p = NULL;

	return 0;
}