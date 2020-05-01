#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
* 2020-04-30
* Veronica
*/
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.empty() || board[0].empty())
			return;
		int dx[4] = { 1,-1,0,0 };
		int dy[4] = { 0,0,1,-1 };
		queue<pair<int, int>> que;
		int row = board.size(), col = board[0].size();
		vector<vector<bool>> visited(row, vector<bool>(col, false));
		for (int i = 0; i < row; ++i) {
			if (board[i][0] == 'O') {
				que.push(make_pair(i, 0));
				visited[i][0] = true;
			}
			if (board[i][col - 1] == 'O') {
				que.push(make_pair(i, col - 1));
				visited[i][col - 1] = true;
			}
		}
		for (int j = 1; j < col - 1; ++j) {
			if (board[0][j] == 'O') {
				que.push(make_pair(0, j));
				visited[0][j] = true;
			}
			if (board[row - 1][j] == 'O') {
				que.push(make_pair(row - 1, j));
				visited[row - 1][j] = true;
			}
		}
		while (!que.empty()) {
			pair<int, int> point = que.front();
			for (int i = 0; i < 4; ++i) {
				int xx = point.first + dx[i];
				int yy = point.second + dy[i];
				if (xx >= 0 && xx < row && yy >= 0 && yy < col && board[xx][yy] == 'O' && !visited[xx][yy]) {
					visited[xx][yy] = true;
					que.push(make_pair(xx, yy));
				}
			}
			que.pop();
		}
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (board[i][j] == 'O' && !visited[i][j])
					board[i][j] = 'X';
			}
		}
	}
};

int main() {
	Solution solution;

	vector<vector<char>> board = { {'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'} };
	solution.solve(board);
	for (auto a : board) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}

	return 0;
}