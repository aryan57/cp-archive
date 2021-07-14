//https://codeforces.com/contest/1535/problem/E

/*
    author : aryan57
    created : 05-June-2021 03:30:55 IST
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

const int mxn = 3e5;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

const int mxbit=20;
vector< vector<int> > par(mxn+1,vector <int> (mxbit+1,-1));

void solve_LOG()
{
    int q,a0,c0;
    cin>>q>>a0>>c0;

    vector <int> a(q+1);
    vector <int> c(q+1);
    a[0]=a0;
    c[0]=c0;

    F(i,1,q)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int p,aa,cc;
            cin>>p>>aa>>cc;
            a[i]=aa;
            c[i]=cc;

            par[i][0]=p;

            F(bit,1,mxbit)
            {
                if(par[i][bit-1]==-1)break;
                par[i][bit]=par[par[i][bit-1]][bit-1];
            }
        }
        else
        {
            int v,w;
            cin>>v>>w;
            int cost=0;
            int ww=w;
            while (true)
            {
                int cur = v;

                for(int bit=mxbit;bit>=0;bit--)
                {
                    if(par[cur][bit]==-1)continue;
                    if(a[par[cur][bit]]==0)continue;

                    cur=par[cur][bit];
                    bit=mxbit+1;
                }
                
                if(a[cur]>=w)
                {
                    a[cur]-=w;
                    cost+=w*c[cur];
                    w=0;
                    break;
                }else
                {
                    cost+=a[cur]*c[cur];
                    w-=a[cur];
                    a[cur]=0;
                }
                if(cur==v)break;
            }
            
            cout<<ww-w<<" "<<cost;
            cout<<endl;

        }
    }
    
}

signed main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
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
//	parsed : 05-June-2021 03:30:45 IST