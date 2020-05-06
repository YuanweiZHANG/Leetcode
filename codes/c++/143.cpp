#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
* 2020-05-06
* Veronica
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	void reorderList(ListNode* head) {
		if (!head)
			return;
		stack<ListNode*> stk;
		ListNode *p = head;
		while (p) {
			stk.push(p);
			p = p->next;
		}
		p = head;
		while (!stk.empty()) {
			ListNode* back = stk.top();
			if (p == back) {
				p->next = NULL;
				return;
			}
			else if (p->next == back) {
				p->next->next = NULL;
				return;
			}
			else {
				back->next = p->next;
				p->next = back;
				p = back->next;
			}
			stk.pop();
		}
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

ListNode *createList(vector<int> lists) {
	if (lists.empty())
		return NULL;
	ListNode* head = new ListNode(lists[0]);
	ListNode* p = head;
	for (int i = 1; i < lists.size(); ++i) {
		p->next = new ListNode(lists[i]);
		p = p->next;
	}
	return head;
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

	ListNode *head = createList({ 1 });

	solution.reorderList(head);
	printList(head);

	deleteList(head);
	head = NULL;

	return 0;
}