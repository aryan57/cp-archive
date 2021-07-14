//https://codeforces.com/contest/1547/problem/E

/*
    author : aryan57
    created : 10-July-2021 20:46:53 IST
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
    int n,k;
    cin>>n>>k;

    vector<pair<int,int> > v(k);
    F(i,0,k-1)
    {
        cin>>v[i].X;
        v[i].X--;
    }
    F(i,0,k-1)cin>>v[i].Y;

    sort(all(v));

    vector <int> left(n,INF);
    vector <int> right(n,INF);

    {
        int ind=k-1;
        int mn=INF;
        RF(i,n-1,0)
        {
            if(ind>=0 && i==v[ind].X)
            {
                mn=min(mn,v[ind].X+v[ind].Y);
                ind--;
            }

            right[i]=min(right[i],mn-i);
        }
    }
    {
        int ind=0;
        int mn=INF;
        F(i,0,n-1)
        {
            if(ind<k && i==v[ind].X)
            {
                mn=min(mn,-v[ind].X+v[ind].Y);
                ind++;
            }
            left[i]=min(left[i],mn+i);
        }
    }

    F(i,0,n-1)
    {
        cout<<min(left[i],right[i])<<" ";
    }
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
//	parsed : 10-July-2021 20:07:54 IST