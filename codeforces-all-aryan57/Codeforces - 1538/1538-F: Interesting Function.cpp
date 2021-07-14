//https://codeforces.com/contest/1538/problem/F

/*
    author : aryan57
    created : 10-June-2021 20:30:39 IST
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

int fun(int k)
{
    string z1=to_string(k);
    string z2=to_string(k+1);

    if(sz(z1)<sz(z2))
    {
        z1='0'+z1;
    }

    assert(sz(z1)==sz(z2));

    int cnt=0;

    F(i,0,sz(z1)-1)
    {
        cnt+=(z1[i]!=z2[i]);
    }

    return cnt;
}

int f1(int a)
{
    int sz=0;

    int ans=0;

    while (a)
    {
        sz=sz*10+1;
        ans+=(a%10)*sz;
        a/=10;
    }

    return ans;
    
}

void solve_LOL()
{
    int l,r;
    cin>>l>>r;

    int a=f1(r);
    int b=f1(l);

    // dbg(a,b);

    cout<<a-b;
    cout<<"\n";

    // int ans=0;

    // while (l<r)
    // {
    //     dbg(l,fun(l));
    //     ans+=fun(l);
    //     if(l==1 || l==10 || l==10 || l==1000 || l==2000)cout<<ans<<" ";
    //     l++;
    // }

    // cout<<"\n";
    // cout<<ans;
    // cout<<"\n";
    
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
//	parsed : 10-June-2021 20:30:29 IST