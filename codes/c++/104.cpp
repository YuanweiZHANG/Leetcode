#include <iostream>
#include <vector>
#include <algorithm>
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
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};

int main() {
	Solution solution;

	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	
	cout << solution.maxDepth(root) << endl;

	delete root->left, root->right, root;
	root = NULL;

	return 0;
}