#include <iostream>
#include <string>
using namespace std;

/**
* 2020-04-09
* Veronica
*/
class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = s.size();
		int length_last = 0;
		for (int i = len - 1; i >= 0; --i) {
			if (s[i] == ' ') {
				if (length_last == 0)
					continue;
				else break;
			}
			length_last++;
		}
		return length_last;
	}
};

int main() {
	Solution solution;

	//string s = "Hello World";
	//string s = "  ";
	string s = "all";
	cout << solution.lengthOfLastWord(s) << endl;
	
	return 0;
}