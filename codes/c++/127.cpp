#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/**
* 2020-04-26
* Veronica
*/
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if (wordList.empty())
			return 0;
		unordered_map<string, bool> paths;
		for (auto word : wordList)
			paths[word] = true;
		queue<pair<string, int/*steps*/>> que;
		que.push({ beginWord, 1 });
		while (!que.empty()) {
			string curr = que.front().first;
			int steps = que.front().second;
			if (curr == endWord)
				return steps;
			for (int i = 0; i < curr.size(); ++i) {
				string s = curr;
				for (int j = 0; j < 26; ++j) {
					s[i] = j + 'a';
					if (paths.find(s) != paths.end() && paths[s]) {
						que.push({ s, steps + 1 });
						paths[s] = false;
					}
				}
			}
			que.pop();
		}
		return 0; // not found
	}
};

int main() {
	Solution solution;

	string beginWord = "hit", endWord = "cog";
	vector<string> wordList = { "hot","dot","dog","lot","log","cog" };
	cout << solution.ladderLength(beginWord, endWord, wordList) << endl;
	
	return 0;
}