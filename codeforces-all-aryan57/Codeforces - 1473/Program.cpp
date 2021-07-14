/*
    author : Aryan Agarwal, IIT KGP
    created : 14-January-2021 21:29:18 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007; /*more than 1e9 */ /*7 + 1e9*/
// const int32_t M = 998244353; /*less than 1e9 */   /*1 + 7*17*(1<<23) */
const long double pie = acos(-1);

#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

void solve_LOL()
{
    int n,m;
    cin>>n>>m;

    string s;
    cin>>s;

    vector<pair<int,int> > pre(n+1);
    vector<pair<int,int> > su(n+1);

    vector <int> posp(n+1);
    vector <int> poss(n+1);

    
    int x=0;
    int l=0,r=0;
    F(i,0,n-1)
    {
        if(s[i]=='+')x++;
        else x--;

        l=min(l,x);
        r=max(r,x);

        {pre[i+1]={l,r};
        posp[i+1]=x;}
        

    }

    // reverse(all(s));
    l=r=x;

    RF(i,n-1,0)
    {
        if(s[i]=='+')x--;
        else x++;

        l=min(l,x);
        r=max(r,x);

        poss[n-i]=x;
        su[n-i]={l,r};

    }

    int p,q;

    while(m--)
    {
        cin>>p>>q;

        p--;
        q=n-q;

        int r1=su[q].Y-poss[q];
        int l1=-su[q].X+poss[q];

        int l2=pre[p].X;
        int r2=pre[p].Y;

        l2=min(l2,posp[p]-l1);
        r2=max(r2,posp[p]+r1);

        cout<<r2-l2+1;
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
    // defualt mxn_sieve = 1e5
    sieve();
#endif
#ifdef ARYAN_SEG_SIEVE
    // default [L,R] = [1,1e5]
    segmented_sieve();
#endif
#ifdef ARYAN_FACT
    // default mxn_fact = 1e5
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