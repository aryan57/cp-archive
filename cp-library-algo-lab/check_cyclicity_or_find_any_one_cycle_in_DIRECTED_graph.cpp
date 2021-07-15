/*
    check if a DIRECTED graph is cyclic or not
                    or
    Find any one cycle in a DIRECTED graph 
*/

#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5;

vector <vector<int>> adj(MXN);
vector <int> color(MXN);
vector <int> parent(MXN);
int cycle_start=-1,cycle_end=-1;

// here graph is directed , so we can go to parent node
bool dfs(int v)
{
    color[v]=1; // color node to grey

    for(int u : adj[v])
    {
        if(color[u]==0)
        {
            parent[u]=v;
            if(dfs(u))return true;
        }
        else if(color[u]==1)
        {
            cycle_end=v; // current node
            cycle_start=u; // node we meant to go
            return true;
        }
    }

    color[v]=2;
    return false;
}

void find_cycle(int n)
{
    cycle_start=cycle_end=-1;

    fill(color.begin(),color.end(),0); // initial all nodes are white or 'unvisited'
    fill(parent.begin(),parent.end(),-1);

    for(int i=0;i<n;i++)
    {
        if(color[i]==0)
        {
            if(dfs(i))break;
        }
    }

    if(cycle_start==-1)
    {
        cout<<"\nNo cycles found...\n";
    }
    else
    {
        vector <int> path;
        
        for(int v=cycle_end;v!=cycle_start;v=parent[v])
        {
            path.push_back(v);
        }

        path.push_back(cycle_start);
        reverse(path.begin(),path.end());

        cout<<"\nPath Found...\n";

        for(int i=0;i<path.size();i++)
        {
            cout<<path[i]+1<<" "; // +1 beacuse 0 based indexation was used
        }

        cout<<"\n";
    }
}

int main()
{
    /*
    directed graph
    1 2
    2 3
    3 4
    4 2
    4 5
    */
    int n;
    n=5;

    // nodes are considered in based indexation
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(4);

    find_cycle(n);
    
    
    return 0;
}