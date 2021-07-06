/*
	group : HackerRank - GOC-CDC Series #11
	name : Maximum Balance Sequence.cpp
	srcPath : /home/aryan/Documents/cp/Maximum_Balance_Sequence.cpp
	url : https://www.hackerrank.com/contests/goc-cdc-series-11/challenges/maximum-balance-sequence
*/
/*
    author : aryan57
    created : 06-July-2021 09:52:48 IST
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
    int n,x;
    cin>>n>>x;

    vector <int> v(n+1);
    vector <int> pre(n+1);
    vector <int> suf(n+2);

    map <int,set<int> > pos; 

    F(i,1,n)
    {
        cin>>v[i];
        pre[i]+=pre[i-1];
        if(v[i]>x)pre[i]++;
        if(v[i]<x)pre[i]--;
    }

    RF(i,n,1)
    {
        suf[i]+=suf[i+1];
        if(v[i]>x)suf[i]++;
        if(v[i]<x)suf[i]--;

        pos[suf[i]].insert(i);
    }

    int ans=0;

    F(i,1,n)
    {
        if(pre[i]==0)ans=max(ans,i);
        if(suf[i]==0)ans=max(ans,n+1-i);

        auto it = pos[-pre[i]].upper_bound(i);

        if(it!=pos[-pre[i]].end())
        {
            ans=max(ans,i+(n+1-*it));
            // dbg(i,*it,i+(n+1-*it));
        }
    }

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
//	parsed : 06-July-2021 09:49:50 IST