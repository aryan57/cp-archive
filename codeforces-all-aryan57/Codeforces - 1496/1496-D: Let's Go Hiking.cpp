//https://codeforces.com/contest/1496/problem/D

/*
    tut used
    author : Aryan Agarwal, IIT KGP
    created : 12-March-2021 17:39:04 IST
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

void solve_LOG()
{
    int n;
    cin>>n;

    int a[n+2];
    a[n+1]=a[0]=INF;
    vector <int> hi,lo;

    F(i,1,n)
    {
        cin>>a[i];
    }

    F(i,1,n)
    {
        if(i==1)
        {
            if(a[i]>a[i+1])hi.pb(i);
            if(a[i]<a[i+1])lo.pb(i);
        }
        else if(i==n)
        {
            if(a[i]>a[i-1])hi.pb(i);
            if(a[i]<a[i-1])lo.pb(i);
        }
        else
        {
            if(a[i]>a[i-1] && a[i]>a[i+1])hi.pb(i);
            if(a[i]<a[i-1] && a[i]<a[i+1])lo.pb(i);
        }
    }

    // for(int x :lo)cout<<x<<" ";
    // cout<<"\n";


    vector <int> vec;

    for(int pos:hi)
    {
        int x1=upper_bound(lo.begin(),lo.end(),pos)-lo.begin();
        int x2=lower_bound(lo.begin(),lo.end(),pos)-lo.begin();
        x2--;
        int l1=0,l2=0;

        if(x1<sz(lo))l1=lo[x1]-pos;
        if(x2>=0)l2=pos-lo[x2];

        // dbg(l1,l2,x1,x2,lo[x1],lo[x2],pos);

        vec.pb(l1);
        vec.pb(l2);
    }

    if(sz(vec)==0)
    {
        cout<<0;
        return;
    }

    sort(all(vec),greater<int> ());
    // for(int x : vec)cout<<x<<" ";
    // cout<<"\n";

    int largest=vec[0];

    if((sz(vec)==1) ||  (sz(vec)>2 && largest==vec[2] )|| largest%2 || (largest!=vec[1]))
    {
        cout<<0;
        return;
    }

    for(int pos:hi)
    {
        int x1=upper_bound(lo.begin(),lo.end(),pos)-lo.begin();
        int x2=lower_bound(lo.begin(),lo.end(),pos)-lo.begin();
        x2--;
        int l1=0,l2=0;

        if(x1<sz(lo))l1=lo[x1]-pos;
        if(x2>=0)l2=pos-lo[x2];

        if(l1==l2 && l1==largest)
        {
            cout<<1;
            return;
        }
    }

    cout<<0;

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
    // cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOG();
    }
    return 0;
}