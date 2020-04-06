#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
* 2020-04-05
* Veronica
*/
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<string> signals;
		vector<vector<string>> result;
		for (auto str : strs) {
			string signal(26, '0');
			int len = str.size();
			for (int i = 0; i < len; ++i) {
				signal[str[i] - 'a']++;
			}
			int groups = signals.size(), i = 0;
			for (i = 0; i < groups; ++i) {
				if (signals[i] == signal) {
					result[i].push_back(str);
					break;
				}
			}
			if (i == groups) {
				signals.push_back(signal);
				result.push_back({ str });
			}
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