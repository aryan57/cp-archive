//https://codeforces.com/contest/1435/problem/B

/*
    author : aryan57
    created : 07-May-2021 12:58:44 IST
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

    vector< vector<int> > r(n,vector <int> (m));
    vector< vector<int> > c(m,vector <int> (n));

    F(i,0,n-1)
    {
        F(j,0,m-1)
        {
            cin>>r[i][j];
        }
    }
    map<int,int> pos;
    set <int> s;
    F(i,0,m-1)
    {
        F(j,0,n-1)
        {
            cin>>c[i][j];
        }
        pos[c[i][0]]=i;
        s.insert(c[i][0]);
    }

    int g[n][m];

    F(i,0,n-1)
    {
        bool ok = true;
        F(j,0,m-1)
        {
            if(s.find(r[i][j])==s.end())
            {
                ok=false;
                break;
            }
        }

        if(!ok)continue;

        vector <int> ind(m);

        F(j,0,m-1)
        {
            int num=r[i][j];
            int new_pos=pos[num];
            ind[j] = new_pos;
        }

        F(k,0,m-1)
        {
            int index=ind[k];
            F(i,0,n-1)
            {
                g[i][k]=c[index][i];
            }
        }

        break;

    }

    F(i,0,n-1)
    {
        F(j,0,m-1)
        {
            cout<<g[i][j]<<" ";
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