#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
* 2020-05-11
* Veronica
*/
class Solution {
public:
	string reverseWords(string s) {
		int start = 0, end = 1, n = s.size();
		vector<string> words;
		while (start < n) {
			while (start < n && s[start] == ' ')
				start++;
			if (start == n)
				break;
			end = start + 1;
			while (end < n && s[end] != ' ')
				end++;
			words.push_back(s.substr(start, end - start));
			start = end + 1;
		}
		if (words.empty())
			return "";
		string result = *words.rbegin();
		for (int i = words.size() - 2; i >= 0; --i) {
			result.push_back(' ');
			result.append(words[i]);
		}
		return result;
	}
};

int main() {
	Solution solution;

	vector<string> input = { "","the sky is blue","  hello world!  ","a good   example" };
	for (auto s : input) {
		cout << s << endl;
		cout << solution.reverseWords(s) << endl;
	}

	return 0;
}