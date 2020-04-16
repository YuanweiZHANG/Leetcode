#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
	TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder) {
		int n = postorder.size();
		map<int, int> inorderMap;
		for (int i = 0; i < n; ++i) {
			inorderMap[inorder[i]] = i;
		}
		return buildTreeCore(inorderMap, postorder, 0, 0, n);
	}
	TreeNode* buildTreeCore(map<int,int>& inorderMap, vector<int>& postorder, int inorderBegin, int postorderBegin, int num) {
		if (num == 0)
			return NULL;
		TreeNode* root = new TreeNode(postorder[postorderBegin + num - 1]);
		int inorderIndex = inorderMap.find(root->val)->second;
		root->left = buildTreeCore(inorderMap, postorder, inorderBegin, postorderBegin, inorderIndex - inorderBegin);
		root->right = buildTreeCore(inorderMap, postorder, inorderIndex + 1, postorderBegin + inorderIndex - inorderBegin, num - (inorderIndex - inorderBegin) - 1);
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

	vector<int> preorder = { 9,3,15,20,7 };
	vector<int> inorder = { 9,15,7,20,3 };
	TreeNode* root = solution.buildTree(preorder, inorder);
	printTree(root);

	deleteTree(root);

	return 0;
}