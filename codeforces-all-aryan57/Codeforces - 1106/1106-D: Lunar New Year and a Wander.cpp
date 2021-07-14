//https://codeforces.com/contest/1106/problem/D

/*
    author : Aryan Agarwal, IIT KGP
    created : 09-06-2020 20:12:47
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

// int cnnt=0;
// vvi adj;
// int n,m;

// vector<bool> visited;

// vi anss;

// Function to print the smallest lexicographically 
// BFS path starting from 1 
void printLexoSmall(vector<int> adj[], int n) 
{ 
    // Visited array 
    bool vis[n + 1]; 
    memset(vis, 0, sizeof vis); 
  
    // Minimum Heap 
    priority_queue<int, vector<int>, greater<int> > Q; 
  
    // First one visited 
    vis[1] = true; 
    Q.push(1); 
  
    // Iterate till all nodes are visited 
    while (!Q.empty()) { 
  
        // Get the top element 
        int now = Q.top(); 
  
        // Pop the element 
        Q.pop(); 
  
        // Print the current node 
        cout << now << " "; 
  
        // Find adjacent nodes 
        for (auto p : adj[now]) { 
  
            // If not visited 
            if (!vis[p]) { 
  
                // Push 
                Q.push(p); 
  
                // Mark as visited 
                vis[p] = true; 
            } 
        } 
    } 
}

signed main()
{
    #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    #endif
    fast;

    int n,m;
    cin>>n>>m;

    vector<int> adj[n + 1]; 
    // visited.resize(n);

    // F(i,0,n-1)
    // {
    //     visited[i]=false;
    // }

    int x,y;

    F(i,0,m-1)
    {
        cin>>x>>y;
        // x--;y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    // anss.pb(0);
    printLexoSmall(adj, n); 

    // F(i,0,n-1)
    // {
    //     visited[i]=false;
    // }

    // F(i,0,sz(anss)-1)
    // {
    //     if(!visited[anss[i]]){cout<<anss[i]+1<<" ";visited[anss[i]]=true;}
    // }

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