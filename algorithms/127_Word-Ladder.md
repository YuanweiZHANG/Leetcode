##127. [Word Ladder](https://leetcode.com/problems/word-ladder/) 

> Medium

Given two words (*beginWord* and *endWord*), and a dictionary's word list, find the length of shortest transformation sequence from *beginWord* to *endWord*, such that:

1. Only one letter can be changed at a time.
2. Each transformed word must exist in the word list.

**Note:**

- Return 0 if there is no such transformation sequence.
- All words have the same length.
- All words contain only lowercase alphabetic characters.
- You may assume no duplicates in the word list.
- You may assume *beginWord* and *endWord* are non-empty and are not the same.

**Example 1:**

```
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
```

**Example 2:**

```
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
```



**Solutions:**

Using queue to BFS is a natural method to solve shortest transformation sequence. 

Here is my solution class:

```c++
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if (wordList.empty())
			return 0;
		unordered_map<string, bool> paths;
		for (auto word : wordList)
			paths[word] = true;
		queue<pair<string, int/*steps*/>> que;
		que.push({ beginWord, 1 });
		while (!que.empty()) {
			string curr = que.front().first;
			int steps = que.front().second;
			if (curr == endWord)
				return steps;
			for (int i = 0; i < curr.size(); ++i) {
				string s = curr;
				for (int j = 0; j < 26; ++j) {
					s[i] = j + 'a';
					if (paths.find(s) != paths.end() && paths[s]) {
						que.push({ s, steps + 1 });
						paths[s] = false;
					}
				}
			}
			que.pop();
		}
		return 0; // not found
	}
};
```

