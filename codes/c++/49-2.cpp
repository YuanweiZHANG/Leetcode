#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/**
* 2020-04-05
* Veronica
*/
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> mp;
		int len = strs.size();
		for (auto str : strs) {
			string key = str;
			sort(key.begin(), key.end());
			mp[key].push_back(str);
		}
		vector<vector<string>> result;
		for (auto it : mp) {
			result.push_back(it.second);
		}
		return result;
	}
};

int main() {
	Solution solution;

	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> results = solution.groupAnagrams(strs);
	for (auto a : results) {
		for (auto b : a) {
			cout << b << ' ';
		}
		cout << endl;
	}

	return 0;
}