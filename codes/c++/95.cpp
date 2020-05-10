#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
* 2020-05-09
* Veronica
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0)
			return {};
		return generateTreesCore(1, n);
	}

	vector<TreeNode*> generateTreesCore(int start, int end) {
		if (start > end)
			return { NULL };
		vector<TreeNode*> roots;
		for (int i = start; i <= end; ++i) {
			vector<TreeNode*> lefts = generateTreesCore(start, i - 1);
			vector<TreeNode*> rights = generateTreesCore(i + 1, end);
			for (auto left : lefts) {
				for (auto right : rights) {
					TreeNode *root = new TreeNode(i);
					root->left = left;
					root->right = right;
					roots.push_back(root);
				}
			}
		}
		return roots;
	}
};

void printTree(TreeNode* root) {
	if (!root) {
		cout << "null" << " ";
		return;
	}
	queue<TreeNode*> que;
	que.push(root);
	while (!que.empty()) {
		TreeNode* curr = que.front();
		if (curr == NULL)
			cout << "null ";
		else {
			cout << curr->val << " ";
			que.push(curr->left);
			que.push(curr->right);
		}
		que.pop();
	}
}

void deleteTree(TreeNode* root) {
	if (!root)
		return;
	queue<TreeNode*> que;
	que.push(root);
	while (!que.empty()) {
		TreeNode* curr = que.front();
		if (curr->left)
			que.push(curr->left);
		if (curr->right)
			que.push(curr->right);
		que.pop();
		curr->left = curr->right = NULL;
		delete curr;
	}
	root = NULL;
}

int main() {
	Solution solution;

	int n = 3;
	vector<TreeNode*> results = solution.generateTrees(n);
	for (auto root : results) {
		printTree(root);
		cout << endl;
		deleteTree(root);
	}

	return 0;
}