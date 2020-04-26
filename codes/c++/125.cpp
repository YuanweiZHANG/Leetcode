#include <iostream>
#include <string>
using namespace std;

/**
* 2020-04-25
* Veronica
*/
class Solution {
public:
	bool isPalindrome(string s) {
		int left = 0, right = s.size() - 1;
		while (left <= right) {
			if ('A' <= s[left] && s[left] <= 'Z')
				s[left] = s[left] - 'A' + 'a';
			else if (!('0' <= s[left] && s[left] <= '9') && !('a' <= s[left] && s[left] <= 'z')) {
				left++;
				continue;
			}
			if ('A' <= s[right] && s[right] <= 'Z')
				s[right] = s[right] - 'A' + 'a';
			else if (!('0' <= s[right] && s[right] <= '9') && !('a' <= s[right] && s[right] <= 'z')) {
				right--;
				continue;
			}
			if (s[left] != s[right])
				return false;
			left++;
			right--;
		}
		return true;
	}
};

int main() {
	Solution solution;

	string s = "p0";
	cout << solution.isPalindrome(s) << endl;
	
	return 0;
}