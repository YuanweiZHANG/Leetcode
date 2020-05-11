## 151. [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/)

> Medium

Given an input string, reverse the string word by word.

 

**Example 1:**

```
Input: "the sky is blue"
Output: "blue is sky the"
```

**Example 2:**

```
Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
```

**Example 3:**

```
Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
```

 

**Note:**

- A word is defined as a sequence of non-space characters.
- Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
- You need to reduce multiple spaces between two words to a single space in the reversed string.



**Solutions:**

Some cases should be noticed.

```
Input: ""
Output: ""
```

```
Input: "  Hello World!  "
Output: "World! Hello"
```

Here is my solution class:

```c++
class Solution {
public:
	string reverseWords(string s) {
		int start = 0, end = 1, n = s.size();
		vector<string> words;
		while (start < n) {
			while (start < n && s[start] == ' ')
				start++;
			if (start == n)
				break;
			end = start + 1;
			while (end < n && s[end] != ' ')
				end++;
			words.push_back(s.substr(start, end - start));
			start = end + 1;
		}
		if (words.empty())
			return "";
		string result = *words.rbegin();
		for (int i = words.size() - 2; i >= 0; --i) {
			result.push_back(' ');
			result.append(words[i]);
		}
		return result;
	}
};
```

We can also use `stringstream` to erase useless space.

```c++
class Solution {
public:
	string reverseWords(string s) {
		reverse(s.begin(), s.end());
		stringstream input(s);
		string word;
		input >> word;
		reverse(word.begin(), word.end());
		string result = word;
		while (input >> word) {
			reverse(word.begin(), word.end());
			result.push_back(' ');
			result.append(word);
		}
		return result;
	}
};
```

