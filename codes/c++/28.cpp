#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
* 2020-04-01
* Veronica
*/
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle == "")
			return 0;
		int len_haystack = haystack.size();
		int len_needle = needle.size();
		vector<int> next = getNext(needle);
		int i = 0, j = 0;
		while (i < len_haystack &&j < len_needle) {
			if (j == -1 || haystack[i] == needle[j]) {
				i++;
				j++;
			}
			else {
				j = next[j];
			}
		}
		if (j == len_needle) {
			return i - j;
		}
		else
			return -1;

	}
	vector<int> getNext(string needle) {
		int len = needle.size();
		vector<int> next(len);
		int i = 0, k = -1;
		next[0] = k;
		while (i < len - 1) {
			if (k == -1 || needle[i] == needle[k]) {
				i++;
				k++;
				next[i] = k;
			}
			else
				k = next[k];
		}
		return next;
	}
};

int main() {
	Solution solution;

	string haystack = "hello", needle = "ll";
	cout << solution.strStr(haystack, needle);

	return 0;
}