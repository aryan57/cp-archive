/*
	group : Codeforces - Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)
	name : D. Lost Tree.cpp
	srcPath : /home/aryan/Documents/cp/D_Lost_Tree.cpp
	url : https://codeforces.com/contest/1534/problem/D
*/
/*
    // credits: @satvikb
    author : aryan57
    created : 14-June-2021 00:18:47 IST
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

    set<pair <int,int> > edges;

    vector <int> o,e;

    cout<<"? 1"<<endl;
    F(i,1,n)
    {
        int x;
        cin>>x;
        if(x==0)continue;
        if(x%2)o.push_back(i);
        else e.push_back(i);

        if(x==1)
        {
            edges.insert({min(1ll,i),max(1ll,i)});
        }
    }

    if(sz(o)>sz(e))
    {
        swap(o,e);
    }

    for(int p : o)
    {
        cout<<"? "<<p<<endl;
        F(i,1,n)
        {
            int x;
            cin>>x;

            if(x==1)
            {
                edges.insert({min(p,i),max(p,i)});
            }
        }
    }

    cout<<"!"<<endl;
    for(auto p : edges)cout<<p.X<<" "<<p.Y<<endl;

}

signed main()
{
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