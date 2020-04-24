#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/**
* 2020-04-24
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
	int maxPathSum(TreeNode* root) {
		int maxPath = INT_MIN;
		maxPathSumCore(root, maxPath);
		return maxPath;
	}
	int maxPathSumCore(TreeNode* root, int& maxSum) {
		if (!root)
			return 0;
		int leftSum = maxPathSumCore(root->left, maxSum);
		int rightSum = maxPathSumCore(root->right, maxSum);
		int sum = root->val;
		if (leftSum > 0)
			sum += leftSum;
		if (rightSum > 0)
			sum += rightSum;
		maxSum = max(maxSum, sum);
		return max(root->val, max(leftSum, rightSum) + root->val);
	}
};

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

	TreeNode* root = new TreeNode(9);
	root->left = new TreeNode(6);
	root->right = new TreeNode(-3);
	root->right->left = new TreeNode(-6);
	root->right->right = new TreeNode(2);
	root->right->right->left = new TreeNode(2);
	root->right->right->left->left = new TreeNode(-6);
	root->right->right->left->right = new TreeNode(-6);
	root->right->right->left->left->left = new TreeNode(-6);

	cout << solution.maxPathSum(root) << endl;

	deleteTree(root);

	return 0;
}