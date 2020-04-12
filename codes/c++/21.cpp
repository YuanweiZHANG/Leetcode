#include <iostream>
using namespace std;

/**
 * 2020-03-30
 * Veronica
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
		else if (l2 == NULL) return l1;

		ListNode *head = NULL, *p = NULL;

		if (l1->val <= l2->val) {
			head = l1;
			l1 = l1->next;
		}
		else {
			head = l2;
			l2 = l2->next;
		}
		p = head;
		while (l1 != NULL && l2 != NULL) {
			if (l1->val <= l2->val) {
				p->next = l1;
				l1 = l1->next;
			}
			else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		if (l1 != NULL)
			p->next = l1;
		else
			p->next = l2;
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

	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(1);
	ListNode *p1 = l1, *p2 = l2;
	p1->next = new ListNode(2);
	p1 = p1->next;
	p1->next = new ListNode(4);
	p1 = p1->next;
	p2->next = new ListNode(3);
	p2 = p2->next;
	p2->next = new ListNode(4);
	p2 = p2->next;

	ListNode *result = solution.mergeTwoLists(l1, l2);
	printList(result);
	deleteList(result);
	
	p1 = p2 = l1 = l2 = NULL;

	return 0;
}
