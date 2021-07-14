//https://codeforces.com/contest/1435/problem/C

/*
    // tut used
    author : aryan57
    created : 07-May-2021 15:20:09 IST
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
    int a[6];
    F(i,0,5)
    {
        cin>>a[i];
    }

    int ind=0;
    int n;
    cin>>n;
    vector<pair<int,int> > v(6*n);
    F(i,0,n-1)
    {
        int b;
        cin>>b;

        F(j,0,5)
        {
            v[ind++]={b-a[j],i};
        }
    }

    sort(all(v));

    int last=0;

    vector <int> right(6*n,-1);

    set<int> s;
    multiset<int> ms;

    F(i,0,6*n-1)
    {
        s.insert(v[i].Y);
        ms.insert(v[i].Y);

        if(sz(s)==n)
        {
            right[0]=i;
            last=i;
            break;
        }
    }

    F(i,1,6*n-1)
    {
        ms.erase(ms.find(v[i-1].Y));
        while (last<6*n-1 && ms.find(v[i-1].Y)==ms.end())
        {
            last++;
            ms.insert(v[last].Y);
        }

        if(ms.find(v[i-1].Y)==ms.end())
        {
            break;
        }
        right[i]=last;
    }

    assert(right[0]!=-1);
    // assert(v[0].X<=right[0]);

    int ans=v[right[0]].X-v[0].X;

    F(i,1,6*n-1)
    {
        if(right[i]==-1)break;
        ans=min(ans,v[right[i]].X-v[i].X);
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