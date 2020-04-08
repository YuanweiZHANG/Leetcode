#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/**
* 2020-04-08
* Veronica
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * middleNode(ListNode* head) {
		if (!head)
			return head;
		ListNode *slow = head;
		ListNode *fast = head->next;
		if (!fast)
			return head;
		while (fast) {
			slow = slow->next;
			fast = fast->next;
			if (!fast)
				break;
			fast = fast->next;
		}
		return slow;
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
	for (int i = 2; i < 7; ++i) {
		p->next = new ListNode(i);
		p = p->next;
	}

	p = solution.middleNode(head);
	printList(p);

	deleteList(head);
	p = NULL;
	return 0;

	return 0;
}