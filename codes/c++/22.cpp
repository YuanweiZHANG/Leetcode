#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 2020-03-30
 * Veronica
 */
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> results;
		string curr;
		generateParenthesisCore(results, 0, 0, n, curr);
		return results;
	}
	void generateParenthesisCore(vector<string> &results, int left, int right, int n, string & curr) {
		if (left == n && right == n) {
			results.push_back(curr);
			return;
		}
		if (left < n) {
			curr.push_back('(');
			generateParenthesisCore(results, left + 1, right, n, curr);
			curr.pop_back();
		}
		if (left > right) {
			curr.push_back(')');
			generateParenthesisCore(results, left, right + 1, n, curr);
			curr.pop_back();
		}
		return;

	}
};

int main() {
	Solution solution;

	int n = 3;
	vector<string> results = solution.generateParenthesis(n);
	for (auto str : results) {
		cout << str << endl;
	}
	return 0;
}
