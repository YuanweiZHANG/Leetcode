#include <iostream>
#include <vector>
#include <stack>
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
	TreeNode * bstFromPreorder(vector<int>& preorder) {
		if (preorder.empty())
			return NULL;
		int n = preorder.size();
		TreeNode* root = new TreeNode(preorder[0]);
		stack<TreeNode*> stk;
		stk.push(root);
		for (int i = 1; i < n; ++i) {
			if (stk.empty())
				break;
			TreeNode* curr = stk.top();
			if (preorder[i] < curr->val) { // left children
				curr->left = new TreeNode(preorder[i]);
				stk.push(curr->left);
			}
			else {
				while (!stk.empty() && preorder[i] > stk.top()->val) {
					curr = stk.top();
					stk.pop();
				}
				if (stk.empty()) { // root
					curr = root;
				}
				while (curr->right)
					curr = curr->right;
				curr->right = new TreeNode(preorder[i]);
				stk.push(curr->right);
			}	
		}
		return root;
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

	vector<int> preorder = { 8,5,1,7,10,12 };
	TreeNode *root = solution.bstFromPreorder(preorder);
	printTree(root);

	deleteTree(root);

	return 0;
}