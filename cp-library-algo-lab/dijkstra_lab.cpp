/*
    author : Aryan Agarwal, 19CS30005
    created : 29-October-2020 11:45:51 IST
*/
#include <bits/stdc++.h>
using namespace std;

const int mxn = 100;
const int INF = INT_MAX;

void dijkstra(int n,int W[][mxn],set<pair<int,int> > &F)
{
    int touch[n+1];
    int length[n+1];

    F.clear();

    for(int i=2;i<=2;i++)
    {
        touch[i]=1;
        length[i]=W[1][i];
    }
    int min_d,v_near;

    for(int k=1;k<n;k++)
    {
        min_d = INF;
        for(int i=2;i<=n;i++)
        {
            if(0<=length[i] && length[i]<min_d)
            {
                min_d = length[i];
                v_near = i;
            }
        }

        pair <int,int> e;
        e ={touch[v_near],v_near};
        F.insert(e);

        for(int i=2;i<=n;i++)
        {
            if(length[i]>length[v_near]+W[v_near][i])
            {
                length[i]=length[v_near]+W[v_near][i];
                touch[i]=v_near;
                length[v_near]=-1;
            }
        }

    }

}

int main()
{

    
    return 0;
}