#include <iostream>
using namespace std;

/**
 * 2020-03-29
 * Veronica
 */
 
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL) return head;
		ListNode *first = head;
		ListNode *second = head;
		for (int i = 0; i < n; ++i) {
			first = first->next;
		}
		if (first == NULL) {
			ListNode * ret = head->next;
			head->next = NULL;
			delete head;
			return ret;
		}
		while (first->next != NULL) {
			first = first->next;
			second = second->next;
		}
		ListNode *delete_p = second->next;
		second->next = second->next->next;
		delete_p->next = NULL;
		delete delete_p;
		delete_p = NULL;
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
}

int main() {
	Solution solution;

	ListNode *head = new ListNode(1);
	ListNode *p = head;

	for (int i = 2; i <= 5; ++i) {
		p->next = new ListNode(i);
		p = p->next;
	}

	head = solution.removeNthFromEnd(head, 5);
	printList(head);

	deleteList(head);
	head = NULL;

	return 0;
}
