/*
	group : AtCoder - AtCoder Beginner Contest 207
	name : C - Many Segments.cpp
	srcPath : /mnt/c/Users/aryan/Desktop/cp/C_Many_Segments.cpp
	url : https://atcoder.jp/contests/abc207/tasks/abc207_c
*/
/*
    author : aryan57
    created : 26-June-2021 17:37:21 IST
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

    vector <int> t(n);
    vector<pair<int,int> > v(n);

    F(i,0,n-1)
    {
        cin>>t[i];
        cin>>v[i].X>>v[i].Y;
    }

    int cnt=0;

    F(i,0,n-1)
    {
        F(j,i+1,n-1)
        {
            long double l1=1.0*v[i].X;
            long double r1=1.0*v[i].Y;
            long double l2=1.0*v[j].X;
            long double r2=1.0*v[j].Y;

            if(t[i]==2)
            {
                r1-=0.0001;
            }
            if(t[i]==3)
            {
                l1+=0.0001;
            }
            if(t[i]==4)
            {
                l1+=0.0001;
                r1-=0.0001;
            }

            if(t[j]==2)
            {
                r2-=0.0001;
            }
            if(t[j]==3)
            {
                l2+=0.0001;
            }
            if(t[j]==4)
            {
                l2+=0.0001;
                r2-=0.0001;
            }

            long double mx1=max(l1,l2);
            long double mx2=min(r1,r2);

            if(mx1<=mx2)
            {
                // dbg(i,j,l1,r1,l2,r2);
                cnt++;
            }
        }
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