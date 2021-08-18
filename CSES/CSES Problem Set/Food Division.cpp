/*
	group : CSES - CSES Problem Set
	name : Food Division.cpp
	srcPath : /mnt/c/Users/aryan/Desktop/cp/Food_Division.cpp
	url : https://cses.fi/problemset/task/1189/
*/
/*
    author : aryan57
    created : 01-July-2021 12:11:50 IST
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
    int n;
    cin>>n;

    vector <int> a(n),b(n);

    F(i,0,n-1)
    {
        cin>>a[i];
    }
    
    vector <int> pre_copy(n);
    F(i,0,n-1)
    {
        cin>>b[i];
        b[i]-=a[i];
        if(i)b[i]+=b[i-1];

        pre_copy[i]=b[i];
    }

    sort(all(pre_copy));

    set<int> s;

    if(n%2)s.insert(n/2);
    else
    {
        s.insert(n/2-1);
        s.insert(n/2);
    }

    // dbg(pre_copy);
    

    int ans=INF;
    for(int ind : s)
    {
        if(ind<0 || ind>=n)continue;

        int mid=pre_copy[ind];
        int t=0;
        // dbg(mid);
        for(int x : pre_copy)
        {
            t+=abs(mid-x);
        }
        // dbg(t);

        ans=min(ans,t);
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