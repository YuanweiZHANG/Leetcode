#include <iostream>
#include <vector>
#include <set>
using namespace std;

/**
* 2020-05-06
* Veronica
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (!head)
			return false;
		ListNode *fast = head->next, *slow = head;
		while (fast && slow && fast != slow) {
			slow = slow->next;
			fast = fast->next;
			if (!fast)
				return false;
			fast = fast->next;
		}
		if (!fast || !slow)
			return false;
		else
			return true;
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
	set<ListNode *> lists;
	while (head) {
		if (lists.find(head) == lists.end()) {
			lists.insert(head);
			head = head->next;
		}
		else
			break;
	}
	for (auto list : lists) {
		delete list;
	}
}

void addCircle(ListNode* head, int pos) {
	if (!head || pos == -1)
		return;
	ListNode* target = head;
	for (int i = 0; i < pos && target; ++i) {
		target = target->next;
	}
	ListNode* p = head;
	while (p->next)
		p = p->next;
	p->next = target;
}

int main() {
	Solution solution;

	ListNode *head = createList({ 3,2,0,4 });
	int pos = -1;
	addCircle(head, pos);

	cout << solution.hasCycle(head) << endl;

	deleteList(head);
	head = NULL;

	return 0;
}