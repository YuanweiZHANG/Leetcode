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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> results;
		if (!root)
			return results;
		queue<TreeNode*> que1, que2;
		que1.push(root);
		while (!que1.empty() || !que2.empty()) {
			if (que2.empty()) {
				vector<int> level;
				while (!que1.empty()) {
					TreeNode* curr = que1.front();
					level.push_back(curr->val);
					if (curr->left)
						que2.push(curr->left);
					if (curr->right)
						que2.push(curr->right);
					que1.pop();
				}
				if (!level.empty()) 
					results.push_back(level);
			}
			if (que1.empty()) {
				vector<int> level;
				while (!que2.empty()) {
					TreeNode* curr = que2.front();
					level.push_back(curr->val);
					if (curr->left)
						que1.push(curr->left);
					if (curr->right)
						que1.push(curr->right);
					que2.pop();
				}
				if (!level.empty())
					results.push_back(level);
			}
		}
		return results;
	}
};

int main() {
	Solution solution;

	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	
	vector<vector<int>> results = solution.levelOrder(root);
	for (auto a : results) {
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}

	delete root->left, root->right, root;
	root = NULL;

	return 0;
}