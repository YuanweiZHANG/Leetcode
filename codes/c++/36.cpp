#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-03
* Veronica
*/
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool result = true;
		for (int i = 0; i < 9; ++i) {
			result &= isValidNine(board, i, 0, 1, 9);
			if (!result)
				return false;
			result &= isValidNine(board, 0, i, 9, 1);
			if (!result)
				return false;
		}
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				result &= isValidNine(board, i * 3, j * 3, 3, 3);
				if (!result)
					return false;
			}
		}
		return true;
	}

	bool isValidNine(vector<vector<char>>& board, int row, int col, int row_num, int col_num) {
		bool num[10] = { false };
		for (int i = 0; i < row_num; ++i) {
			for (int j = 0; j < col_num; ++j) {
				char ch = board[i + row][j + col];
				if (ch == '.')
					continue;
				else {
					if (!num[ch - '0']) {
						num[ch - '0'] = true;
					}
					else
						return false;
				}
			}
		}
		return true;
	}
};

int main() {
	Solution solution;

	vector<vector<char>> board = {
		{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};
	cout << solution.isValidSudoku(board) << endl;

	return 0;
}