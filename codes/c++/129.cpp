#include <iostream>
#include <queue>
using namespace std;

/**
* 2020-04-29
* Veronica
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	int sumNumbers(TreeNode* root) {
		if (!root)
			return 0;
		return sumNumbersCore(root, 0);
	}
	int sumNumbersCore(TreeNode* root, int currNum) {
		currNum = currNum * 10 + root->val;
		if (!root->left && !root->right)
			return currNum;
		int leftSum = 0, rightSum = 0;
		if (root->left)
			leftSum = sumNumbersCore(root->left, currNum);
		if (root->right)
			rightSum = sumNumbersCore(root->right, currNum);
		return leftSum + rightSum;
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

	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(9);
	root->right = new TreeNode(0);
	root->left->left = new TreeNode(5);
	root->left->right = new TreeNode(1);
	cout << solution.sumNumbers(root) << endl;

	deleteTree(root);

	return 0;
}