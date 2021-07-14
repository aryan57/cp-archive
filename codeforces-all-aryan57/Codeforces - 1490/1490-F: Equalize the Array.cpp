//https://codeforces.com/contest/1490/problem/F

/*
    author : Aryan Agarwal, IIT KGP
    created : 16-February-2021 20:44:50 IST
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


// bool comp(int x,int y)
// {

// }

void solve_LOL()
{
    int n;
    cin>>n;

    // mp.clear();
    map<int,int> mp;
    
    vector <int> a(n);

    set<int> ss;

    int mx=0;
    F(i,0,n-1)
    {
        cin>>a[i];
        mp[a[i]]++;
        mx=max(mx,mp[a[i]]);
        ss.insert(a[i]);
    }

    vector <int> vv;

  

    for(int x :ss)
    {
        vv.pb(mp[x]);
    }

    int m=sz(vv);

    int prevv[m+1]={};

    F(i,0,m-1)
    {
        if(!i)prevv[i]=vv[i];
        else prevv[i]=prevv[i-1]+vv[i];
    }

    sort(all(vv));

    // sort(all(a),comp);

    int ans=n;
    F(c,1,mx)
    {
        int t=0;
        
        int pos=lower_bound(vv.begin(),vv.end(),c)-vv.begin();

        if(pos-1>=0)
        {
            t+=prevv[pos-1];
            t+=n-prevv[pos-1]-c*(m-pos);
        }else{
            t+=n-c*(m-pos);
        }


        // dbg(t);

        ans=min(ans,t);
    }

    cout<<ans;
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