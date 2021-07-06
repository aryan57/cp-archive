/*
	group : HackerRank - GOC-CDC Series #11
	name : Subarray Beauty.cpp
	srcPath : /home/aryan/Documents/cp/Subarray_Beauty.cpp
	url : https://www.hackerrank.com/contests/goc-cdc-series-11/challenges/subarray-beauty
*/
/*
    author : aryan57
    created : 06-July-2021 10:25:53 IST
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

int cnt[mxn+1]={};
int cnt_mn[mxn+1]={};

void f(int l,int r,vector <int> &v)
{
    if(l>r)return;

    int pos=max_element(v.begin()+l,v.begin()+r+1)-v.begin();

    // dbg(l,r,pos);

    cnt[v[pos]]+=(pos-l+1)*(r-pos+1);

    f(l,pos-1,v);
    f(pos+1,r,v);

}

void f2(int l,int r,vector <int> &v)
{
    if(l>r)return;

    int pos=min_element(v.begin()+l,v.begin()+r+1)-v.begin();

    cnt_mn[v[pos]]+=(pos-l+1)*(r-pos+1);

    f2(l,pos-1,v);
    f2(pos+1,r,v);

}

void solve_LOG()
{
    int n;
    cin>>n;
    vector <int> v(n);
    for(int &x : v)cin>>x;

    f(0,n-1,v);
    f2(0,n-1,v);

    int ans=0;

    F(i,1,mxn)
    {
        ans+=i*(cnt[i]-cnt_mn[i]);
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
//	parsed : 06-July-2021 10:24:19 IST