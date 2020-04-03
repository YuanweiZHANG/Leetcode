#include <iostream>
#include <string>
using namespace std;

/**
* 2020-04-03
* Veronica
*/
class Solution {
public:
	string countAndSay(int n) {
		string result = "1";
		if ((n--) == 1)
			return result;
		while (n--) {
			int len = result.size();
			if (len == 1)
				result = "11";
			else {
				int num = 1;
				string temp = "";
				for (int i = 1; i < len; ++i) {
					if (result[i] != result[i - 1]) {
						temp.push_back((num + '0'));
						temp.push_back(result[i - 1]);
						num = 1;
					}
					else
						num++;
				}
				temp.push_back((num + '0'));
				temp.push_back(result[len - 1]);
				result = temp;
			}
		}
		return result;
	}
};

int main() {
	Solution solution;

	int n = 6;
	cout << solution.countAndSay(n) << endl;

	return 0;
}