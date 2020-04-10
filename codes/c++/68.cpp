#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
* 2020-04-10
* Veronica
*/
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

int main() {
	Solution solution;

	vector<string> words = { "Science","is","what","we","understand","well","enough","to","explain",
		"to","a","computer.","Art","is","everything","else","we","do" };
	int maxWitdth = 20;
	vector<string> results = solution.fullJustify(words, maxWitdth);
	for (auto str : results) {
		cout << str << endl;
	}

	return 0;
}
