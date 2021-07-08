/*
	group : Codeforces - Educational Codeforces Round 72 (Rated for Div. 2)
	name : B. Zmei Gorynich.cpp
	srcPath : /home/aryan/Documents/cp/B_Zmei_Gorynich.cpp
	url : https://codeforces.com/contest/1217/problem/B
*/
/*
    author : aryan57
    created : 08-July-2021 16:43:54 IST
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

int ceil(int a, int b)
{
    return (a + b - 1) / b;
}

void solve_LOL()
{
    int n,x;
    cin>>n>>x;

    vector <int> d(n),h(n);
    int mx=0;
    bool less=false;
    F(i,0,n-1)
    {
        cin>>d[i]>>h[i];
        mx=max(mx,d[i]);
        if(d[i]>h[i])less=true;
    }

    if(mx>=x)
    {
        cout<<1;
        cout<<"\n";
        return;
    }
    if(!less)
    {
        cout<<"-1\n";
        return;
    }

    int ans=INF;

    F(i,0,n-1)
    {
        if(d[i]<=h[i])continue;

        int t=(x-mx)/(d[i]-h[i]);
        
        F(j,max(0ll,t-5),t+5)
        {
            int rem=x-j*(d[i]-h[i]);
            if(rem<=0 || (rem<=h[i] && j>0))continue;
            int t=j;

            while (rem>0)
            {
                t++;
                if(rem-mx<=0)break;
                rem-=d[i];
                rem+=h[i];
            }

            ans=min(ans,t);
            
        }
    }

    if(ans==INF)ans=-1;

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