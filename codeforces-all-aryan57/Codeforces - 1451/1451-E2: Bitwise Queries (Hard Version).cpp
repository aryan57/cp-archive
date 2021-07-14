//https://codeforces.com/contest/1451/problem/E2

/*
    // tut used
    author : Aryan Agarwal, IIT KGP
    created : 22-November-2020 20:59:35 IST
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
#define int ll

const int INF = (int)2e18;
const int MOD = 1000000007; /*more than (10)^9*/  /*7 + 1e9*/
const int PEG = 998244353; /*less than (10)^9*/   /*1 + 7*17*(2)^23*/
long double pie=acos(-1);

typedef vector< int > vi;
typedef vector< string > vs;
typedef vector< vi > vvi;
typedef pair< int, int > pii;
typedef vector< pii > vpii;
#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
#define tr(c,it) for(auto it=(c).begin();it!=(c).end();it++)

#define F(i,a,b) for(int i=a;i<=b;i++)
#define RF(i,a,b) for(int i=a;i>=b;i--)
#define Fo(i,a,b,j) for(int i=a;i<=b;i+=j)
#define RFo(i,a,b,j) for(int i=a;i>=b;i-=j)
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

ll binpow(ll x,ll y,ll p); // O(log y)
ll nCr(ll n,ll r,ll p); // min(O(r),O(n-r))
ll gcd(ll a, ll b); // __gcd doesn't work for big no.s
ll ceil(ll a,ll b);

bool comp(pii a,pii b){return a.X<b.X;}

const int mxn = 1e5;

signed main()
{
    #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    #endif
    // fast;

    int n;
    cin>>n;

    int xorr[n+1];
    int cnt[n+1]={};
    int arr[n+1];
    xorr[1]=0;
    cnt[0]=1;
    bool ok = false;
    int j=-1;
    bool ok2 = false;
    int j2=-1;
    F(i,2,n)
    {
        cout<<"XOR 1 "<<i<<endl;
        cin>>xorr[i];

        if(xorr[i]==n-1)j2=i;

        if(cnt[xorr[i]] && !ok)
        {
            // case 1
            j=cnt[xorr[i]];
            cout<<"AND "<<i<<" "<<j<<endl;
            cin>>arr[i];
            arr[j]=arr[i];
            ok=true;
        }
        else cnt[xorr[i]]=i;
    }

    if(ok)
    {
        F(i,1,n)
        {
            arr[i]=xorr[i]^xorr[j]^arr[j];
        }
    }
    else
    {
        int x,y,z;
        int a,b;
        int t1,t2;

        
    
        if(j2!=2)
        {
            a=xorr[2];
            t1=a;
            cout<<"AND 1 2"<<endl;
            cin>>b;
            x=a+2*b;
            
            a=xorr[2]^xorr[j2];
            cout<<"AND 2 "<<j2<<endl;
            cin>>b;
            t2=a;
            y=a+2*b;

            a=xorr[j2];
            b=0;
            z=a+2*b;
        }
        else
        {
            a=xorr[3];
            t1=a;
            cout<<"AND 1 3"<<endl;
            cin>>b;
            x=a+2*b;
            
            a=xorr[3]^xorr[j2];
            cout<<"AND 3 "<<j2<<endl;
            cin>>b;
            t2=a;
            y=a+2*b;

            a=xorr[j2];
            b=0;
            z=a+2*b;
        }
        
        
    
        
    
        arr[1]=(x-y+z)/2;
        arr[2]=(x+y-z)/2;
        arr[j2]=(-x+y+z)/2;

        F(i,1,n)
        {
            arr[i]=arr[1]^xorr[i];
        }
    }
    

    cout<<"! ";
    F(i,1,n)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}

/* ########## TIPS ##########
#   
#   if you want to use lower/upper bound in vector/set/multiset of pairs,
#   pass comp function in 4th parameter,
#   and use a pair in 34d parameter.
#
#   ceil(((1.0)*a)/b) is same as (a+b-1)/b
#   don't use ceil() function, since it returns double values,
#   it has some precision errors and doesn't work for large no.s
#
#   while using ceil() function,always type cast the parameters to double like ceil((1.0*a)/b)
#
#   mod_inverse(n,p) is binpow(n,p-2,p)
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

ll gcd(ll a, ll b) /*__gcd doesn't work for big no.s*/
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll ceil(ll a,ll b)
{
    return (a+b-1)/b;
}

ll nCr(ll n,ll r,ll p) // O(r) -> Returns nCr % p using Fermat's little theorem.
{
    if(r>n-r)
    {
        r=n-r;
    }
    if (r == 0)
    {
        return 1;
    }

    ll num2=1,num1=1,ans=1;

    for(int i=1;i<=r;i++)
    {
        num1*=(n+1-i)%p;
        num1%=p;
        num2*=i%p;
        num2%=p;
    }
    
    ans*=num1;
    ans%=p;
    ans*=binpow(num2,p-2,p);
    ans%=p;
    return ans;
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