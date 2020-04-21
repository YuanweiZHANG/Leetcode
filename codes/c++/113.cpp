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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> results;
		vector<int> curr;
		if (!root)
			return results;
		pathSumCore(results, root, sum, curr);
		return results;
	}
	void pathSumCore(vector<vector<int>>& results, TreeNode* root, int& sum, vector<int>& curr) {
		if (!root->left && !root->right && sum == root->val) {
			curr.push_back(root->val);
			results.push_back(curr);
			curr.pop_back();
			return;
		}
		sum -= root->val;
		curr.push_back(root->val);
		if (root->left)
			pathSumCore(results, root->left, sum, curr);
		if (root->right)
			pathSumCore(results, root->right, sum, curr);
		curr.pop_back();
		sum += root->val;
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
	root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);
	int sum = 22;

	vector<vector<int>> results = solution.pathSum(root, sum);
	for (auto a : results) {
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}

	deleteTree(root);

	return 0;
}