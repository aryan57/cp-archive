/*
	group : Codeforces - Codeforces Round #593 (Div. 2)
	name : D. Alice and the Doll.cpp
	srcPath : /home/aryan/Documents/cp/D_Alice_and_the_Doll.cpp
	url : https://codeforces.com/contest/1236/problem/D
*/
/*
    author : aryan57
    created : 24-June-2021 15:40:25 IST
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
    return (x>=1 && x<=n && y>=1 && y<=m);
}

void solve_LOG()
{
    int n,m;
    cin>>n>>m;

    vector< vector<bool> > vis(n+1,vector <bool> (m+1,false));
    vector< vector<bool> > block(n+1,vector <bool> (m+1,false));
    

    int k;
    cin>>k;
    int tot=n*m;

    F(i,0,k-1)
    {
        int x,y;
        cin>>x>>y;
        block[x][y]=true;
        tot--;
    }

    F(i,0,n)block[i][0]=true;
    F(j,0,m)block[0][j]=true;

    int x=1;
    int y=1;

    vector <int> hx={0,1,0,-1};
    vector <int> hy={1,0,-1,0};
    int d=0;

    while(true)
    {
        tot--;
        vis[x][y]=true;
        // dbg(x,y);
        bool ok=false;
        F(k,0,3)
        {
            int r=x+hx[(d+k)%4];
            int c=y+hy[(d+k)%4];
            
            if(is_inside(r,c,n,m) && !vis[r][c] && !block[r][c])
            {
                x=r;
                y=c;
                d=(d+k)%4;
                ok=true;
                break;
            }
        }

        if(!ok)break;
    }

    cout<<(tot==0?"Yes":"No");
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
//	parsed : 24-June-2021 14:30:24 IST