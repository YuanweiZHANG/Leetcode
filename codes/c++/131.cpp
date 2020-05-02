#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
* 2020-05-02
* Veronica
*/
class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> results;
		vector<string> curr;
		if (s.empty())
			return results;
		partitionCore(s, 0, results, curr);
		return results;
	}
	
	void partitionCore(string s, int start, vector<vector<string>>& results, vector<string>& curr) {
		if (start == s.size()) {
			results.push_back(curr);
			return;
		}
		for (int i = start; i < s.size(); ++i) {
			if (isPalindrome(s, start, i)) {
				curr.push_back(s.substr(start, i - start + 1));
				partitionCore(s, i + 1, results, curr);
				curr.pop_back();
			}
		}
	}

	bool isPalindrome(string s, int start, int end) {
		while (start <= end) {
			if (s[start++] != s[end--])
				return false;
		}
		return true;
	}
};

int main() {
	Solution solution;

	string s = "aab";
	vector<vector<string>> results = solution.partition(s);
	for (auto a : results) {
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}

	return 0;
}