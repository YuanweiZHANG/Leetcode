#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

/**
* 2020-05-11
* Veronica
*/
class Solution {
public:
	string reverseWords(string s) {
		reverse(s.begin(), s.end());
		stringstream input(s);
		string word;
		input >> word;
		reverse(word.begin(), word.end());
		string result = word;
		while (input >> word) {
			reverse(word.begin(), word.end());
			result.push_back(' ');
			result.append(word);
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