#include <iostream>
#include <map>
#include <vector>
using namespace std;

/**
* 2020-05-04
* Veronica
*/
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution {
public:
	Node * copyRandomList(Node* head) {
		if (!head)
			return NULL;
		Node* newHead = new Node(head->val);
		map<Node*, Node*> mp;
		mp[NULL] = NULL; // trick
		mp[head] = newHead;
		Node* p = head;
		while (p) {
			if (mp.find(p->next) == mp.end())
				mp[p->next] = new Node(p->next->val);
			if (mp.find(p->random) == mp.end())
				mp[p->random] = new Node(p->random->val);
			mp[p]->next = mp[p->next];
			mp[p]->random = mp[p->random];
			p = p->next;
		}
		return newHead;
	}
};

void printNodes(Node* head) {
	map<Node*, int/*index*/> mp;
	Node* p = head;
	int index = 0;
	while (p) {
		mp[p] = index++;
		p = p->next;
	}
	p = head;
	while (p) {
		cout << p->val << ",";
		if (p->random)
			cout << mp[p->random];
		else
			cout << "null";
		cout << "  ";
		p = p->next;
	}
	cout << endl;
}

Node* createNodes(vector<vector<int>> lists) {
	vector<Node*> nodes(lists.size() + 1, NULL);
	for (int i = 0; i < lists.size(); ++i) {
		nodes[i] = new Node(lists[i][0]);
	}
	for (int i = 0; i < lists.size(); ++i) {
		if (lists[i][1] == -1)
			nodes[i]->random = NULL;
		else
			nodes[i]->random = nodes[lists[i][1]];
		nodes[i]->next = nodes[i + 1];
	}
	return nodes[0];
}

void deleteNodes(Node* head) {
	Node* del = head;
	while (head) {
		del = head;
		head = head->next;
		delete del;
	}
}

int main() {
	Solution solution;

	vector<vector<int>> lists = { {7,-1},{13,0},{11,4},{10,2},{1,0} };
	Node* head = createNodes(lists);
	printNodes(head);
	Node* newHead = solution.copyRandomList(head);
	printNodes(newHead);

	deleteNodes(head);
	head = NULL;
	deleteNodes(newHead);
	newHead = NULL;

	return 0;
}