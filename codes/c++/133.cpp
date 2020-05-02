#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

/**
* 2020-05-02
* Veronica
*/
class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}

	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution {
public:
	Node * cloneGraph(Node* node) {
		if (!node)
			return NULL;
		map<Node*, Node*> mp;
		queue<Node*> que;
		Node* newNode = new Node(node->val);
		mp[node] = newNode;
		que.push(node);
		while (!que.empty()) {
			Node* curr = que.front();
			for (auto neighbor : curr->neighbors) {
				if (mp.find(neighbor) == mp.end()) {
					mp[neighbor] = new Node(neighbor->val);
					que.push(neighbor);
				}
				mp[curr]->neighbors.push_back(mp[neighbor]);
			}
			que.pop();
		}
		return newNode;
	}
};

Node* createGraph(vector<vector<int>> adjList) {
	vector<Node*> nodes(adjList.size(), NULL);
	for (int i = 0; i < adjList.size(); ++i)
		nodes[i] = new Node(i + 1);
	for (int i = 0; i < adjList.size(); ++i) {
		for (auto node : adjList[i]) {
			nodes[i]->neighbors.push_back(nodes[node - 1]);
		}
	}
	if (adjList.empty())
		return NULL;
	else
		return nodes[0];
}

void printGraph(Node* node) {
	set<Node*> nodes;
	queue<Node*> que;
	nodes.insert(node);
	que.push(node);
	while (!que.empty()) {
		Node* curr = que.front();
		cout << curr->val << ": ";
		for (auto item : curr->neighbors) {
			cout << item->val << " ";
			if (nodes.find(item) == nodes.end()) {
				nodes.insert(item);
				que.push(item);
			}
		}
		cout << endl;
		que.pop();
	}
}

void deleteGraph(Node*& node) {
	if (!node)
		return;
	set<Node*> nodes;
	queue<Node*> que;
	que.push(node);
	nodes.insert(node);
	while (!que.empty()) {
		Node* curr = que.front();
		for (auto neighbor : curr->neighbors) {
			if (nodes.find(neighbor) == nodes.end()) {
				que.push(neighbor);
				nodes.insert(neighbor);
			}
		}
		delete(curr);
		que.pop();
	}
	node = NULL;
}

int main() {
	Solution solution;

	vector<vector<int>> adjList = { {2,4},{1,3},{2,4},{1,3} };
	Node* node = createGraph(adjList);
	Node* newNode = solution.cloneGraph(node);
	printGraph(newNode);

	deleteGraph(node);
	deleteGraph(newNode);

	return 0;
}