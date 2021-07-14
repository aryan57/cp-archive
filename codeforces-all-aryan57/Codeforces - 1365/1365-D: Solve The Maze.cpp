//https://codeforces.com/contest/1365/problem/D

/*
    author : Aryan Agarwal, IIT KGP
    created : 07-06-2020 21:56:33
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

#define sf(x) cin>>x
#define pf(x) cout<<x
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
int n,m;
int cnt=0;
vvi visited(50,vi (50,0));

void dfs(vvi &grid,int x,int y)
{
    if(grid[x][y]==3)cnt++;
    visited[x][y]=1;
    
    if(x-1>=0)
    {
        if(grid[x-1][y]%2 && !visited[x-1][y])
        {
            // dbg(x-1,y);
            dfs(grid,x-1,y);
        }
    }
    if(x+1<n)
    {
        if(grid[x+1][y]%2  && !visited[x+1][y])
        {
            // dbg(x+1,y);
            dfs(grid,x+1,y);
        }
    }
    if(y-1>=0)
    {
        if(grid[x][y-1]%2  && !visited[x][y-1])
        {
            // dbg(x,y-1);
            dfs(grid,x,y-1);
        }
    }
    if(y+1<m)
    {
        if(grid[x][y+1]%2  && !visited[x][y+1])
        {
            // dbg(x,y+1);
            dfs(grid,x,y+1);
        }
    }

}

void solve()
{
    // int n,m;
    cnt=0;
    cin>>n>>m;
    vvi grid(n,vi(m));
    vpii gg,bb;
    char c1;
    
    F(i,0,n-1)
    {
        F(j,0,m-1)
        {
            visited[i][j]=0;
            cin>>c1;
            if(c1=='.')grid[i][j]=1;
            if(c1=='#')grid[i][j]=0;
            if(c1=='B')
            {
                grid[i][j]=2;
                bb.pb({i,j});
                
            }
            if(c1=='G')
            {
                grid[i][j]=3;
                gg.pb({i,j});
            }
        }
    }

    if(sz(gg)==0)
    {
        pfy;
        return;
    }

    int x,y;

    F(i,0,sz(bb)-1)
    {
        x=bb[i].X;
        y=bb[i].Y;

        if((x==n-1 && y==m-2) || (x==n-2 && y==m-1))
        {
            pfn;
            return;
        }

        if(x-1>=0)
        {
            if(grid[x-1][y]==3)
            {
                pfn;
                return;
            }
            grid[x-1][y]=0;
        }
        if(x+1<n)
        {
            if(grid[x+1][y]==3)
            {
                pfn;
                return;
            }
            grid[x+1][y]=0;
        }
        if(y-1>=0)
        {
            if(grid[x][y-1]==3)
            {
                pfn;
                return;
            }
            grid[x][y-1]=0;
        }
        if(y+1<m)
        {
            if(grid[x][y+1]==3)
            {
                pfn;
                return;
            }
            grid[x][y+1]=0;
        }
    }

    

    dfs(grid,n-1,m-1);

    // dbg(sz(gg),cnt);
    if(sz(gg)==cnt)
    {
        pfy;
        return;
    }

    pfn;

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