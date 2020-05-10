## 997. [Find the Town Judge](https://leetcode.com/problems/find-the-town-judge/)

> Easy

In a town, there are `N` people labelled from `1` to `N`.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

1. The town judge trusts nobody.
2. Everybody (except for the town judge) trusts the town judge.
3. There is exactly one person that satisfies properties 1 and 2.

You are given `trust`, an array of pairs `trust[i] = [a, b]` representing that the person labelled `a` trusts the person labelled `b`.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return `-1`.

 

**Example 1:**

```
Input: N = 2, trust = [[1,2]]
Output: 2
```

**Example 2:**

```
Input: N = 3, trust = [[1,3],[2,3]]
Output: 3
```

**Example 3:**

```
Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
```

**Example 4:**

```
Input: N = 3, trust = [[1,2],[2,3]]
Output: -1
```

**Example 5:**

```
Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
```

 

**Note:**

1. `1 <= N <= 1000`
2. `trust.length <= 10000`
3. `trust[i]` are all different
4. `trust[i][0] != trust[i][1]`
5. `1 <= trust[i][0], trust[i][1] <= N`



**Solutions:**

Be careful when `N == 1`.

Here is my solution class:

```c++
class Solution {
public:
	int findJudge(int N, vector<vector<int>>& trust) {
		if (N == 1 && trust.empty())
			return 1;
		map<int/*trusted people*/, int/*trust number*/> mp;
		for (auto t : trust) {
			mp[t[0]] = -1;
			if (mp.find(t[1]) != mp.end() && mp[t[1]] == -1)
				continue;
			mp[t[1]]++;
		}
		for (auto p : mp) {
			if (p.second == N - 1)
				return p.first;
		}
		return -1;
	}
};
```

Also, we can use `vector` to store the information of trusting, which would be faster.

