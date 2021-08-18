/*
	group : AtCoder - AtCoder Beginner Contest 208
	name : C - Fair Candy Distribution.cpp
	srcPath : /home/aryan/Documents/cp/C_Fair_Candy_Distribution.cpp
	url : https://atcoder.jp/contests/abc208/tasks/abc208_c
*/
/*
    author : aryan57
    created : 04-July-2021 17:40:39 IST
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

void solve_LOG()
{
    int n,k;
    cin>>n>>k;

    vector<pair<int,int> > v(n);

    F(i,0,n-1)
    {
        cin>>v[i].X;
        v[i].Y=i;
    }

    sort(all(v));

    vector <int> ans(n);
    int rem=k-n*(k/n);
    F(i,0,n-1)
    {
        if(rem>0)
        {
            ans[v[i].Y]=k/n+1;
            rem--;
        }
        else
        {
            ans[v[i].Y]=k/n;

        }
    }

    for(int x : ans)
    {
        cout<<x;
        cout<<"\n";
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
    // cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOG();
    }
    return 0;
}
//	parsed : 04-July-2021 17:34:52 IST