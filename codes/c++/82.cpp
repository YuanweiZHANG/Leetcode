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
		ListNode *pre = new ListNode(-1);
		pre->next = p;
		ListNode *preHead = pre;
		while (p && p->next) {
			if (p->val == p->next->val) {
				while (p->next && p->val == p->next->val) {
					ListNode *del = p->next;
					p->next = p->next->next;
					del->next = NULL;
					delete del;
				}
				pre->next = p->next;
				p->next = NULL;
				delete p;
				p = pre->next;
			}
			else {
				pre = pre->next;
				p = p->next;
			}
		}
		head = preHead->next;
		preHead->next = NULL;
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
	p->next = new ListNode(1);
	p = p->next;
	/*
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
	*/
	head = solution.deleteDuplicates(head);
	printList(head);
	
	deleteList(head);
	p = NULL;

	return 0;
}