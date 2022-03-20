/*
	group : local
	name : c2.cpp
	srcPath : /home/aryan/cp-workspace/c2.cpp
	url : /home/aryan/cp-workspace/c2.cpp
*/
#include <bits/stdc++.h>
using namespace std;



int main()
{
	
	int n,m;

	// cout<<"Please enter number of rows : ";
	cin>>n;
	// cout<<"Please enter number of columns : ";
	cin>>m;

	vector< vector<bool> > grid(n,vector <bool> (m,true));

	pair <int,int> start={0,0};

	// cout<<"The start cell is currently (1,1). Do you want to change it?.\n";
	// cout<<"Press 1 for yes and 0 nor no : ";
	// int is_change=0;
	// cin>>is_change;
	// if(is_change==1){
		// cout<<"Please enter the row of the start cell : ";
		cin>>start.first;
		start.first--;
		// cout<<"Please enter the column of the start cell : ";
		cin>>start.second;
		start.second--;
	// }
	assert(start.first>=0 && start.first<n);
	assert(start.second>=0 && start.second<m);
	int b;
	cin>>b;
	while (b--)
	{

		pair <int,int> block;
		cin>>block.first;
		block.first--;
		cin>>block.second;
		block.second--;
		assert(block.first>=0 && block.first<n);
		assert(block.second>=0 && block.second<m);
		assert(block!=start); // start cell cant be blocked

		grid[block.first][block.second]=false;
	}
	
	queue<pair <int,int> > q;
	vector< vector<bool> > visited(n,vector <bool> (m));
	vector< vector<pair <int,int> > > parent(n,vector <pair <int,int> > (m,{-1,-1}));
	
	q.push(start);
	visited[start.first][start.second] = true;
	parent[start.first][start.second] = {-1,-1};

	vector<int> hx = {-1,0,1,0};
	vector<int> hy = {0,1,0,-1};
	pair <int,int> last_visited=start;
	while (!q.empty()) {
	
		auto parent_node = q.front();
		last_visited=parent_node;
		q.pop();
	
		for(int k=0;k<4;k++){
			int r=parent_node.first+hx[k];
			int c=parent_node.second+hy[k];

			if( r>=0 && r<n && c>=0 && c<m && grid[r][c] && !visited[r][c]){
				q.push({r,c});
				parent[r][c]=parent_node;
				visited[r][c]=true;
			}
		}
	}

	vector<pair<int,int> > path;
	while (true)
	{
		path.push_back(last_visited);
		last_visited=parent[last_visited.first][last_visited.second];
		if(last_visited.first==-1)break;
	}
	reverse(path.begin(),path.end());
	assert(*path.begin()==start); // must start from start cell
	
	cout<<"Path : \n";
	for(auto p : path){
		cout<<"("<<p.first+1<<","<<p.second+1<<"), ";
	}
	cout<<"\n";

	return 0;
}