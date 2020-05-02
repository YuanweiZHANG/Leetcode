#include <iostream>
#include <string>
using namespace std;

/**
* 2020-05-02
* Veronica
*/
class Solution {
public:
	int numJewelsInStones(string J, string S) {
		bool jewels[128] = { false };
		for (int i = 0; i < J.size(); ++i) {
			jewels[J[i]] = true;
		}
		int num = 0;
		for (int i = 0; i < S.size(); ++i) {
			if (jewels[S[i]])
				num++;
		}
		return num;
	}
};

int main() {
	Solution solution;

	string J = "aA", S = "aAAbbbb";
	cout << solution.numJewelsInStones(J, S) << endl;

	return 0;
}