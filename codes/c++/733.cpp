#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
* 2020-05-11
* Veronica
*/
class Solution {
public:
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		if (image.empty() || image[0].empty())
			return image;
		int row = image.size(), col = image[0].size();
		if (sr > row || sc > col || image[sr][sc] == newColor)
			return image;
		queue<pair<int, int>> que;
		que.push({ sr,sc });
		int oldColor = image[sr][sc];
		while (!que.empty()) {
			int x = que.front().first;
			int y = que.front().second;
			image[x][y] = newColor;
			for (int i = 0; i < 4; ++i) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx >= 0 && xx < row && yy >= 0 && yy < col && image[xx][yy] == oldColor)
					que.push({ xx,yy });
			}
			que.pop();
		}
		return image;
	}
};

int main() {
	Solution solution;

	vector<vector<int>> image = { {1,1,1},{1,1,0},{1,0,1} };
	int sr = 1, sc = 1, newColor = 2;
	vector<vector<int>> results = solution.floodFill(image, sr, sc, newColor);
	for (auto a : results) {
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}

	return 0;
}