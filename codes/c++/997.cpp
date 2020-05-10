#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
* 2020-05-10
* Veronica
*/
class Solution {
public:
	int findJudge(int N, vector<vector<int>>& trust) {
		if (N == 1 && trust.empty())
			return 1;
		map<int/*people*/, int/*trust number*/> mp;
		for (auto t : trust) {
			mp[t[0]] = -1;
			if (mp.find(t[1]) != mp.end() && mp[t[1]] == -1)
				continue;
			mp[t[1]]++;
		}
		for (auto p : mp) {
			if (p.second == N - 1)
				return p.first;
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