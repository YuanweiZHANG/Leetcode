#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
* 2020-04-30
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
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
	bool isValidSequence(TreeNode* root, vector<int>& arr) {
		if (!root)
			return false;
		queue<pair<TreeNode*, int/*index*/>> que;
		que.push({ root,0 });
		while (!que.empty()) {
			TreeNode* curr = que.front().first;
			int index = que.front().second;
			if (index < arr.size() && curr->val == arr[index]) {
				if (index == arr.size() - 1 && !curr->left && !curr->right)
					return true;
				if (curr->left)
					que.push({ curr->left, index + 1 });
				if (curr->right)
					que.push({ curr->right,index + 1 });
			}
			que.pop();
		}
		return false;
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

	TreeNode* root = new TreeNode(0);
	root->left = new TreeNode(1);
	root->right = new TreeNode(0);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(1);
	root->right->left = new TreeNode(0);
	root->left->left->right = new TreeNode(1);
	root->left->right->left = new TreeNode(0);
	root->left->right->right = new TreeNode(0);
	vector<int> arr = { 0,1,0,1 };
	
	cout << solution.isValidSequence(root, arr) << endl;

	deleteTree(root);

	return 0;
}