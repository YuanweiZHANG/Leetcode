#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
* 2020-04-10
* Veronica
*/
class Solution {
public:
	bool isNumber(string s) {
		int len = s.size();
		bool exponent = false, decimal = false, number = false;
		int start = 0;
		while (start < len && s[start] == ' ') {
			start++;
		}
		while (len > 0 && s[len - 1] == ' ') {
			len--;
		}
		for (int i = start; i < len; ++i) {
			if (s[i] >= '0'&&s[i] <= '9') {
				number = true;
			}
			else if (s[i] == '+' || s[i] == '-') {
				if ((i != start && s[i - 1] != 'e') || i == len - 1)
					return false;
			}
			else if (s[i] == '.') {
				if (decimal)
					return false;
				else
					decimal = true;
			}
			else if (s[i] == 'e') {
				if (i == len - 1 || !number || exponent)
					return false;
				decimal = true;
				exponent = true;
			}
			else
				return false;
		}
		return number;
	}
};

int main() {
	Solution solution;

	vector<string> strs = { "0","0.1","abc","1 a","2e10","-90e3","1e","e3","6e-1","99e2.5","53.5e93","--6","-+3","95a54e53","+90.2e2.2",".0","1.",".","e","1 ",". 1","4e+","0e "," "," -54.53061" };
	for (auto s : strs) {
		cout << s << " " << solution.isNumber(s) << endl;
	}

	return 0;
}
