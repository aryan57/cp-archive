/*
	group : Codeforces - Codeforces Round #513 by Barcelona Bootcamp (rated, Div. 1 + Div. 2)
	name : C. Maximum Subrectangle.cpp
	srcPath : /home/aryan/Documents/cp/C_Maximum_Subrectangle.cpp
	url : https://codeforces.com/contest/1060/problem/C
*/
/*
    author : aryan57
    created : 09-June-2021 03:02:00 IST
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
    int n,m;
    cin>>n>>m;

    vector<pair <int,int> > pa;

    vector <int> a(n),b(m);
    F(i,0,n-1)cin>>a[i];
    F(i,0,m-1)cin>>b[i];


    vector <int> pre(m+n+1);
    F(i,1,n)
    {
        pre[i]=pre[i-1]+a[i-1];
    }
    F(i,1,n)
    {
        F(j,i,n)
        {
            pa.push_back({pre[j]-pre[i-1],j-i+1});
        }
    }

    sort(all(pa));
    pre[0]=0;

    vector<int>ppa(sz(pa)),ppind(sz(pa));

    for(int i=0;i<sz(pa);i++)
    {
        ppa[i]=pa[i].X;
        ppind[i]=pa[i].Y;
        if(i)ppind[i]=max(ppind[i],ppind[i-1]);
    }

    F(i,1,m)
    {
        pre[i]=pre[i-1]+b[i-1];
    }

    // dbg(pre);

    int x;
    cin>>x;

    int ans=0;

    F(i,1,m)
    {
        F(j,i,m)
        {
            int lim=x/(pre[j]-pre[i-1]);
            int pos=upper_bound(all(ppa),lim)-ppa.begin();
            pos--;

            if(pos>=0)
            {
                ans=max(ans,ppind[pos]*(j-i+1));
            }
        }
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
//	parsed : 09-June-2021 03:01:52 IST