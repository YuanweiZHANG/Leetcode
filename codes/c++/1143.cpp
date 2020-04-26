#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/**
* 2020-04-26
* Veronica
*/
class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		if (text1 == "" || text2 == "")
			return 0;
		int len1 = text1.size(), len2 = text2.size();
		vector<vector<int>> dp(len1, vector<int>(len2, 0));
		dp[0][0] = (text1[0] == text2[0]);
		for (int i = 1; i < len1; ++i) {
			if (text1[i] == text2[0])
				dp[i][0] = 1;
			else
				dp[i][0] = max(dp[i - 1][0], 0);
		}
		for (int i = 1; i < len2; ++i) {
			if (text1[0] == text2[i])
				dp[0][i] = 1;
			else
				dp[0][i] = max(dp[0][i - 1], 0);
		}
		for (int i = 1; i < len1; ++i) {
			for (int j = 1; j < len2; ++j) {
				if (text1[i] == text2[j])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[len1 - 1][len2 - 1];
	}
};

int main() {
	Solution solution;

	string text1 = "abcde", text2 = "ace";
	cout << solution.longestCommonSubsequence(text1, text2) << endl;
	
	return 0;
}