#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-05-10
* Veronica
*/
class Solution {
public:
	int findJudge(int N, vector<vector<int>>& trust) {
		vector<int> trusted(N + 1, 0);
		for (auto t : trust) {
			trusted[t[0]] = -1;
			if (trusted[t[1]] == -1)
				continue;
			trusted[t[1]]++;
		}
		for (int i = 1; i <= N; ++i) {
			if (trusted[i] == N - 1)
				return i;
		}
		return -1;
	}
};

int main() {
	Solution solution;

	int N = 4;
	vector<vector<int>> trust = { {1,3},{1,4},{2,3},{2,4},{4,3} };
	cout << solution.findJudge(N, trust) << endl;

	return 0;
}