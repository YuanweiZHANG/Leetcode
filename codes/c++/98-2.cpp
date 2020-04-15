#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
* 2020-04-15
* Veronica
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (!root)
			return true;
		stack<pair<TreeNode*, int/*processTimes*/>> stk;
		stk.push(make_pair(root, 0));
		vector<int> nums;
		while (!stk.empty()) {
			TreeNode* curr = stk.top().first;
			int processTimes = stk.top().second;
			if (processTimes == 0) { // first time in the stack
				stk.pop();
				stk.push(make_pair(curr, 1));
				if (curr->left)
					stk.push(make_pair(curr->left, 0));
			}
			else {
				stk.pop();
				nums.push_back(curr->val);
				if (curr->right)
					stk.push(make_pair(curr->right, 0));
			}
		}
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i - 1] >= nums[i])
				return false;
		}
		return true;
	}
};

int main() {
	Solution solution;

	TreeNode* root = NULL;
	cout << solution.isValidBST(root) << endl;

	return 0;
}