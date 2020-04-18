#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
* 2020-04-18
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
	TreeNode * sortedArrayToBST(vector<int>& nums) {
		return sortedArrayToBSTCore(nums, 0, nums.size() - 1);
	}
	TreeNode *sortedArrayToBSTCore(vector<int>& nums, int left, int right) {
		if (left > right)
			return NULL;
		int mid = (left + right) >> 1;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = sortedArrayToBSTCore(nums, left, mid - 1);
		root->right = sortedArrayToBSTCore(nums, mid + 1, right);
		return root;
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

	vector<int> nums = { -10,-3,0,5,9 };
	TreeNode* root = solution.sortedArrayToBST(nums);
	printTree(root);

	deleteTree(root);

	return 0;
}