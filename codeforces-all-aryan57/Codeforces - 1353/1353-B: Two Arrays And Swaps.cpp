//https://codeforces.com/contest/1353/problem/B

/*
    author : Aryan Agarwal, IIT KGP
    created : 14-05-2020 20:11:59
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
#define int ll

const int MOD = 1000000007; /*more than (10)^9*/  /*7 + 1e9*/
const int PEG = 998244353; /*less than (10)^9*/   /*1 + 7*17*(2)^23*/
long double pie=acos(-1);

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair<int, int>	pii;
typedef vector<pii>		vpii;
#define X first
#define Y second
#define pb push_back
#define sz(a) (ull)(a).size()
#define all(a) (a).begin(),(a).end()

#define F(i,a,b) for (ll i=a;i<=b;i++)
      #define RF(i,a,b) for(ll i=a;i>=b;i--)
      #define in(a,n) F(i,0,n-1)cin>>a[i]
#define in1(a,n) F(i,1,n)cin>>a[i]
#define out(a,n) F(i,0,n-1)cout<<a[i]<<" "
#define out1(a,n) F(i,1,n)cout<<a[i]<<" "

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define sf(x) cin>>x
#define pf(x) cout<<x
#define pfy cout<<"YES"
#define pfn cout<<"NO"
#define pfn1 cout<<"-1"  // printf negative 1
#define pf1 cout<<"1"
#define nl cout<<"\n"

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name,Arg1&& arg1){std::cout<<name<<" : "<<arg1<<endl;}template <typename Arg1,typename... Args>void __f(const char* names,Arg1&& arg1,Args&&... args){const char* comma=strchr(names+1, ',');std::cout.write(names,comma-names)<<" : "<<arg1<<"\n";__f(comma+1,args...);}

ll binpow(ll x,ll y,ll p);

void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n],b[n];
    in(a,n);
    in(b,n);

    sort(a,a+n);
    sort(b,b+n,greater <int> ());

    int ans=0;
    F(i,0,k-1)
    {
        ans+=max(a[i],b[i]);
        // cout<<ans<<" ";
    }
    // nl;
    F(i,k,n-1)
    {
        ans+=a[i];
        // cout<<ans<<" ";
    }
    // nl;

    cout<<ans;
}
  
signed main()
{
    #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    #endif
    fast;

    int _t;
    cin>>_t;
    while(_t--)
    {
        solve();
        cout<<"\n";
    }

    return 0;
}

/* ########## TIPS ##########
#
#   mod_inverse(n,p) is binpow(n,p-2,p)
#
#   while using ceil() function,always type cast the parameters to double like ceil((1.0*a)/b)
#
#   for creating a 2d vector "vec" with n rows & m columns then initialise it with it 0
#   vvi vec(n,vi(m,0))
#   vector<vector<int> > vec( n , vector<int> (m, 0))
#
*/

ll binpow(ll x,ll y,ll p)/* (x^y)%p in O(log y) */
{
    ll res=1;
    x=x%p;
    while (y > 0)
    {
        if(y&1)res=(res*x)%p;
        y = y>>1;
        x=(x*x)%p;
    }
    return res;
}