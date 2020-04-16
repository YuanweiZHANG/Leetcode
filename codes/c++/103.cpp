#include <iostream>
#include <vector>
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> results;
		if (!root)
			return results;
		vector<stack<TreeNode*>> stk(2);
		stk[0].push(root);
		while (!stk[0].empty() || !stk[1].empty()) {
			for (int i = 0; i < 2; ++i) {
				if (!stk[i].empty()) {
					vector<int> level;
					while (!stk[i].empty()) {
						TreeNode* curr = stk[i].top();
						level.push_back(curr->val);
						if (i == 0){
							if (curr->left)
								stk[1 - i].push(curr->left);
							if (curr->right)
								stk[1 - i].push(curr->right);
						}
						else {
							if (curr->right)
								stk[1 - i].push(curr->right);
							if (curr->left)
								stk[1 - i].push(curr->left);
						}
						stk[i].pop();
					}
					if (!level.empty())
						results.push_back(level);
				}
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
	
	vector<vector<int>> results = solution.zigzagLevelOrder(root);
	for (auto a : results) {
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}

	delete root->left, root->right, root;
	root = NULL;

	return 0;
}