//https://codeforces.com/contest/1527/problem/C

/*
    author : aryan57
    created : 21-May-2021 10:03:56 IST
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

int calc(int t)
{
    int k=0;
    k+=(t*(t+1)*(2*t+1))/6;
    k-=(t*(t+1))/2;
    assert(k%2==0 && k>=0);
    k/=2;
    return k;
}

void solve_LOL()
{
    int n;
    cin>>n;

    vector <int> a(n);
    unordered_map<int,int> cnt;
    F(i,0,n-1)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }

    int ans=0;

    unordered_map<int,vector <int> > mp;

    F(i,0,n-1)
    {
        mp[a[i]].push_back(i);
    }
    for(auto p : cnt)
    {
        // mp[p.X].push_back(n);
        vector <int> vec=mp[p.X];
        vector <int> suf(sz(vec));
        suf.back()=n-vec.back();
        RF(i,sz(vec)-2,0)
        {
            suf[i]=suf[i+1]+n-vec[i];
        }
        // dbg(p);
        // dbg(vec);
        for(int i=0;i<=sz(vec)-2;i++)
        {
            
            int l=vec[i]+1;
            int r=suf[i+1];
            // dbg(l,r,suf[i+1]);

            ans+=l*r;

        }

    }

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