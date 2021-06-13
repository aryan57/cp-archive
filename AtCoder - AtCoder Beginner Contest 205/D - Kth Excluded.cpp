/*
	group : AtCoder - AtCoder Beginner Contest 205
	name : D - Kth Excluded.cpp
	srcPath : /home/aryan/Documents/cp/D_Kth_Excluded.cpp
	url : https://atcoder.jp/contests/abc205/tasks/abc205_d
*/
/*
    author : aryan57
    created : 13-June-2021 17:40:20 IST
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
    int n,q;
    cin>>n>>q;

    vector <int> d(n),a(n);
    vector <int> pre(n);

    F(i,0,n-1)
    {
        cin>>a[i];
        if(i==0)
        {
            d[i]=a[i]-1;
            pre[i]=d[i];
        }
        else
        {
            d[i]=a[i]-a[i-1]-1;
            pre[i]=d[i]+pre[i-1];
        }
    }

    while (q--)
    {
        int k;
        cin>>k;

        int pos=lower_bound(all(pre),k)-pre.begin();

        if(pos<n)
        {
            if(pos==0)
            {
                cout<<k;
                cout<<"\n";
                continue;
            }

            int rem=k-pre[pos-1];

            cout<<a[pos-1]+rem;
            cout<<"\n";
            continue;
        }
        else
        {
            int rem=k-pre[n-1];

            cout<<a[n-1]+rem;
            cout<<"\n";
            continue;
        }
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
//	parsed : 13-June-2021 17:37:43 IST