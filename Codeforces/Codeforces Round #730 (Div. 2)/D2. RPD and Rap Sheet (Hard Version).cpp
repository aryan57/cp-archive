/*
	group : Codeforces - Codeforces Round #730 (Div. 2)
	name : D2. RPD and Rap Sheet (Hard Version).cpp
	srcPath : /home/aryan/Documents/cp/D2_RPD_and_Rap_Sheet_Hard_Version_.cpp
	url : https://codeforces.com/contest/1543/problem/D2
*/
/*
    author : aryan57
    created : 08-July-2021 09:31:53 IST
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

int f(int a,int b,int k)
{
    int ans=0;
    int pw=1;

    while (a || b)
    {
        int bit=0;

        bit+=a%k;
        bit-=b%k;

        bit+=k;
        bit%=k;

        ans+=bit*pw;
        pw*=k;
        a/=k;
        b/=k;
    }

    return ans;
    
}

void solve_LOL()
{
    int n,k;
    cin>>n>>k;

    F(i,1,n)
    {
        if(i==1)cout<<0<<endl;
        else if(i%2)cout<<f(i-1,i-2,k)<<endl;
        else cout<<f(i-2,i-1,k)<<endl;

        int r;
        cin>>r;
        if(r)break;
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
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}
//	parsed : 08-July-2021 09:31:44 IST