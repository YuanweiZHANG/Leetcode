#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/**
* 2020-04-11
* Veronica
*/
class Solution {
public:
	string simplifyPath(string path) {
		if (path == "")
			return path;
		vector<string> directories;
		string directory;
		stringstream ss(path);
		while (getline(ss, directory, '/')) {
			if (directory == "" || directory == ".")
				continue;
			else if (directory == "..") {
				if (!directories.empty())
					directories.pop_back();
			}
			else
				directories.push_back(directory);
		}

		string result;
		if (!directories.empty()) {
			for (auto directory : directories) {
				result.append("/" + directory);
			}
		}
		else
			result = "/";
		return result;
	}
};

int main() {
	Solution solution;

	vector<string> paths = { "/home/","/../","/home//foo/","/a/./b/../../c/","/a/../../b/../c//.//","/a//b////c/d//././/..","/..." };
	for (auto path : paths) {
		cout << solution.simplifyPath(path) << endl;
	}

	return 0;
}
