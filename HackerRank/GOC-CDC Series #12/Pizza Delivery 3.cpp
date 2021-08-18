/*
	group : HackerRank - GOC-CDC Series #12
	name : Pizza Delivery 3.cpp
	srcPath : /home/aryan/Documents/cp/Pizza_Delivery_3.cpp
	url : https://www.hackerrank.com/contests/goc-cdc-series-12/challenges/pizza-delivery-3
*/
/*
    author : aryan57
    created : 10-July-2021 16:47:27 IST
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

const int mxn = 1e6;
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
    int n,m;
    cin>>n>>m;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    --a;--b;--c;--d;

    vector <pair <int,int> > adj[n*m];

    char g[n][m];

    F(i,0,n-1)
    {
        F(j,0,m-1)
        {
            cin>>g[i][j];

        }
    }

    unordered_map<char,pair <int,int> > move;
    move['L']={0,-1};
    move['R']={0,1};
    move['U']={-1,0};
    move['D']={1,0};

    

    vector< vector<int> > dis(n,vector <int> (m,INF));
    vector< vector<bool> > vis(n,vector <bool> (m,false));

    dis[a][b] = 0;
    set< pair <int,pair <int,int> >  > q;
    q.insert({0, {a,b}});
    while (!q.empty()) {
        pair <int,int>  v = (*q.begin()).second;
        int d_v = (*q.begin()).first;
        q.erase(q.begin());

        if(vis[v.X][v.Y])continue;
        vis[v.X][v.Y]=true;
        if(v.X==c && v.Y==d)break;
        F(k,0,3)
        {
            int r=v.X +plus_x[k];
            int c=v.Y+plus_y[k];

            int rr = v.X + move[g[v.X][v.Y]].X; 
            int cc = v.Y + move[g[v.X][v.Y]].Y;

            int cost=1;

            if(rr==r && cc==c)cost=0;

            if(!is_inside(r,c,n,m))continue;

            if (dis[v.X][v.Y] + cost < dis[r][c]) {
                dis[r][c]=dis[v.X][v.Y] + cost ;
                q.insert({dis[r][c], {r,c}});
            }
        }
    }

    cout<<dis[c][d];
    cout<<"\n";
    


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
//	parsed : 10-July-2021 16:47:23 IST