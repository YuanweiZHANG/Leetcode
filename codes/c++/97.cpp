#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
* 2020-04-15
* Veronica
*/
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s3.size() != s1.size() + s2.size())
			return false;
		vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
		
		dp[0][0] = true;

		for (int i = 0; i < s1.size(); ++i)
			dp[i + 1][0] = dp[i][0] && (s1[i] == s3[i]);

		for (int i = 0; i < s2.size(); ++i)
			dp[0][i + 1] = dp[0][i] && (s2[i] == s3[i]);

		for (int i = 0; i < s1.size(); ++i) {
			for (int j = 0; j < s2.size(); ++j) {
				dp[i + 1][j + 1] = ((dp[i][j + 1] && (s1[i] == s3[i + j + 1])) || (dp[i + 1][j] && (s2[j] == s3[i + j + 1])));
			}
		}
		return dp[s1.size()][s2.size()];
	}
	
};

int main() {
	Solution solution;

	string s1 = "db", s2 = "b", s3 = "cbb";
	cout << solution.isInterleave(s1, s2, s3) << endl;

	return 0;
}