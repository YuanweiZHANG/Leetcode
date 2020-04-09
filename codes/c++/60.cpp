#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
* 2020-04-09
* Veronica
*/
class Solution {
public:
	string getPermutation(int n, int k) {
		vector<bool> used(n, false);
		vector<int> factorial(n, 1);
		for (int i = 2; i < n; ++i) {
			factorial[n - i - 1] = factorial[n - i] * i;
		}
		string result;
		k--;
		for (int i = 0; i < n; ++i) {
			int num = k / factorial[i];
			k %= factorial[i];
			int index = 0;
			while (used[index]) {
				index++;
			}
			while (num) {
				if (!used[index++])
					num--;
			}
			while (used[index]) {
				index++;
			}
			result.push_back('1' + index);
			used[index] = true;
		}
		return result;
	}
};

int main() {
	Solution solution;

	//int n = 8, k = 15198;
	int n = 9, k = 161191;
	cout << solution.getPermutation(n, k) << endl;
		
	return 0;
}