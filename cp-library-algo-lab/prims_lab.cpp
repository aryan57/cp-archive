/*
    author : Aryan Agarwal, 19CS30005
    created : 29-October-2020 10:53:02 IST
*/
// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int mxn = 100;
const int INF = INT_MAX;

void prim(int n,int W[][mxn],set <pair<int,int> > F)
{
    F.clear();

    int nearest[n+1];
    int distance[n+1];

    for(int i=2;i<=n;i++)
    {
        nearest[i]=1;
        distance[i]=W[1][i];
    }

    int min_d,v_near;

    for(int k = 1;k<n;k++)
    {
        min_d=INF;
        for(int i=2;i<=n;i++)
        {
            if(0<=distance[i] && distance[i]<min_d)
            {
                min_d=distance[i];
                v_near=i;
            }
        }

        F.insert({v_near,nearest[v_near]});
        distance[v_near]=-1;

        for(int i=2;i<=n;i++)
        {
            if(W[i][v_near]<distance[i])
            {
                distance[i] = W[i][v_near];
                nearest[i] = v_near;

            }
        }

    }
    

}

int main()
{

    int n,m; //n>=2
    // n = #vertex
    // m = #edge

    int W[n][n];
    // 0 if i=j
    // INF if no edge

    int nearest[n]; // index of the vertex in 'Y' nearest to v_i
    int distance[n]; // weight of the edge between v_i and vertex indexed by nearest[i]

    // initialisation
    // set 'Y' = {v1}
    // nearest[i] = 1 for all i [1,n]
    // distance[1]=0
    // distance[i] = adj[1][i] for all i [2,n]

    
    return 0;
}