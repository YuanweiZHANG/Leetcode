#include <iostream>
#include <queue>
using namespace std;

/**
* 2020-04-22
* Veronica
*/
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
	Node * connect(Node* root) {
		if (!root)
			return root;
		root->next = NULL;
		vector<queue<Node*>> que(2);
		que[0].push(root);
		while (!que[0].empty() || !que[1].empty()) {
			for (int i = 0; i < 2; ++i) {
				if (!que[i].empty()) {
					while (!que[i].empty()) {
						Node* curr = que[i].front();
						que[i].pop();
						if (curr->left) {
							que[1 - i].push(curr->left);
							que[1 - i].push(curr->right);
						}
						if (!que[i].empty())
							curr->next = que[i].front();
						else
							curr->next = NULL;
					}
				}
			}
		}
		return root;
	}
};

int main() {
	Solution solution;

	Node* root = NULL;
	root = solution.connect(root);

	return 0;
}