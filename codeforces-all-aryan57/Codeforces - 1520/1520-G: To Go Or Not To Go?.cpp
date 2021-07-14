//https://codeforces.com/contest/1520/problem/G

/*
    // credits : https://codeforces.com/blog/entry/90310?#comment-787861
    author : aryan57
    created : 05-May-2021 23:20:04 IST
*/
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

vector<int> plus_x={0,1,0,-1};
vector<int> plus_y={-1,0,1,0};

vector<int> star_x={1,1,-1,-1};
vector<int> star_y={-1,1,1,-1};

vector<int> square_x={0,1,1,1,0,-1,-1,-1};
vector<int> square_y={-1,-1,0,1,1,1,0,-1};

bool is_inside(int x,int y,int n,int m)
{
    return (x>=0 && x<n && y>=0 && y<m);
}

void solve_LOG()
{
    int n,m,w;
    cin>>n>>m>>w;

    int g[n][m];
    F(i,0,n-1)
    {
        F(j,0,m-1)
        {
            cin>>g[i][j];
        }
    }

    queue<pair <int,int> > q;
    vector< vector<bool> > visited(n,vector <bool> (m,false));
    vector< vector<int> > d1(n,vector <int> (m,INF));
    d1[0][0]=0;
    q.push({0,0});
    visited[0][0] = true;
    
    while (!q.empty()) {
    
        pair <int,int>  parent_node = q.front();
        q.pop();

        F(k,0,3)
        {
            int x=plus_x[k]+parent_node.X;
            int y=plus_y[k]+parent_node.Y;

            if(!is_inside(x,y,n,m) || g[x][y]==-1 || visited[x][y])continue;
            // dbg(parent_node,x,y);
            visited[x][y] = true;
            q.push({x,y});
            d1[x][y] = min(d1[x][y],d1[parent_node.X][parent_node.Y] + 1);
        }
    }

    // dbg(d1);

    vector< vector<int> > d2(n,vector <int> (m,INF));
    d2[n-1][m-1]=0;
    
    q.push({n-1,m-1});
    F(i,0,n-1)F(j,0,m-1)visited[i][j]=false;
    visited[n-1][m-1] = true;
    
    while (!q.empty()) {
    
        pair <int,int>  parent_node = q.front();
        q.pop();

        F(k,0,3)
        {
            int x=plus_x[k]+parent_node.X;
            int y=plus_y[k]+parent_node.Y;

            if(!is_inside(x,y,n,m) || g[x][y]==-1 || visited[x][y])continue;
            // dbg(parent_node,x,y);
            visited[x][y] = true;
            q.push({x,y});
            d2[x][y] = min(d2[x][y],d2[parent_node.X][parent_node.Y] + 1);
        }
    }

    // dbg(d2);

    int ans=INF;
    if(d1[n-1][m-1]!=INF)ans=d1[n-1][m-1]*w;
    // dbg(ans);

    vector <int> x1,x2;

    F(i,0,n-1)
    {
        F(j,0,m-1)
        {
            if(g[i][j]<=0)continue;
            
            int num=1;
            if(d1[i][j]!=INF)num=d1[i][j]*w+g[i][j];
            else num=INF;

            x1.push_back(num);

            num=1;
            if(d2[i][j]!=INF)num=d2[i][j]*w+g[i][j];
            else num=INF;

            x2.push_back(num);
        }
    }

    // dbg(x1,x2);

    if(!x1.empty() && !x2.empty())
    {
        sort(all(x1));
        sort(all(x2));

        ans=min(ans,x1[0]+x2[0]);
    }

    if(ans>=INF)ans=-1;
    cout<<ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
#endif
#ifdef ARYAN_SIEVE
    sieve();
#endif
#ifdef ARYAN_SEG_SIEVE
    segmented_sieve();
#endif
#ifdef ARYAN_FACT
    fact_init();
#endif
    // cout<<fixed<<setprecision(10);
    int _t=1;
    // cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOG();
    }
    return 0;
}