/*
	group : Codeforces - Codeforces Round #725 (Div. 3)
	name : A. Stone Game.cpp
	srcPath : /home/aryan/Documents/cp/A_Stone_Game.cpp
	url : https://codeforces.com/contest/1538/problem/0
*/
/*
    author : aryan57
    created : 10-June-2021 20:06:38 IST
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

int f1(int mn,int mx,int n)
{

    int ans=0;
    if(mn>mx)
    {
        swap(mn,mx);
    }

    ans+=mn+1;
    n-=mn+1;
    mx-=mn+1;

    ans+=min(mx+1,n-1-mx+1);

    return ans;
}
int f2(int mn,int mx,int n)
{

    int ans=0;
    if(mn>mx)
    {
        swap(mn,mx);
    }

    ans+=n-1-mx+1;
    n-=n-1-mx+1;

    ans+=min(mn+1,n-1-mn+1);

    return ans;
}

void solve_LOL()
{
    int n;
    cin>>n;

    vector <int> a(n);

    F(i,0,n-1)
    {
        cin>>a[i];
    }

    int mn=min_element(all(a))-a.begin();
    int mx=max_element(all(a))-a.begin();

    int ans=0;

    // dbg(f1(mn,mx,n));
    // dbg(f2(mn,mx,n));

    ans=min(f1(mn,mx,n),f2(mn,mx,n));
    

    cout<<ans;
    cout<<"\n";
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
//	parsed : 10-June-2021 20:06:31 IST