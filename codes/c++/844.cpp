#include <iostream>
#include <string>
using namespace std;

/**
* 2020-04-09
* Veronica
*/

class Solution {
public:
	bool backspaceCompare(string S, string T) {
		int len_s = S.size(), len_t = T.size();
		int curr_s = 0, curr_t = 0;
		for (int i = 0; i < len_s; ++i) {
			if (S[i] != '#') {
				S[curr_s++] = S[i];
			}
			else {
				if (curr_s != 0) {
					curr_s--;
				}
			}
		}
		for (int i = 0; i < len_t; ++i) {
			if (T[i] != '#') {
				T[curr_t++] = T[i];
			}
			else {
				if (curr_t != 0) {
					curr_t--;
				}
			}
		}
		if (curr_s != curr_t)
			return false;
		else {
			for (int i = 0; i < curr_s; ++i) {
				if (S[i] != T[i])
					return false;
			}
			return true;
		}
	}
};

int main() {
	Solution solution;

	string S = "a#c", T = "b";
	cout << solution.backspaceCompare(S, T) << endl;
	
	return 0;
}