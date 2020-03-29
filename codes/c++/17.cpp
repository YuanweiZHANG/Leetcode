#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

/**
 * 2020-03-29
 * Veronica
 */
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		int len = digits.size();
		vector<string> results;
		string result;
		stack<pair<char, int>> stk;
		for (int i = 0; i < len; ++i) {
			char letter = nextLetter(digits[i] - '0', '\0');
			stk.push(make_pair(letter, i));
			result.push_back(letter);
		}
		while (!stk.empty()) {
			pair<char, int> p = stk.top();
			char next = 0;
			if (p.second == len - 1) {
				results.push_back(result);
				stk.pop();
				result.pop_back();
				next = nextLetter(p.second, p.first);
				while (next == '\0') {
					if (p.second == 0) {
						return results;
					}
					p = stk.top();
					stk.pop();
					result.pop_back();
					next = nextLetter(p.second, p.first);
				}
				stk.push(make_pair(next, p.second));
				result.push_back(next);
			}
			else {
				next = nextLetter(digits[p.second + 1] - '0', '\0');
				stk.push(make_pair(next, p.second + 1));
				result.push_back(next);
			}
		}
		return results;
	}
	char nextLetter(int digit, char curr_letter) {
		if (curr_letter == '\0') {
			switch (digit) {
			case 2:
				return 'a';
			case 3:
				return 'd';
			case 4:
				return 'g';
			case 5:
				return 'j';
			case 6:
				return 'm';
			case 7:
				return 'p';
			case 8:
				return 't';
			case 9:
				return 'w';
			}
		}
		switch (curr_letter) {
		case 'c':
		case 'f':
		case 'i':
		case 'l':
		case 'o':
		case 's':
		case 'v':
		case 'z':
			return '\0';
		default:
			return curr_letter + 1;
		}
	}
};


int main() {
	Solution solution;

	string digits = "232";

	vector<string> results = solution.letterCombinations(digits);
	for (auto str : results) {
		cout << str << endl;
	}

	return 0;
}