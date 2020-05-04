#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
* 2020-05-04
* Veronica
*/
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		vector<int> letters(26, 0);
		for (auto letter : magazine) {
			letters[letter - 'a']++;
		}
		for (auto letter : ransomNote) {
			if (letters[letter - 'a']-- == 0)
				return false;
		}
		return true;
	}
};

int main() {
	Solution solution;

	string ransomNote = "aa", magazine = "aab";
	cout << solution.canConstruct(ransomNote, magazine) << endl;

	return 0;
}