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
	void recoverTree(TreeNode* root) {
		if (!root)
			return;
		stack<pair<TreeNode*, int>> stk;
		vector<TreeNode*> bst;
		stk.push(make_pair(root, 0));
		while (!stk.empty()) {
			TreeNode* curr = stk.top().first;
			int processTimes = stk.top().second;
			stk.pop();
			if (processTimes == 0) {
				stk.push(make_pair(curr, 1));
				if (curr->left)
					stk.push(make_pair(curr->left, 0));
			}
			else {
				bst.push_back(curr);
				if (curr->right)
					stk.push(make_pair(curr->right, 0));
			}
		}
		int n = bst.size();
		int first = 0, second = 0;
		for (first = 0; first < n - 1; ++first) {
			if (bst[first]->val > bst[first + 1]->val)
				break;
		}
		for (second = first; second < n - 1; second++) {
			if (bst[second + 1]->val > bst[first]->val)
				break;
		}
		int tempVal = bst[first]->val;
		bst[first]->val = bst[second]->val;
		bst[second]->val = tempVal;
		return;
	}
};

int main() {
	Solution solution;

	TreeNode* root = NULL;
	solution.recoverTree(root);

	return 0;
}