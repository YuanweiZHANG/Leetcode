#include <iostream>
#include <string>
using namespace std;

/**
* 2020-04-10
* Veronica
*/
class Solution {
public:
	string addBinary(string a, string b) {
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		string result;
		int len_a = a.size(), len_b = b.size();
		if (len_b > len_a) {
			swap(a, b);
			swap(len_a, len_b);
		}
		for (int i = 0; i < len_b; ++i) {
			a[i] += b[i] - '0';
		}
		for (int i = 0; i < len_a; ++i) {
			if (a[i] > '1') {
				a[i] -= 2;
				if (i < len_a - 1)
					a[i + 1] += 1;
				else
					a.push_back('1');
			}
		}
		reverse(a.begin(), a.end());
		return a;
	}
};

int main() {
	Solution solution;

	string a = "1", b = "111";
	cout << solution.addBinary(a, b) << endl;

	return 0;
}
