//https://codeforces.com/contest/1453/problem/C

/*
    author : Aryan Agarwal, IIT KGP
    created : 04-December-2020 21:02:43 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007; /*more than (10)^9*/ /*7 + 1e9*/
// const int32_t M = 998244353; /*less than (10)^9*/   /*1 + 7*17*(2)^23*/
const long double pie = acos(-1);

#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

#define dbg(a) cout<<"["<<#a<<" : "<<a<<"]\n"
#define dbg2(a,b) cout<<"["<<#a<<" : "<<a<<"], "<<"["<<#b<<" : "<<b<<"]\n"
#define dbg3(a,b,c) cout<<"["<<#a<<" : "<<a<<"], "<<"["<<#b<<" : "<<b<<"], "<<"["<<#c<<" : "<<c<<"]\n"

int n;
int g[2000][2000];

int ans[10];

void fun()
{
    vector< vector<int> > f(10,vector <int> (n,-1));
    vector< vector<int> > l(10,vector <int> (n,-1));

    vector <int> fu(10,-1);
    vector <int> lu(10,-1);

    F(i,0,n-1)
    {
        F(j,0,n-1)
        {
            if(fu[g[i][j]]==-1)
            {
                fu[g[i][j]]=i;
            }
            
            lu[g[i][j]]=i;
            
            if(f[g[i][j]][i]==-1)
            {
                f[g[i][j]][i]=j;
            }
            
            l[g[i][j]][i]=j;
            
        }
    }

    F(d,0,9)
    {
        F(i,0,n-1)
        {
            if(f[d][i]==-1)continue;
            int ba,le;
            ba=l[d][i]-f[d][i];
            le=max(i-0,n-1-i);
            ans[d]=max(ans[d],le*ba);

            le=max(abs(fu[d]-i),abs(lu[d]-i));
            ba=0;
            ba=max(ba,abs(f[d][i]-0));
            ba=max(ba,abs(f[d][i]-(n-1)));
            ba=max(ba,abs(l[d][i]-0));
            ba=max(ba,abs(l[d][i]-(n-1)));

            ans[d]=max(ans[d],le*ba);

        }
    }

}

void solve()
{
    cin>>n;

    F(i,0,9)ans[i]=0;

    string s;

    int gg[n][n];

    F(i,0,n-1)
    {
        cin>>s;
        F(j,0,n-1)
        {
            g[i][j]=s[j]-'0';
            gg[i][j]=g[i][j];
        }
    }

    fun();

    // transformation

    F(i,0,n-1)
    {
        F(j,0,n-1)
        {
            g[i][j]=gg[j][i];
        }
    }


    fun();

    F(i,0,9)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
#endif
#ifdef ARYAN_SIEVE
    sieve();
#endif
#ifdef ARYAN_FACT
    fact_init();
#endif
    int _t=1;
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}