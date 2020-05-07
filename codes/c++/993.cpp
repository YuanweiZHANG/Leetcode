#include <iostream>
#include <queue>
using namespace std;

/**
* 2020-05-07
* Veronica
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool isCousins(TreeNode* root, int x, int y) {
		if (!root)
			return false;
		int parentX = 0, parentY = 0;
		int depthX = isCousinsCore(root, x, parentX);
		int depthY = isCousinsCore(root, y, parentY);
		if (depthX == depthY && parentX != parentY)
			return true;
		else
			return false;
	}

	int isCousinsCore(TreeNode* root, int x, int& parent) {
		if (!root)
			return -1;
		if (root->val == x)
			return 0;
		int left = isCousinsCore(root->left, x, parent);
		int right = isCousinsCore(root->right, x, parent);
		if (left == 0 || right == 0) {
			parent = root->val;
			return 1;
		}
		else if (left != -1)
			return left + 1;
		else if (right != -1)
			return right + 1;
		else
			return -1;
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

	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->right = new TreeNode(5);

	cout << solution.isCousins(root, 6, 7) << endl;

	deleteTree(root);
	root = NULL;

	return 0;
}