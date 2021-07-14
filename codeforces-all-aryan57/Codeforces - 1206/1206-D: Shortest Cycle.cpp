//https://codeforces.com/contest/1206/problem/D

/*
    author : Aryan Agarwal, IIT KGP
    created : 20-June-2020 19:40:21
    // solution and tutorial used
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

vvi gr;

// Function to find the length of 
// the shortest cycle in the graph 
int shortest_cycle(int n) 
{ 
    // To store length of the shortest cycle 
    int ans = LONG_LONG_MAX; 
  
    // For all vertices 
    for (int i = 0; i < n; i++) { 
  
        // Make distance maximum 
        vector<int> dist(n, (int)(1e18)); 
  
        // Take a imaginary parent 
        vector<int> par(n, -1); 
  
        // Distance of source to source is 0 
        dist[i] = 0; 
        queue<int> q; 
  
        // Push the source element 
        q.push(i); 
  
        // Continue until queue is not empty 
        while (!q.empty()) { 
  
            // Take the first element 
            int x = q.front(); 
            q.pop(); 
  
            // Traverse for all it's childs 
            for (int child : gr[x]) { 
  
                // If it is not visited yet 
                if (dist[child] == (int)(1e18)) { 
  
                    // Increase distance by 1 
                    dist[child] = 1 + dist[x]; 
  
                    // Change parent 
                    par[child] = x; 
  
                    // Push into the queue 
                    q.push(child); 
                } 
  
                // If it is already visited 
                else if (par[x] != child and par[child] != x && (dist[x] + dist[child] + 1>=3)) 
                    ans = min(ans, dist[x] + dist[child] + 1); 
            } 
        } 
    } 
  
    // If graph contains no cycle 
    if (ans == LONG_LONG_MAX) 
        return -1; 
  
    // If graph contains cycle 
    else
        return ans; 
}

signed main()
{
    #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    #endif
    fast;

    int n;
    cin>>n;

    int a[n];
    vi nz;
    int sznz=0;
    F(i,0,n-1)
    {
        cin>>a[i];
        if(a[i]){nz.pb(a[i]);sznz++;}
    }

    if(sznz>120)
    {
        cout<<3;
        return 0;
    }

    gr.resize(sznz);

    int temp=0;
    F(i,0,sznz-1)
    {
        F(j,i+1,sznz-1)
        {
            if((nz[i]&nz[j])!=0)
            {
                gr[i].pb(j);
                gr[j].pb(i);
                temp++;
            }
        }
    }
    // watch(temp);
    // F(i,0,sznz-1)
    // {
    //     cout<<i<<" --> ";
    //     F(j,0,sz(gr[i])-1)
    //     {
    //         cout<<gr[i][j]<<" ";
    //     }nl;
    // }
    cout << shortest_cycle(sznz); 

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