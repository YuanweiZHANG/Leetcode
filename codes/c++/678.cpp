#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
* 2020-04-16
* Veronica
*/
class Solution {
public:
	bool checkValidString(string s) {
		if (s == "")
			return true;
		int n = s.size();
		vector<vector<bool>> dp(n, vector<bool>(n, false));
		for (int i = 0; i < n; ++i) {
			if (s[i] == '*')
				dp[i][i] = true;
			if (i < n - 1 && (s[i] == '(' || s[i] == '*') && (s[i + 1] == ')' || s[i + 1] == '*'))
				dp[i][i + 1] = true;
		}
		for (int k = 2; k < n; ++k) {
			for (int i = 0; i < n - k; ++i) {
				if (s[i] == '*' && dp[i + 1][i + k])
					dp[i][i + k] = true;
				else if (s[i] == '(' || s[i] == '*') {
					for (int j = i + 1; j <= i + k; ++j) {
						if (s[j] == ')' || s[j] == '*') {
							if (j == i + 1) {
								if (dp[j + 1][i + k])
									dp[i][i + k] = true;
							}
							else if (j == i + k) {
								if (dp[i + 1][j - 1])
									dp[i][i + k] = true;
							}
							else {
								if (dp[i + 1][j - 1] && dp[j + 1][i + k])
									dp[i][i + k] = true;
							}
						}
					}
				}
			}
		}
		return dp[0][n - 1];
	}
};

int main() {
	Solution solution;

	string s = "()";
	cout << solution.checkValidString(s) << endl;

	return 0;
}