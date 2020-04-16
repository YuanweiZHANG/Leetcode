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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p && !q)
			return true;
		if (!p || !q)
			return false;
		if (p->val != q->val)
			return false;
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};

int main() {
	Solution solution;

	TreeNode* p = NULL, *q = NULL;
	cout << solution.isSameTree(p, q) << endl;

	return 0;
}