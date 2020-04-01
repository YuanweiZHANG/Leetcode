#include <iostream>
#include <stack>
using namespace std;

/**
* 2020-03-31 
* Veronica
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * reverseKGroup(ListNode* head, int k) {
		if (!head || k == 1) return head;
		stack<ListNode *> stk;
		ListNode *result = NULL, *pre_head = new ListNode(0);
		pre_head->next = head;
		ListNode *pre_tail = pre_head;
		int i = 0;
		while (pre_tail->next) {
			ListNode *p = pre_tail;
			for (i = 0; i < k; ++i) {
				if (!p->next) // If I put this sentence behind p = p->next, it can cause wrong
					break;
				stk.push(p->next);
				p = p->next;
			}
			if (i != k) 
				break;
			ListNode *temp = stk.top()->next;
			while (!stk.empty()) {
				ListNode *curr = stk.top();
				stk.pop();
				if (!stk.empty()) {
					curr->next = stk.top();
				}
				else {
					curr->next = temp;
				}
				pre_tail->next = curr;
				pre_tail = pre_tail->next;
			}
		}
		result = pre_head->next;
		delete pre_head;
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

	int k = 5;
	ListNode *head = new ListNode(1);
	ListNode *p = head;
	for (int i = 2; i < 6; ++i) {
		p->next = new ListNode(i);
		p = p->next;
	}

	head = solution.reverseKGroup(head, k);
	printList(head);

	deleteList(head);
	p = NULL;
	return 0;
}
