#include <iostream>
#include <algorithm>
using namespace std;

/**
* 2020-04-11
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
	int diameterOfBinaryTree(TreeNode* root) {
		int diameter = 0;
		depth(root, diameter);
		return diameter;
	}
	int depth(TreeNode* root, int& diameter) {
		if (!root) {
			diameter = 0;
			return 0;
		}
		else {
			int diameterLeft = 0, diameterRight = 0;
			int depthLeft = depth(root->left, diameterLeft);
			int depthRight = depth(root->right, diameterRight);
			diameter = max(max(diameterLeft, diameterRight), depthLeft + depthRight);
			return max(depthLeft, depthRight) + 1;
		}
	}
};

int main() {
	Solution solution;

	TreeNode *head = new TreeNode(1);
	cout << solution.diameterOfBinaryTree(head) << endl;
	delete head;

	return 0;
}
