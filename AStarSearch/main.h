#pragma once
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <String>
#include <vector>

using namespace std;

enum class State { kStart, kFinish, kEmpty, kObstacle, kClosed, kPath };

// directional deltas, up,left,down,right
const int delta[4][2]{ { -1,0 },{ 0,-1 },{ 1,0 },{ 0,1 } };

vector<State> ParseLine(string line);
vector<vector<State> > ReadBoardFile(string path);
bool Compare(vector<int> a, vector<int> b);
void CellSort(vector<vector<int> > *v);
int Heuristic(int x1, int y1, int x2, int y2);
bool CheckValidCell(int x, int y, vector<vector<State> > &grid);
void AddToOpen(int x, int y, int g, int h, vector<vector<int> > &openlist, vector<vector<State> > &grid);
void ExpandNeighbors(vector<int> &current_node, int *goal, vector<vector<int> > &openlist, vector<vector<State> > &grid);
vector<vector<State> > Search(vector<vector<State> > grid, int init[2], int goal[2]);
string CellString(State cell);
void PrintBoard(const vector<vector<State> > board);

