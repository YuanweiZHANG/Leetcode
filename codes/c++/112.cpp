#include <iostream>
#include <queue>
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
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root)
			return false;
		return hasPathSumCore(root, sum);
	}
	bool hasPathSumCore(TreeNode* root, int& sum) {
		if (!root->left && !root->right && sum == root->val)
			return true;
		sum -= root->val;
		int flag = false;
		if (root->left)
			flag = flag || hasPathSumCore(root->left, sum);
		if (root->right)
			flag = flag || hasPathSumCore(root->right, sum);
		sum += root->val;
		return flag;
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

	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right->right->right = new TreeNode(1);
	int sum = 22;

	cout << solution.hasPathSum(root, sum) << endl;

	deleteTree(root);

	return 0;
}