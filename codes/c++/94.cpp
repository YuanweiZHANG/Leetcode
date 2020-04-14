#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
* 2020-04-14
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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> results;
		if (!root)
			return results;
		stack<pair<TreeNode*, int/*process times*/>> stk;
		stk.push(make_pair(root, 0));
		while (!stk.empty()) {
			TreeNode *curr = stk.top().first;
			int processTimes = stk.top().second;
			if (processTimes == 0) {
				stk.pop();
				stk.push(make_pair(curr, processTimes + 1));
				if (curr->left) {
					stk.push(make_pair(curr->left,0));
				}
			}
			else {
				results.push_back(curr->val);
				stk.pop();
				if (curr->right) {
					stk.push(make_pair(curr->right,0));
				}
			}
		}
		return results;
	}
};

int main() {
	Solution solution;

	TreeNode* root = NULL;
	vector<int> results = solution.inorderTraversal(root);
	for (auto result : results)
		cout << result << " ";

	return 0;
}