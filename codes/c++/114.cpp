#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/**
* 2020-04-22
* Veronica
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void flatten(TreeNode* root) {
		if (!root)
			return;
		stack<pair<TreeNode*, int>> stk;
		queue<TreeNode*> que;
		stk.push(make_pair(root, 0));
		while (!stk.empty()) {
			TreeNode* curr = stk.top().first;
			int processTimes = stk.top().second;
			stk.pop();
			if (processTimes == 0) {
				que.push(curr);
				stk.push(make_pair(curr, 1));
				if (curr->left)
					stk.push(make_pair(curr->left, 0));
			}
			else {
				if (curr->right) {
					stk.push(make_pair(curr->right, 0));
				}
			}
		}
		TreeNode* preHead = new TreeNode(0);
		TreeNode* pre = preHead;
		while (!que.empty()) {
			pre->right = que.front();
			pre = pre->right;
			pre->left = NULL;
			pre->right = NULL;
			que.pop();
		}
		root = preHead->right;
		delete preHead;
		return;
	}
};

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

	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->right = new TreeNode(6);

	solution.flatten(root);
	printTree(root);

	deleteTree(root);

	return 0;
}