/*
	group : local
	name : c2.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/c2.cpp
	url : /home/aryan/Desktop/cp-workspace/c2.cpp
*/
#include <bits/stdc++.h>
using namespace std;

class State{
public:
	int i, j, k;

	State(int _i, int _j, int _k){
		i = _i; j = _j; k = _k;
	}

	bool operator < (const State &y) const {
		if(this->k != y.k)return this->k < y.k;
		if(this->i != y.i)return this->i < y.i;
		return this->j < y.j;
	}
};

int main()
{
	set<State> visited;

	cout << (visited.find(State (0, 1, 1))==visited.end() ? "absent" : "present")<< "\n";
	cout << (visited.find(State (0, 0, 1))==visited.end() ? "absent" : "present")<< "\n";

	visited.insert(State (0, 0, 1));

	cout << (visited.find(State (0, 1, 1))==visited.end() ? "absent" : "present")<< "\n";
	cout << (visited.find(State (0, 0, 1))==visited.end() ? "absent" : "present")<< "\n";
	cout << (visited.find(State (123, 456, 1))==visited.end() ? "absent" : "present")<< "\n";
	cout << (visited.find(State (123, 456, 789))==visited.end() ? "absent" : "present")<< "\n";

	cout<<"\nvisited states are :\n";
	for(State s : visited){
		cout<<s.i<<" "<<s.j<<" "<<s.k<<"\n";
	}

	return 0;
}