#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> results;
		if (!root)
			return results;
		stack<vector<int>> stk;
		vector<queue<TreeNode*>> que(2);
		que[0].push(root);
		while (!que[0].empty() || !que[1].empty()) {
			for (int i = 0; i < 2; ++i) {
				if (!que[i].empty()) {
					vector<int> level;
					while (!que[i].empty()) {
						TreeNode* curr = que[i].front();
						level.push_back(curr->val);
						if (curr->left)
							que[1 - i].push(curr->left);
						if (curr->right)
							que[1 - i].push(curr->right);
						que[i].pop();
					}
					stk.push(level);
				}
			}
		}
		while (!stk.empty()) {
			results.push_back(stk.top());
			stk.pop();
		}
		return results;
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

	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	vector<vector<int>> results = solution.levelOrderBottom(root);
	for (auto a : results) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}

	deleteTree(root);

	return 0;
}