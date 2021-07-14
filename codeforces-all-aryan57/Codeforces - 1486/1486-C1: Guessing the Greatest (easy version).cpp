//https://codeforces.com/contest/1486/problem/C1

/*
    author : Aryan Agarwal, IIT KGP
    created : 18-February-2021 21:01:16 IST
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

// int a[mxn+1]={};
int ans;

map<pair <int,int>,int > s;


void fun(int l,int r)
{
    if(l>r)
    {
        return;
    }
    if(l==r)
    {
        ans=l;
        return;
    }
    
    int m=(l+r)/2;
    int pos;
    if(s.find({l,r})==s.end())
    {
        cout<<"? "<<l<<" "<<r;
        cout<<endl;
        cin>>pos;
        s[{l,r}]=pos;

    }
    pos=s[{l,r}];

    if(r-l+1==2)
    {
        if(pos==l)ans=r;
        else ans=l;

        return;

    }
    
    
    int posy;
    if(s.find({m,r})==s.end())
    {
        cout<<"? "<<m<<" "<<r;
        cout<<endl;
        cin>>posy;
        s[{m,r}]=posy;

    }
    posy=s[{m,r}];

    int posx;
    if(s.find({l,m})==s.end())
    {
        cout<<"? "<<l<<" "<<m;
        cout<<endl;
        cin>>posx;
        s[{l,m}]=posx;

    }
    posx=s[{l,m}];

    if(posy==pos)
    {
        fun(m,r);
        return;
    } 
    if(posx==pos)
    {
        fun(l,m);
        return;
    } 

    if(pos>=m)
    {
        fun(l,m);
        return;

    }
    fun(m,r);


    

    

    

    // if(posx==pos)
    // {
    //     fun(l,m);
    // }
    // else if(posy==pos)
    // {
    //     fun(m,r);
    // }
    // else if(pos<=m)
    // {
    //     fun(m,r);
    // }
    // else 
    // {
    //     fun(l,m);
    // }

    
        
    


    
    
}


void solve_LOG()
{
    int n;
    cin>>n;
    fun(1,n);

    cout<<"! "<<ans;
    cout<<endl;
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
    // cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOG();
    }
    return 0;
}