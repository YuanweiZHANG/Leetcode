##72. [Edit Distance](https://leetcode.com/problems/edit-distance/) 

> Hard

Given two words *word1* and *word2*, find the minimum number of operations required to convert *word1* to *word2*.

You have the following 3 operations permitted on a word:

1. Insert a character
2. Delete a character
3. Replace a character

**Example 1:**

```
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
```

**Example 2:**

```
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
```



**Solutions:**

Classic Dynamic Planning.

Define `distance[i][j]` as the minimum number of operations between `word1.substr(0, i)` and `word2.substr(0, j)`. Therefore, `distance[len1][len2]` is the answer.

Initiation: 

```
distance[i][0] = i;
distance[0][j] = j;
```

Relationship formula: 

```
distance[i][j] = distance[i-1][j-1], if word1[i-1] == word2[j-1];
distance[i][j] = min(min(distance[i-1][j], distance[i][j-1]), distance[i-1][j-1]) + 1, if word1[i-1] != word2[j-1];
```

Here is my solution class:

```c++
class Solution {
public:
	int minDistance(string word1, string word2) {
		int len1 = word1.size(), len2 = word2.size();
		vector<vector<int>> distance(len1 + 1, vector<int>(len2 + 1, 0));
		for (int i = 0; i <= len1; ++i) {
			for (int j = 0; j <= len2; ++j) {
				if (i == 0)
					distance[i][j] = j;
				else if (j == 0)
					distance[i][j] = i;
				else if (word1[i - 1] == word2[j - 1]) {
					distance[i][j] = distance[i - 1][j - 1];
				}
				else
					distance[i][j] = min(min(distance[i - 1][j], distance[i][j - 1]), distance[i - 1][j - 1]) + 1;
			}
		}
		return distance[len1][len2];
	}
};
```

