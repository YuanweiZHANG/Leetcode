#include <iostream>
#include <string>
using namespace std;

/**
* 2020-04-05
* Veronica
*/
class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "" || num2 == "")
			return "";
		string result = "0";
		int len1 = num1.size(), len2 = num2.size();
		for (int i = len2 - 1; i >= 0; --i) {
			string mul = multiply(num1, num2[i] - '0');
			for (int j = i; j < len2 - 1; ++j) {
				mul.push_back('0');
			}
			result = add(result, mul);
		}
		int first_none_zero = 0, len = result.size();
		for (int i = 0; i < len - 1; ++i) {
			if (result[i] == '0') {
				first_none_zero++;
			}
			else
				break;
		}
		return result.substr(first_none_zero, len - first_none_zero);
	}

	string multiply(string num1, int num2) {
		reverse(num1.begin(), num1.end());

		int len = num1.size();
		for (int i = 0; i < len; ++i) {
			num1[i] = (num1[i] - '0') * num2; // store as int
		}
		for (int i = 0; i < len - 1; ++i) {
			if (num1[i] > 9) {
				num1[i + 1] += num1[i] / 10;
				num1[i] = num1[i] % 10 + '0';
			}
			else
				num1[i] += '0';
		}
		if (num1[len - 1] > 9) {
			num1.push_back(num1[len - 1] / 10 + '0');
			num1[len - 1] = num1[len - 1] % 10 + '0';
		}
		else
			num1[len - 1] += '0';
		reverse(num1.begin(), num1.end());
		return num1;
	}

	string add(string num1, string num2) {
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		int len1 = num1.size(), len2 = num2.size();
		string result = num1;
		if (len1 < len2) {
			result = num2;
			num2 = num1;
			swap(len1, len2);
		}
		int i = 0, j = 0;
		while (i <len2) {
			result[i] += (num2[i] - '0');
			if (result[i] - '0' > 9) {
				result[i] -= 10;
				if (i < result.size() - 1) {
					result[i + 1]++;
				}
				else {
					result.push_back('1');
				}
			}
			i++;
		}
		len1 = result.size();
		for (i = len2; i < len1 - 1; ++i) {
			if (result[i] - '0' > 9) {
				result[i] -= 10;
				result[i + 1]++;
			}
		}
		if (result[len1 - 1] - '0' > 9) {
			result[len1 - 1] -= 10;
			result.push_back('1');
		}
		reverse(result.begin(), result.end());
		return result;
	}
};

int main() {
	Solution solution;

	string num1 = "9", num2 = "9";
	cout << solution.multiply(num1, num2) << endl;

	return 0;
}