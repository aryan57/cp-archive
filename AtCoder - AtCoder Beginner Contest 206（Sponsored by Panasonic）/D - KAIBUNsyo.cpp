/*
	group : AtCoder - AtCoder Beginner Contest 206（Sponsored by Panasonic）
	name : D - KAIBUNsyo.cpp
	srcPath : /home/aryan/fdsms/D_KAIBUNsyo.cpp
	url : https://atcoder.jp/contests/abc206/tasks/abc206_d
*/
/*
    author : aryan57
    created : 19-June-2021 17:40:07 IST
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

const int mxn = 2e5;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

void solve_LOG()
{
    int n;
    cin>>n;

    vector <int> a(n);

    vector<set <int>> pos(mxn+1);

    F(i,0,n-1)
    {
        cin>>a[i];
        pos[a[i]].insert(i);
    }

    int p=0;
    int q=n-1;
    int cnt=0;
    while (p<q)
    {
        if(a[p]==a[q])
        {
            p++;
            q--;
            continue;
        }

        int x=a[p];
        int y=a[q];

        if(sz(pos[a[p]])>sz(pos[a[q]]))swap(x,y);

        for(auto it =pos[x].begin();it!=pos[x].end();it++)
        {
            a[*it]=y;
            pos[y].insert(*it);
        }


        p++;
        q--;
        cnt++;
    }

    cout<<cnt;
    
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
//	parsed : 19-June-2021 17:39:50 IST