//https://codeforces.com/contest/1132/problem/C

/*
    author : aryan57
    created : 29-April-2021 13:06:29 IST
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

const int mxn = 5000;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

void solve_LOG()
{
    int n,q;
    cin>>n>>q;


    vector<pair<int,int> > v(q);

    int val[mxn+1]={};

    F(i,0,q-1)
    {
        cin>>v[i].X>>v[i].Y;
        F(j,v[i].X,v[i].Y)
        {
            val[j]++;
        }
    }

    int s=0;

    int pre1[mxn+1]={};
    int pre2[mxn+1]={};

    F(i,1,mxn)
    {
        pre1[i]=pre1[i-1]+(val[i]==1?1:0);
        pre2[i]=pre2[i-1]+(val[i]==2?1:0);

        if(val[i])s++;
    }

    // dbg(s);
    int ans=-INF;
    F(i,0,q-1)
    {
        F(j,i+1,q-1)
        {
            int l1=v[i].X;
            int r1=v[i].Y;
            int l2=v[j].X;
            int r2=v[j].Y;

            int minus=0;

            minus+=pre1[r1]-pre1[l1-1];
            minus+=pre1[r2]-pre1[l2-1];

            int l=max(l1,l2);
            int r=min(r1,r2);

            if(l<=r){
                minus+=pre2[r]-pre2[l-1];
            }

            assert(minus>=0);

            // dbg(i,j,l1,r1,l2,r2,l,r,minus,ans);

            ans=max(ans,s-minus);
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