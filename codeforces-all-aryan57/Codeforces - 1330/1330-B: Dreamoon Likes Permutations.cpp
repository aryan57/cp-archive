//https://codeforces.com/contest/1330/problem/B

/*
    author : Aryan Agarwal, IIT KGP
    created : 24-June-2020 15:58:36
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
#define int ll

const int INF=(int)2e18;
const int MOD = 1000000007; /*more than (10)^9*/  /*7 + 1e9*/
const int PEG = 998244353; /*less than (10)^9*/   /*1 + 7*17*(2)^23*/
long double pie=acos(-1);

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int, int > pii;
typedef vector< pii > vpii;
#define X first
#define Y second
#define pb push_back
#define sz(a) (ll)(a).size()
#define all(a) (a).begin(),(a).end()

#define F(i,a,b) for(ll i=a;i<=b;i++)
#define RF(i,a,b) for(ll i=a;i>=b;i--)
#define Fo(i,a,b,j) for(ll i=a;i<=b;i+=j)
#define RFo(i,a,b,j) for(ll i=a;i>=b;i-=j)
#define in(a,n) F(i,0,n-1)cin>>a[i]
#define in1(a,n) F(i,1,n)cin>>a[i]
#define out(a,n) F(i,0,n-1)cout<<a[i]<<" "
#define out1(a,n) F(i,1,n)cout<<a[i]<<" "

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define popcount __builtin_popcountll

#define pfy cout<<"YES"
#define pfn cout<<"NO"
#define pfn1 cout<<"-1"  // printf negative 1
#define pf1 cout<<"1"
#define nl cout<<"\n"

#define watch(x) cout<<#x<<" is "<<x<<"\n"
#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name,Arg1&& arg1);
template <typename Arg1,typename... Args>void __f(const char* names,Arg1&& arg1,Args&&... args);

ll binpow(ll x,ll y,ll p);

void solve()
{
    int n;
    cin>>n;
    int a[n];
    int cnt[n]={};

    F(i,0,n-1)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }

    bool zer=false;
    bool one=false;
    int last=0;

    if(cnt[1]!=2)
    {
        cout<<0;
        cout<<"\n";
        return;
    }
    int last2=0;
    F(i,1,n-1)
    {
        if(cnt[i]==2)
        {
            last=i;
        }
        if(cnt[i]>0)
        {
            last2=i;
        }
        
        if(cnt[i]==0)zer=true;
        if(cnt[i]==1)one=true;

        if(cnt[i]>0 && zer)
        {
            cout<<0;
        cout<<"\n";
            return;
        }

        if(cnt[i]>2)
        {
            cout<<0;
        cout<<"\n";
            return;
        }
        
        if(cnt[i]==2 && one)
        {
            cout<<0;
        cout<<"\n";
            return;
        }
    }

    int cntp1[n]={};
    int cntp2[n]={};

    vpii vec;
    F(i,0,last-1)cntp1[a[i]]++;
    F(i,last,n-1)cntp2[a[i]]++;

    bool ok=true;
    F(i,1,last){if(cntp1[i]!=1){ok=false;break;}}
    F(i,1,last2){if(cntp2[i]!=1){ok=false;break;}}
    if(ok)vec.pb({last,last2});

    // dbg(ok,last);


    int cntp3[n]={};
    int cntp4[n]={};

    F(i,0,last2-1)cntp4[a[i]]++;
    F(i,last2,n-1)cntp3[a[i]]++;

    ok=true;
    F(i,1,last2){if(cntp4[i]!=1){ok=false;break;}}
    F(i,1,last){if(cntp3[i]!=1){ok=false;break;}}
    if(ok && last2!=last)vec.pb({last2,last});

    // out1(cntp1,last);nl;
    // out1(cntp2,last2);nl;
    
    // dbg(ok,last2);

    cout<<vec.size();
        cout<<"\n";
    if(vec.size()>0)
    {
        F(i,0,vec.size()-1)
        {
            cout<<vec[i].X<<" "<<vec[i].Y;nl;
        }
    }

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
#   if you want to insert an integer and a pair in a set then,
#   set <pair<int,int>,int> is wrong
#   set< pair < pii,int> > is correct                       // according to my macros
#   set < pair<pair<int,int> , int> > is correct            // pair of a pair & a integer
#
#   if you want just the sum of smallest k elements of a array
#   use nth_element(arr,arr+n) ,
#         use nth_element(arr,arr+n,greater <int> ()) if you want largest k elements
#   then take sum of first k elements ,it works in O(n) ,
#   rather than first sorting then taking sum of first k elements, which works in O(n*logn)
#
#   if you want to check that a given no. 'N' is power of 2
#   use N&(N-1)==0  ,   rather than log2(N)==ceil(log2(N))
#
#   upper_bound is > val in a non-decreasing array
#   lower_bound is >= val in a non-decreasing array
#   upper_bound is < val in a non-increasing array (use greater <int> () in 4th parameter) 
#   lower_bound is <= val in a non-increasing array (use greater <int> () in 4th parameter) 
#   
#   don't use stoi() , it doesn't works for large strings
#   use stoi() to convert string to integer, (2nd & 3rd parameter are optional)
#   1st parameter is string (address of char array)
#   2nd parameter is starting index, 0 most of the times
#   3rd parameter is base of integer, like 2 (for binary no.s), 10 (for decimel no.s) etc.
#
#   for creating a string 'S' of length 'len' , having each character 'c'
#   type    string S(len,c);    while creating the string
#
#   gcd(x-y,x)=gcd(x,y)=gcd(x+y,y)      (for all x and y)
#   gcd(a,b)=gcd(b,a)                   (for all a and b)
#
#   a+b = a|b + a&b
#   a+b = a^b + 2*(a&b)
#   x<<y = x*(2^y)
#   x>>y = x/(2^y)
#
*/

ll binpow(ll x, ll y, ll p) /* (x^y)%p in O(log y) */
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    std::cout << name << " : " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    std::cout.write(names, comma - names) << " : " << arg1 << "\n";
    __f(comma + 1, args...);
}