## 93. [Restore IP Addresses](https://leetcode.com/problems/restore-ip-addresses/)

> Medium

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

**Example:**

```
Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
```



**Solutions:**

Remember, we cannot restore IP as `01.01.01.01`. Therefore, when `s` starts as `0`, let `0` be a single part of IP.

Here is my solution class:

```c++
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> results;
		string curr;
		restoreIpAddressesCore(s, results, curr, 4);
		return results;
	}
	void restoreIpAddressesCore(string s, vector<string>& results, string& curr, int rest) {
		if (rest == 0) {
			if (s == "") {
				curr.pop_back();
				results.push_back(curr);
				curr.push_back('.');
			}
			return;
		}
		if (s.size() > 3 * rest)
			return;
		int num = 0;
		if (s[0] == '0') {
			curr.append("0.");
			restoreIpAddressesCore(s.substr(1), results, curr, rest - 1);
			curr.pop_back();
			curr.pop_back();
			return;
		}
		for (int i = 0; i < 3 && i < s.size(); ++i) {
			num += s[i] - '0';
			if (num > 255)
				return;
			curr.append(s.substr(0, i + 1));
			curr.push_back('.');
			restoreIpAddressesCore(s.substr(i + 1), results, curr, rest - 1);
			for (int j = 0; j < i + 2; ++j)
				curr.pop_back();
			num *= 10;
		}
	}
};
```

