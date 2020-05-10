#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-05-09
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
	ListNode * sortList(ListNode* head) {
		if (!head)
			return NULL;
		ListNode* p = head;
		int n = 0;
		while (p) {
			n++;
			p = p->next;
		}
		return sortListCore(head, n);
	}

	ListNode * sortListCore(ListNode* head, int n) {
		if (n < 1)
			return NULL;
		else if (n == 1)
			return head;
		ListNode* leftEnd = head, *right = head;
		for (int i = 0; i < n / 2 - 1; ++i) {
			leftEnd = leftEnd->next;
			right = right->next;
		}
		right = right->next;
		leftEnd->next = NULL;
		ListNode* left = sortListCore(head, n / 2);
		right = sortListCore(right, n - n / 2);
		if (!left)
			return right;
		else if (!right)
			return left;

		if (right->val < left->val)
			swap(right, left);
		head = left;
		while (right) {
			ListNode* p = right;
			right = right->next;
			while (left->next && left->next->val < p->val)
				left = left->next;
			if (!left->next) { // left is used up
				left->next = p;
				break;
			}
			p->next = left->next;
			left->next = p;
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

	vector<int> lists = { 4,2,1,3 };
	ListNode* head = createList(lists);
	printList(head);
	ListNode* sortedHead = solution.sortList(head);
	printList(sortedHead);

	deleteList(sortedHead);
	head = sortedHead = NULL;

	return 0;
}