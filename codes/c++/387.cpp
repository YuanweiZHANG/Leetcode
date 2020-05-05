#include <iostream>
#include <map>
#include <string>
using namespace std;

/**
* 2020-05-05
* Veronica
*/
class Solution {
public:
	int firstUniqChar(string s) {
		if (s == "")
			return -1;
		map<char, int> mp;
		for (auto c : s) {
			mp[c]++;
		}
		for (int i = 0; i < s.size(); ++i) {
			if (mp[s[i]] == 1)
				return i;
		}
		return -1;
	}
};

int main() {
	Solution solution;

	string s = "loveleetcode";
	cout << solution.firstUniqChar(s) << endl;

	return 0;
}