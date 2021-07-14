//https://codeforces.com/contest/1440/problem/C1

/*
    author : Aryan Agarwal, IIT KGP
    created : 02-December-2020 07:34:38 IST
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
void sieve();
vi getFactorization(int x);
bool comp(pii a,pii b){return a.X<b.X;}

const int mxn = 1e5;
int spf[mxn+1]; // spf -> smallest prime factor
int n,m;

bool isin(pii p, pii q,pii r)
{
    if(p.X<0 || q.X<0 || r.X<0)return false;
    if(p.X>=n || q.X>=n || r.X>=n)return false;
    if(p.Y<0 || q.Y<0 || r.Y<0)return false;
    if(p.Y>=m || q.Y>=m || r.Y>=m)return false;

    return true;
}

bool one3(int a,int b,int c)
{
    if(a==b && b==c && c==1)return true;

    return false;
}
bool isin2(pii p, pii q)
{
    if(p.X<0 || q.X<0 )return false;
    if(p.X>=n || q.X>=n )return false;
    if(p.Y<0 || q.Y<0 )return false;
    if(p.Y>=m || q.Y>=m)return false;

    return true;
}

bool one2(int a,int c)
{
    if(a==c && c==1)return true;

    return false;
}

int helpx[] = {-1,0,1,0};
int helpy[] = {0,1,0,-1};
int helpx2[] = {-1,-1,-1,0,1,1,1,0};
int helpy2[] = {-1,0,1,1,1,0,-1,-1};

void solve()
{
    
    cin>>n>>m;

    int a[n][m];

    string s;
    F(i,0,n-1)
    {
        cin>>s;
        F(j,0,m-1)
        {
            a[i][j]=s[j]-'0';
        }
    }

    vector <tuple<pii,pii,pii> > ans;


    F(i,0,n-1)
    {
        F(j,0,m-1)
        {
            if(a[i][j]==0)continue;
            pii p,q,r;
            r.X=i;
            r.Y=j;

            F(k,0,7)
            {
                p=q=r;
                p.X=p.X+helpx2[k];
                p.Y=p.Y+helpy2[k];
                q.X=q.X+helpx2[(k+1)%8];
                q.Y=q.Y+helpy2[(k+1)%8];
                if(isin(p,q,r))
                {
                    if(one3(a[p.X][p.Y],a[q.X][q.Y],a[r.X][r.Y]))
                    {
                        // f3.pb(r);
                        // cout<<"**\n";
                        // cout<<"("<<r.X<<", "<<r.Y<<")";nl;
                        a[p.X][p.Y]=0;
                        a[q.X][q.Y]=0;
                        a[r.X][r.Y]=0;

                        tuple <pii,pii,pii> zz;
                        zz = {p,q,r};
                        ans.pb(zz);
                        break;
                    
                    }
                }
            }

            
        }
    }

    vpii f2;

    F(i,0,n-1)
    {
        F(j,0,m-1)
        {
            if(a[i][j]==0)continue;

            pii p,r;
            r.X=i;
            r.Y=j;
            // dbg(r.X,r.Y);

            F(k,0,7)
            {
                p=r;
                p.X=p.X+helpx2[k];
                p.Y=p.Y+helpy2[k];
                if(isin2(p,r))
                {
                    if(one2(a[p.X][p.Y],a[r.X][r.Y]))
                    {
                        a[p.X][p.Y]=0;
                        a[r.X][r.Y]=0;
                        tuple <pii,pii,pii> zz;
                        if(k==3 || k==7)
                        {
                            pii x1,x2,x3,x4;
                            x1=x3=p;
                            x2=x4=r;

                            x3.X++;
                            x4.X++;
                            if(x3.X==n)x3.X=n-2;
                            if(x4.X==n)x4.X=n-2;

                            zz = {x1,x3,x4};
                            ans.pb(zz);
                            zz = {x2,x3,x4};
                            ans.pb(zz);
                            break;
                        }
                        if(k==1 || k==5)
                        {
                            pii x1,x2,x3,x4;
                            x1=x2=p;
                            x3=x4=r;

                            x2.Y++;
                            x4.Y++;
                            if(x2.Y==m)x2.Y=m-2;
                            if(x4.Y==m)x4.Y=m-2;

                            zz = {x1,x2,x4};
                            ans.pb(zz);
                            zz = {x3,x2,x4};
                            ans.pb(zz);
                            break;
                        }

                        pii x1,x2,x3,x4;
                        int mnx=min(p.X,r.X),mxx=max(p.X,r.X);
                        int mny=min(p.Y,r.Y),mxy=max(p.Y,r.Y);
                        x1={mnx,mny};
                        x2={mnx,mxy};
                        x3={mxx,mny};
                        x4={mxx,mxy};

                        if(k==2 || k==6)
                        {
                            zz = {x1,x2,x4};
                            ans.pb(zz);
                            zz = {x1,x3,x4};
                            ans.pb(zz);
                            break;
                        }
                        if(k==0 || k==4)
                        {
                            zz = {x1,x2,x3};
                            ans.pb(zz);
                            zz = {x2,x4,x3};
                            ans.pb(zz);
                            break;
                        }
                        
                    }
                }
            }

            
        }
    }

    


    F(i,0,n-1)
    {
        F(j,0,m-1)
        {
            if(a[i][j])
            {
                a[i][j]=0;
                tuple <pii,pii,pii> zz;
                pii x1,x2,x3,x4;
                
                if(i+1<n && j+1<m)
                {
                    x1.X=i;x1.Y=j;
                    x2=x3=x4=x1;
                    x2.Y++;
                    x3.X++;
                    x4.X++;x4.Y++;
                }
                else if(i-1>=0 && j-1>=0)
                {
                    x1.X=i;x1.Y=j;
                    x2=x3=x4=x1;
                    x2.Y--;
                    x3.X--;
                    x4.X--;x4.Y--;
                }
                else if(i==0 && j==m-1)
                {
                    x1.X=i;x1.Y=j;
                    x2=x3=x4=x1;
                    x2.Y--;
                    x3.X++;
                    x4.X++;x4.Y--;
                }
                else if(i==n-1 && j==0)
                {
                    // cout<<"**";nl;
                    x1.X=i;x1.Y=j;
                    x2=x3=x4=x1;
                    x2.Y++;
                    x3.X--;
                    x4.X--;x4.Y++;

                    
                }
                // dbg(x3.X,x3.Y);
                zz={x3,x1,x2};
                ans.pb(zz);
                zz={x1,x2,x4};
                ans.pb(zz);
                zz={x1,x3,x4};
                ans.pb(zz);
                
            }
        }
    }

    cout<<sz(ans);nl;
    for(auto x : ans)
    {
        pii p,q,r;
        tie(p,q,r) = x;
        p.X++;p.Y++;
        q.X++;q.Y++;
        r.X++;r.Y++;

        cout<<p.X<<" "<<p.Y<<" "<<q.X<<" "<<q.Y<<" "<<r.X<<" "<<r.Y;nl;
    }
}
  
signed main()
{
    #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    #endif
    fast;
    // sieve();

    int _t;
    cin>>_t;
    while(_t--)
    {
        solve();
        // cout<<"\n";
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

void sieve() // Calculating SPF (Smallest Prime Factor) for every number till mxn.
{ 
    spf[1] = 1; 
    for (int i=2; i<=mxn; i++) 
        spf[i] = i; 
  
    for (int i=4; i<=mxn; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<=mxn; i++) 
    {
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<=mxn; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  
// A O(log n) function returning primefactorization by dividing by smallest prime factor at every step 
vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
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