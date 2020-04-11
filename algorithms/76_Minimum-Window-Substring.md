## 76. [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)

> Hard

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

**Example:**

```
Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
```

**Note:**

- If there is no such window in S that covers all characters in T, return the empty string `""`.
- If there is such window, you are guaranteed that there will always be only one unique minimum window in S.



**Solutions:**

Hmmmm, my solution is so complicated and slow...

`mpT` stores latest postion of `t`'s characters in `s`. `priorityMap` stores every useful `t`'s characters' position. It can return the earliest appearance of `t`'s characters.

Here is my solution class:

```c++
class Solution {
public:
	string minWindow(string s, string t) {
		int lenS = s.size(), lenT = t.size();
		int start = -1, end = -1;
		
		multimap<char, int> mpT;  // store t's charater whether exist in s
		map<int, char> priorityMap;
		for (int i = 0; i < lenT; ++i) {
			mpT.insert(make_pair(t[i], -1));
		}
		for (int i = 0; i < lenS; ++i) {
			if (mpT.find(s[i]) != mpT.end()) { // target characters
				if (start == -1) {
					start = end = i;
					priorityMap[i] = s[i];
				}
				else {
					if (mpT.find(s[i])->second == -1) { // s[i]: first appearance
						priorityMap[i] = s[i];
						end = i;
						start = priorityMap.begin()->first;
					}
					else {
						priorityMap.erase(mpT.find(s[i])->second); // update s[i]'s position in s
						priorityMap[i] = s[i];
						if (i - priorityMap.begin()->first < end - start) {
							// updating s[i] has a shorter substring
							start = priorityMap.begin()->first;
							end = i;
						}
					}
				}
				mpT.erase(mpT.find(s[i]));				
				mpT.insert(make_pair(s[i], i));
			}
		}
		for (auto p : mpT) {
			if (p.second == -1) // some characters of t are not in s
				return "";
		}
		return s.substr(start, end - start + 1);
	}
};
```

Someone else's better solution:

```c++
class Solution {
public:
    string minWindow(string s, string t) {
        std::vector<int> hist(128, 0);
        for (char c : t) hist[c]++;
        
        int remaining = t.length();
        int left = 0;
        int right = 0;
        int minStart = 0;
        int minLen = INT_MAX;
        while (right < s.length())
        {
            // if not exist in t then --hist[s[right]] = -1; so if --hist[s[right]] >=0, it must appear in t
            if (--hist[s[right++]] >= 0) remaining--;
            // have found all characters in t
            while (remaining == 0)
            {
                if (right - left < minLen)
                {
                    minLen = right - left;
                    minStart = left;
                }
                // shrink left boundary
                // if not exist in t, then ++hist[s[left]] = 0; so if ++hist[s[left]] > 0, it must appear in t
                if (++hist[s[left++]] > 0) remaining++;
            }
        }
        return minLen < INT_MAX ? s.substr(minStart, minLen) : "";
    }
};
```

This method calculate every pair of `left` and `right` when all `t`'characters have appeared in `s`.  **`hist`** array is the **KEY**.