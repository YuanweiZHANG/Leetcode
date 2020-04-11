#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**
* 2020-04-11
* Veronica
*/
class Solution {
public:
	int minDistance(string word1, string word2) {
		int len1 = word1.size(), len2 = word2.size();
		vector<vector<int>> distance(len1 + 1, vector<int>(len2 + 1, 0));
		for (int i = 0; i <= len1; ++i) {
			for (int j = 0; j <= len2; ++j) {
				if (i == 0)
					distance[i][j] = j;
				else if (j == 0)
					distance[i][j] = i;
				else if (word1[i - 1] == word2[j - 1]) {
					distance[i][j] = distance[i - 1][j - 1];
				}
				else
					distance[i][j] = min(min(distance[i - 1][j], distance[i][j - 1]), distance[i - 1][j - 1]) + 1;
			}
		}
		return distance[len1][len2];
	}
};

int main() {
	Solution solution;

	string word1 = "pneumonoultramicroscopicsilicovolcanoconiosis", word2 = "ultramicroscopically";
	//string word1 = "a", word2 = "aab";
	cout << solution.minDistance(word1, word2) << endl;

	return 0;
}
