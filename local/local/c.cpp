/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/c.cpp
	url : /home/aryan/Desktop/cp-workspace/c.cpp
*/
#include <bits/stdc++.h>
using namespace std;

class State{
public:
	int i, j, k;

	State(int _i, int _j, int _k){
		i = _i; j = _j; k = _k;
	}

	bool operator < (const State &y) const { return this->k < y.k; }
};

int main()
{
	map<State, bool> visited;

	cout << visited[State (0, 1, 1)] << "\n";
	cout << visited[State (0, 0, 1)] << "\n";

	visited[State (0, 0, 1)] = true;

	cout << visited[State (0, 1, 1)] << "\n";
	cout << visited[State (0, 0, 1)] << "\n";

	return 0;
}