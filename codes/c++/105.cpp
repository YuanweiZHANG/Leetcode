#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
* 2020-04-16
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		return buildTreeCore(preorder, inorder, 0, 0, n);
	}
	TreeNode* buildTreeCore(vector<int>& preorder, vector<int>& inorder, int preorderBegin, int inorderBegin, int num) {
		if (num == 0)
			return NULL;
		TreeNode* root = new TreeNode(preorder[preorderBegin]);
		
		for (int i = 0; i < num; ++i) {
			if (inorder[i + inorderBegin] == root->val) {
				root->left = buildTreeCore(preorder, inorder, preorderBegin + 1, inorderBegin, i);
				root->right = buildTreeCore(preorder, inorder, preorderBegin + i + 1, inorderBegin + i + 1, num - i - 1);
			}
		}
		return root;
	}
};

void printTree(TreeNode* root) {
	if (!root)
		return;
	queue<TreeNode*> que;
	que.push(root);
	while (!que.empty()) {
		TreeNode* curr = que.front();
		cout << curr->val << " ";
		if (curr->left)
			que.push(curr->left);
		if (curr->right)
			que.push(curr->right);
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

	vector<int> preorder = { 3,9,20,15,7 };
	vector<int> inorder = { 9,3,15,20,7 };
	TreeNode* root = solution.buildTree(preorder, inorder);
	printTree(root);

	deleteTree(root);

	return 0;
}