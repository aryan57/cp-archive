//https://codeforces.com/contest/1517/problem/B

/*
    author : aryan57
    created : 23-April-2021 20:24:45 IST
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

void solve_LOL()
{
    int n,m;
    cin>>n>>m;

    vector < multiset<int> > b(n+1);

    F(i,1,n)
    {
        F(j,1,m)
        {
            int x;
            cin>>x;
            // dbg(x);
            b[i].insert(x);
        }
    }

    vector <int> ans[m+1];

    F(p,1,m)
    {
        int mn=INF;

        int mnind=-1;

        F(i,1,n)
        {
            if(mn>*b[i].begin())
            {
                mn=*b[i].begin();
                mnind=i;
            }
        }

        F(i,1,mnind-1)
        {
            auto it  = b[i].end();
            it--;
            ans[p].push_back(*it);

            b[i].erase(it);
        }

        ans[p].push_back(*b[mnind].begin());
        b[mnind].erase(b[mnind].begin());

        F(i,mnind+1,n)
        {
            auto it  = b[i].end();
            it--;
            ans[p].push_back(*it);

            b[i].erase(it);
        }
    }

    F(i,1,n)
    {
        F(j,1,m)
        {
            cout<<ans[j][i-1]<<" ";
        }
        cout<<"\n";
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