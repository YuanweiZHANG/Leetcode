#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
* 2020-04-20
* Veronica
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		ListNode* p = head;
		int n = 0;
		while (p) {
			n++;
			p = p->next;
		}
		return sortedListToBSTCore(head, n);
	}
	TreeNode* sortedListToBSTCore(ListNode* head, int n) {
		if (n == 0)
			return NULL;
		int mid = n >> 1;
		ListNode* p = head;
		for (int i = 0; i < mid; ++i) {
			p = p->next;
		}
		TreeNode* root = new TreeNode(p->val);
		root->left = sortedListToBSTCore(head, mid);
		root->right = sortedListToBSTCore(p->next, n - mid - 1);
		return root;
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

void printTree(TreeNode* root) {
	if (!root) {
		cout << "null" << " ";
		return;
	}
	queue<TreeNode*> que;
	que.push(root);
	while (!que.empty()) {
		TreeNode* curr = que.front();
		if (curr == NULL)
			cout << "null ";
		else {
			cout << curr->val << " ";
			que.push(curr->left);
			que.push(curr->right);
		}
		que.pop();
	}
}

void deleteTree(TreeNode* root) {
	if (!root)
		return;
	queue<TreeNode*> que;
	que.push(root);
	while (!que.empty()) {
		TreeNode* curr = que.front();
		if (curr->left)
			que.push(curr->left);
		if (curr->right)
			que.push(curr->right);
		que.pop();
		curr->left = curr->right = NULL;
		delete curr;
	}
	root = NULL;
}

int main() {
	Solution solution;

	ListNode* head = new ListNode(-10);
	ListNode* p = head;
	p->next = new ListNode(-3);
	p = p->next;
	p->next = new ListNode(0);
	p = p->next;
	p->next = new ListNode(5);
	p = p->next;
	p->next = new ListNode(9);
	p = p->next;

	TreeNode* root = solution.sortedListToBST(head);
	printTree(root);

	deleteList(head);
	deleteTree(root);

	return 0;
}