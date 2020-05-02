## 771. [Jewels and Stones](https://leetcode.com/problems/jewels-and-stones/)

> Easy

You're given strings `J` representing the types of stones that are jewels, and `S` representing the stones you have.  Each character in `S` is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in `J` are guaranteed distinct, and all characters in `J` and `S` are letters. Letters are case sensitive, so `"a"` is considered a different type of stone from `"A"`.

**Example 1:**

```
Input: J = "aA", S = "aAAbbbb"
Output: 3
```

**Example 2:**

```
Input: J = "z", S = "ZZ"
Output: 0
```

**Note:**

- `S` and `J` will consist of letters and have length at most 50.
- The characters in `J` are distinct.



**Solutions:**

Use a hashmap `jewels` to store all types of jewels.

Here is my solution class:

```c++
class Solution {
public:
	int numJewelsInStones(string J, string S) {
		bool jewels[128] = { false };
		for (int i = 0; i < J.size(); ++i) {
			jewels[J[i]] = true;
		}
		int num = 0;
		for (int i = 0; i < S.size(); ++i) {
			if (jewels[S[i]])
				num++;
		}
		return num;
	}
};
```