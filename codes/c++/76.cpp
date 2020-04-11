#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

/**
* 2020-04-11
* Veronica
*/
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

int main() {
	Solution solution;

	string s = "AA", t = "AA";
	//string s = "ADOBECODEBANC", t = "ABC";
	//string s = "abc", t = "b";
	//string s = "bba", t = "ab";
	cout << solution.minWindow(s, t) << endl;

	return 0;
}
