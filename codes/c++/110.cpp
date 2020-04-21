#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/**
* 2020-04-20
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
	bool isBalanced(TreeNode* root) {
		if (!root)
			return true;
		int h = height(root);
		if (h == -1)
			return false;
		else
			return true;
	}
	int height(TreeNode* root) {
		if (!root)
			return 0;
		int left = height(root->left);
		int right = height(root->right);
		if (left == -1 || right == -1)
			return -1;
		if (abs(left - right) > 1)
			return -1;
		return max(height(root->left), height(root->right)) + 1;
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

	TreeNode* root = NULL;

	cout << solution.isBalanced(root) << endl;

	deleteTree(root);

	return 0;
}