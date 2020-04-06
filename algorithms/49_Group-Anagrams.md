## 49. [Group Anagrams](https://leetcode.com/problems/group-anagrams/)

> Medium

Given an array of strings, group anagrams together.

**Example:**

```
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
```

**Note:**

- All inputs will be in lowercase.
- The order of your output does not matter.




**Solutions:**

`signal` stores every 26 letters appearing in the `str`. Use `signal` to determine whether this `str` belongs to this group.

Here is my solution class:

```c++
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<string> signals;
		vector<vector<string>> result;
		for (auto str : strs) {
			string signal(26, '0');
			int len = str.size();
			for (int i = 0; i < len; ++i) {
				signal[str[i] - 'a']++;
			}
			int groups = signals.size(), i = 0;
			for (i = 0; i < groups; ++i) {
				if (signals[i] == signal) {
					result[i].push_back(str);
					break;
				}
			}
			if (i == groups) {
				signals.push_back(signal);
				result.push_back({ str });
			}
		}
		return result;
	}
};
```

However, this kind of solution's time complexity is $O(n^2)$, and space complexity is $O(n)$. 

Someone else sort every `str` in `strs` so that anagrams can get same `string`.

Here is the solution class:

```c++
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> mp;
		int len = strs.size();
		for (auto str : strs) {
			string key = str;
			sort(key.begin(), key.end());
			mp[key].push_back(str);
		}
		vector<vector<string>> result;
		for (auto it : mp) {
			result.push_back(it.second);
		}
		return result;
	}
};
```

