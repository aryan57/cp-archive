/*
	group : Codeforces - Codeforces Round #733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))
	name : B. Putting Plates.cpp
	srcPath : /home/aryan/Documents/cp/B_Putting_Plates.cpp
	url : https://codeforces.com/contest/1530/problem/B
*/
/*
    author : aryan57
    created : 17-July-2021 20:10:26 IST
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

void solve_LOL()
{
    int h,w;
    cin>>h>>w;

    int g[h][w]={};

    F(j,0,w-1)
    {
        int i=0;

        if(g[i][j]==0)
        {
            g[i][j]=1;

            F(k,0,7)
            {
                int r=i+square_x[k];
                int c=j+square_y[k];

                if(is_inside(r,c,h,w))
                {
                    g[r][c]=-1;
                }
            }
        }
    }
    F(j,0,w-1)
    {
        int i=h-1;

        if(g[i][j]==0)
        {
            g[i][j]=1;

            F(k,0,7)
            {
                int r=i+square_x[k];
                int c=j+square_y[k];

                if(is_inside(r,c,h,w))
                {
                    g[r][c]=-1;
                }
            }
        }
    }

    F(i,0,h-1)
    {
        int j=0;

        if(g[i][j]==0)
        {
            g[i][j]=1;

            F(k,0,7)
            {
                int r=i+square_x[k];
                int c=j+square_y[k];

                if(is_inside(r,c,h,w))
                {
                    g[r][c]=-1;
                }
            }
        }
    }

    F(i,0,h-1)
    {
        int j=w-1;

        if(g[i][j]==0)
        {
            g[i][j]=1;

            F(k,0,7)
            {
                int r=i+square_x[k];
                int c=j+square_y[k];

                if(is_inside(r,c,h,w))
                {
                    g[r][c]=-1;
                }
            }
        }
    }

    F(i,0,h-1)
    {
        F(j,0,w-1)
        {
            if(g[i][j]==-1)g[i][j]=0;
        }
    }
    F(i,0,h-1)
    {
        F(j,0,w-1)
        {
            cout<<g[i][j];
        }cout<<"\n";
    }
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
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}
//	parsed : 17-July-2021 20:07:47 IST