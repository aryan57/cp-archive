/*
	group : local
	name : c3.cpp
	srcPath : /home/aryan/Documents/cp/c3.cpp
	url : /home/aryan/Documents/cp/c3.cpp
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define F(i,a,b) for(int i=a;i<=b;i++)
#define RF(i,a,b) for(int i=a;i>=b;i--)
const int mxn=1e6+1;
int spf[mxn];

void init()
{
    F(i,0,mxn)spf[i]=i;

    for(int i=2;i<=mxn;i++)
    {
        if(spf[i]==i)
        for(int j=i;j<=mxn;j+=i)
        {
            spf[j]=i;
        }
    }
}

int f(int n)
{
    int cnt=0;

    while (n!=1)
    {
        cnt++;
        int z=spf[n];
        while (n%z==0)
        {
            n/=z;
        }
        
    }

    return cnt;
    
}



struct Edge {
    int x,y;
    int w;
};


void solve()
{
    
    int n;
    cin>>n;
    vector<Edge> adj[n][n];
    int g[n][n];

    F(i,0,n-1)
    {
        F(j,0,n-1)
        {
            cin>>g[i][j];
            int p=f(g[i][j]);
            int cost = (int)floor(sqrt(g[i][j]));
            F(r,max(0ll,i-p),min(n-1,i+p))
            {
                F(c,max(0ll,j-p),min(n-1,j+p))
                {
                    if(abs(c-j) + abs(i-r)>p)continue;
                    
                    Edge e;
                    e.x=r;
                    e.y=c;
                    e.w=cost;

                    // cout<<i<<" "<<j<<" "<<r<<" "<<c<<" "<<cost;cout<<"\n";

                    adj[i][j].push_back(e);
                }
            }

        }
    }



    vector< vector<int> > d(n,vector <int> (n,1e18));

    d[0][0] = 0;
    using pii = pair<int, pair<int,int> >;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, {0,0}});
    while (!q.empty()) {
        auto v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v.first][v.second])
            continue;

        for (auto edge : adj[v.first][v.second]) {
            int x = edge.x;
            int y = edge.y;
            int len = edge.w;

            if (d[v.first][v.second] + len < d[x][y]) {
                /*
                    q.erase({d[to], to});

                    no need to erase, let the old pair be in the priority_queue,
                    since we are always accessing the smallest pair,
                    this old pair will never be used.
                */
                d[x][y] = d[v.first][v.second] + len;
                q.push({d[x][y], {x,y}});
            }
        }
    }
    

    cout<<d[n-1][n-1];
    cout<<"\n";


}

signed main()
{
    init();
    int tc;
    cin>>tc;

    while (tc--)
    {
        solve();
    }

    return 0;
    
}