#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/**
* 2020-05-06
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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		if (!root)
			return result;
		stack<pair<TreeNode*, int>> stk;
		stk.push({ root, 0 });
		while (!stk.empty()) {
			TreeNode *curr = stk.top().first;
			int processTimes = stk.top().second;
			stk.pop();
			if (processTimes == 0) {
				stk.push({ curr,1 });
				if (curr->left)
					stk.push({ curr->left,0 });
			}
			else if (processTimes == 1) {
				stk.push({ curr,2 });
				if (curr->right)
					stk.push({ curr->right,0 });
			}
			else {
				result.push_back(curr->val);
			}
		}
		return result;
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

	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(5);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(4);

	vector<int> results = solution.postorderTraversal(root);
	for (auto node : results)
		cout << node << " ";

	deleteTree(root);
	root = NULL;

	return 0;
}