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
	ListNode * swapPairs(ListNode* head) {
		if (!head) 
			return NULL;
		ListNode *result = head->next;
		if (!result) {
			return head;
		}
		ListNode *pre = NULL;
		
		while (head && head->next) {
			ListNode *temp = head->next->next;
			head->next->next = head;
			if (pre)
				pre->next = head->next;
			head->next = temp;
			pre = head;
			head = head->next;
		}
		return result;
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
	for (int i = 2; i < 6; ++i) {
		p->next = new ListNode(i);
		p = p->next;
	}
	
	head = solution.swapPairs(head);
	printList(head);
	
	deleteList(head);
	p = NULL;
	return 0;
}
