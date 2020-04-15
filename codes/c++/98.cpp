#include <iostream>
#include <vector>
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

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return isVaildBSTCore(root)[0];
	}
	vector<int> isVaildBSTCore(TreeNode * root) {
		if (!root)
			return { true, 0, 0 };
		int smallest = root->val;
		int biggest = root->val;
		if (root->left) {
			vector<int> result = isVaildBSTCore(root->left);
			if (!result[0] || result[2] >= root->val)
				return { false, smallest, biggest };
			smallest = result[1];
		}
		if (root->right) {
			vector<int> result = isVaildBSTCore(root->right);
			if (!result[0] || result[1] <= root->val)
				return { false, smallest, biggest };
			biggest = result[2];
		}
		return { true, smallest, biggest };
	}
};

int main() {
	Solution solution;

	TreeNode* root = NULL;
	cout << solution.isValidBST(root) << endl;

	return 0;
}