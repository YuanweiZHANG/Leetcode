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
	ListNode * insertionSortList(ListNode* head) {
		if (!head)
			return NULL;
		ListNode* unsortedHead = head->next, *unsorted = head->next;
		ListNode* sortedHead = head, *sortedTail = head;
		while (unsortedHead) {
			unsorted = unsortedHead;
			unsortedHead = unsortedHead->next;
			sortedTail->next = unsortedHead;
			ListNode* p = sortedHead;
			if (sortedHead->val > unsorted->val) {
				unsorted->next = sortedHead;
				sortedHead = unsorted;
			}
			else {
				while (p != sortedTail && p->next->val < unsorted->val)
					p = p->next;
				unsorted->next = p->next;
				p->next = unsorted;
				if (p == sortedTail)
					sortedTail = p->next;
			}
		}
		return sortedHead;
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

	vector<int> lists = { -1 };
	ListNode* head = createList(lists);
	printList(head);
	ListNode* sortedHead = solution.insertionSortList(head);
	printList(sortedHead);

	deleteList(sortedHead);
	head = sortedHead = NULL;

	return 0;
}