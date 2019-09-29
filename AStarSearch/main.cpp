#include <fstream>
#include <iostream>
#include <sstream>
#include <String>
#include <vector>

using namespace std;

enum class State
{
	kEmpty,
	kObstcle
};

vector<State> ParseLine(string line) {
	istringstream sline(line);
	int n;
	char c;
	vector<State> row;
	while (sline >> n >> c && c == ',') {
		if (n == 0) {
			row.push_back(State::kEmpty);
		}
		else {
			row.push_back(State::kObstcle);
		}
	}
	return row;
}

vector<vector<State> > ReadBoardFile(string path) {
	ifstream myfile(path);
	vector<vector<State> > board{};
	if (myfile) {
		string line;
		while (getline(myfile, line)) {
			vector<State> row = ParseLine(line);
			board.push_back(row);
		}
	}
	return board;
}

/**
* Implementation of A* search algorithm
*/
vector<vector<State> > Search(vector<vector<State> > grid, int initial_point[2], int goal_point[2]) {
	cout << "No path found!" << "\n";
	return vector<vector<State> > {};
}

string CellString(State cell) {
	switch (cell)
	{
	case State::kObstcle:
		return "⛰️   ";
	default:
		return "0   ";
	}
}

void PrintBoard(const vector<vector<State> > board) {
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			cout << CellString(board[i][j]);
		}
		cout << "\n";
	}
}

int main()
{
	int init_point[2]{ 0, 0 };
	int goal_point[2]{ 4, 5 };

	auto board = ReadBoardFile("1.board");
	auto solution = Search(board, init_point, goal_point);
	PrintBoard(solution);
	
}
