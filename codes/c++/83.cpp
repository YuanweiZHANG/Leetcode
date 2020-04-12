#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/**
* 2020-04-12
* Veronica
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * deleteDuplicates(ListNode* head) {
		if (!head || !head->next)
			return head;
		ListNode *p = head;
		while (p && p->next) {
			while (p->next && p->val == p->next->val) {
				ListNode *del = p->next;
				p->next = p->next->next;
				del->next = NULL;
				delete del;
			}
			p = p->next;
		}
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
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(4);
	p = p->next;
	p->next = new ListNode(4);
	p = p->next;
	p->next = new ListNode(5);
	p = p->next;
	
	head = solution.deleteDuplicates(head);
	printList(head);
	
	deleteList(head);
	p = NULL;

	return 0;
}