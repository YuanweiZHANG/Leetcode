## 68. [Text Justification](https://leetcode.com/problems/text-justification/)

> Hard

Given an array of words and a width *maxWidth*, format the text such that each line has exactly *maxWidth* characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces `' '` when necessary so that each line has exactly *maxWidth* characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no **extra** space is inserted between words.

**Note:**

- A word is defined as a character sequence consisting of non-space characters only.
- Each word's length is guaranteed to be greater than 0 and not exceed *maxWidth*.
- The input array `words` contains at least one word.

**Example 1:**

```
Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
```

**Example 2:**

```
Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
             because the last line must be left-justified instead of fully-justified.
             Note that the second line is also left-justified becase it contains only one word.
```

**Example 3:**

```
Input:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
```



**Solutions:**

This problem isn't difficult but we need to be cautious about situations listed below.

- A line only has a word, which is `start == end`. Therefore, in this case we cannot calculate the width between words.
- `sum` has already included one blank between words, so we need add one more blank to `blankLong` and `blankShort`.
- When `i = wordsNum - 1`, last line should be left justified.

Here is my solution class:

```c++
class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		int wordsNum = words.size();
		vector<string> results;
		int start = 0, end = 0;
		while (start < wordsNum) {
			int sum = 0;
			for (int i = start; i < wordsNum; ++i) {
				sum += words[i].size();
				if (sum >= maxWidth) {
					if (sum > maxWidth) { // go back a word
						sum -= (words[i].size() + 1);
						i--;
					}
					end = i;
					string line;
					if (end != wordsNum - 1) {
						if (start == end) { // only has one word
							line.append(words[start]);
							string blank(maxWidth - sum, ' ');
							line.append(blank);
						}
						else {
							int blankWidthShort = (maxWidth - sum) / (end - start);
							int blankWidthLongNum = (maxWidth - sum) % (end - start);
							string blankShort(blankWidthShort + 1, ' '); // sum has already included a blank between words
							string blankLong(blankWidthShort + 2, ' ');
							for (int j = start; j < start + blankWidthLongNum; ++j) {
								line.append(words[j]);
								line.append(blankLong);
							}
							for (int j = start + blankWidthLongNum; j < end; ++j) {
								line.append(words[j]);
								line.append(blankShort);
							}
							line.append(words[end]);
						}
						results.push_back(line);
						start = end + 1;
						break;
					}
				}
				if (i == wordsNum - 1) { // last line
					end = i;
					string line;
					for (int j = start; j < end; ++j) {
						line.append(words[j]);
						line.append(" ");
					}
					line.append(words[end]);
					string blank(maxWidth - sum, ' ');
					line.append(blank);
					results.push_back(line);
					start = end + 1;
					break;
				}
				sum += 1; // every single blank after a word
			}
		}
		return results;
	}
};
```

