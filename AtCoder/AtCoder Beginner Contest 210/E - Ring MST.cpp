/*
	group : AtCoder - AtCoder Beginner Contest 210
	name : E - Ring MST.cpp
	srcPath : /home/aryan/Documents/cp/E_Ring_MST.cpp
	url : https://atcoder.jp/contests/abc210/tasks/abc210_e
*/
/*
    author : aryan57
    created : 17-July-2021 18:21:30 IST
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


void solve_LOG2(int n,int m)
{

    vector<pair<int,int> > v(m);

    F(i,0,m-1)
    {
        cin>>v[i].Y>>v[i].X;
    }

    sort(all(v));
    int total_components = n;
    int cost=0;
    F(j,0,m-1)
    {
        if(total_components==1)break;
        int reduced_components = __gcd(total_components,v[j].Y);
        cost+=(total_components-reduced_components)*v[j].X;
        total_components=reduced_components;
    }

    if(total_components!=1)cost=-1;
    
    cout<<cost;
    return;
    

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
        int n,m;
        cin>>n>>m;
        solve_LOG2(n,m);
    }
    return 0;
}
//	parsed : 17-July-2021 18:21:06 IST