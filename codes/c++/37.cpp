#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-03
* Veronica
*/
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		bool valid[27][9] = { false };
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					valid[i][board[i][j] - '0' - 1] = true;
					valid[9 + j][board[i][j] - '0' - 1] = true;
					valid[18 + 3 * (i / 3) + j / 3][board[i][j] - '0' - 1] = true;
				}
			}
		}
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.') {
					for (int k = 0; k < 9; ++k) {
						if (!valid[i][k] && !valid[9 + j][k] && !valid[18 + 3 * (i / 3) + j / 3][k]) {
							valid[i][k] = true;
							valid[9 + j][k] = true;
							valid[18 + 3 * (i / 3) + j / 3][k] = true;
							board[i][j] = '0' + k + 1;
							if (fill(board, valid, i * 9 + j))
								return;
							board[i][j] = '.';
							valid[i][k] = false;
							valid[9 + j][k] = false;
							valid[18 + 3 * (i / 3) + j / 3][k] = false;
						}
					}
					return;
				}
			}
		}
	}
	bool fill(vector<vector<char>>& board, bool valid[27][9], int loc) {
		for (int loc_ = loc + 1; loc_ < 81; ++loc_) {
			int i = loc_ / 9;
			int j = loc_ % 9;
			if (board[i][j] == '.') {
				for (int k = 0; k < 9; ++k) {
					if (!valid[i][k] && !valid[9 + j][k] && !valid[18 + 3 * (i / 3) + j / 3][k]) {
						valid[i][k] = true;
						valid[9 + j][k] = true;
						valid[18 + 3 * (i / 3) + j / 3][k] = true;
						board[i][j] = '0' + k + 1;
						if (fill(board, valid, i * 9 + j))
							return true;
						board[i][j] = '.';
						valid[i][k] = false;
						valid[9 + j][k] = false;
						valid[18 + 3 * (i / 3) + j / 3][k] = false;
					}
				}
				return false;
			}
		}
		return true;
	}
};

int main() {
	Solution solution;

	vector<vector<char>> board = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};
	solution.solveSudoku(board);
	for (auto row : board) {
		for (auto col : row) {
			cout << col << ' ';
		}
		cout << endl;
	}

	return 0;
}