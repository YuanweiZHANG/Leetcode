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
	bool isSymmetric(TreeNode* root) {
		if (!root)
			return true;
		return isSymmetricCore(root->left, root->right);
	}
	bool isSymmetricCore(TreeNode* p, TreeNode* q) {
		if (!p && !q)
			return true;
		if (!p || !q || p->val != q->val)
			return false;
		return isSymmetricCore(p->left, q->right) && isSymmetricCore(p->right, q->left);
	}
};

int main() {
	Solution solution;

	TreeNode* root = NULL;
	cout << solution.isSymmetric(root) << endl;

	return 0;
}