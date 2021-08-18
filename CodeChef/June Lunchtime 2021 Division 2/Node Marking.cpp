/*
	group : CodeChef - June Lunchtime 2021 Division 2
	name : Node Marking.cpp
	srcPath : /mnt/c/Users/aryan/Desktop/cp/Node_Marking.cpp
	url : https://www.codechef.com/LTIME97B/problems/NDMRK
*/
/*
    author : aryan57
    created : 26-June-2021 22:08:58 IST
*/
#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
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

const int mxn = 5e4;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

vector <int> adj[mxn+1];

int dfs(int u,int par)
{
    int ans=1;

    for(int to : adj[u])
    {
        if(to==par)continue;
        ans+=dfs(to,u);
        break;
    }
    return ans;
}

void solve_LOL()
{
    int n,k;
    cin>>n>>k;

    F(i,2,n-1)
    {
        int x;
        cin>>x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    int c1=dfs(1,-1);
    int c2=n-c1;

    if(c1<c2)swap(c1,c2);

    int ans=0;
    int req=(k+n-1)/n;

    ans+=req-1;

    int rem=k;

    int lem=((rem+c1-1)/c1);
    lem=min(lem,req);
    rem-=lem*c1;
    ans+=lem;
    rem=max(0ll,rem);

    if(rem>0)
    {
        lem=((rem+c2-1)/c2);
        lem=min(lem,req);
        rem-=lem*c2;
        ans+=lem;
        rem=max(0ll,rem);

    }
    
    assert(rem==0);
    

    cout<<ans;
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
    int _t = 1;
    cin >> _t;
    for (int i = 1; i <= _t; i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}