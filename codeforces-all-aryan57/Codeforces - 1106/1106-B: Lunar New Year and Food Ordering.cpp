//https://codeforces.com/contest/1106/problem/B

/*
    author : Aryan Agarwal, IIT KGP
    created : 09-06-2020 19:30:22
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

bool comp(pii a, pii b)
{
    if(a.X!=b.X)return a.X<b.X;
    else return a.Y<b.Y;
}

/*         n --> No. of elements present in input array.  
    BITree[0..n] --> Array that represents Binary Indexed Tree. 
    arr[0..n-1] --> Input array for which prefix sum is evaluated. */
  
// Returns sum of arr[0..index]. This function assumes 
// that the array is preprocessed and partial sums of 
// array elements are stored in BITree[]. 
int getSum(int BITree[], int index) 
{ 
    int sum = 0; // Iniialize result 
  
    // index in BITree[] is 1 more than the index in arr[] 
    index = index + 1; 
  
    // Traverse ancestors of BITree[index] 
    while (index>0) 
    { 
        // Add current element of BITree to sum 
        sum += BITree[index]; 
  
        // Move index to parent node in getSum View 
        index -= index & (-index); 
    } 
    return sum; 
} 
  
// Updates a node in Binary Index Tree (BITree) at given index 
// in BITree. The given value 'val' is added to BITree[i] and  
// all of its ancestors in tree. 
void updateBIT(int BITree[], int n, int index, int val) 
{ 
    // index in BITree[] is 1 more than the index in arr[] 
    index = index + 1; 
  
    // Traverse all ancestors and add 'val' 
    while (index <= n) 
    { 
    // Add 'val' to current node of BI Tree 
    BITree[index] += val; 
  
    // Update index to that of parent in update View 
    index += index & (-index); 
    } 
} 
  
// Constructs and returns a Binary Indexed Tree for given 
// array of size n. 
int *constructBITree(int arr[], int n) 
{ 
    // Create and initialize BITree[] as 0 
    int *BITree = new int[n+1]; 
    for (int i=1; i<=n; i++) 
        BITree[i] = 0; 
  
    // Store the actual values in BITree[] using update() 
    for (int i=0; i<n; i++) 
        updateBIT(BITree, n, i, arr[i]); 
  
    // Uncomment below lines to see contents of BITree[] 
    //for (int i=1; i<=n; i++) 
    //     cout << BITree[i] << " "; 
  
    return BITree; 
} 

signed main()
{
    #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    #endif
    fast;

    int n,m;
    cin>>n>>m;

    int a[n],c[n];
    vpii r(n);

    F(i,0,n-1)
    {
        cin>>a[i];
        // r[i].X=a[i];
        // r[i].Y=i;
    }
    F(i,0,n-1)
    {
        cin>>c[i];
        r[i].X=c[i];
        r[i].Y=i;
    }
    // in(c,n);

    sort(all(r),comp);

    int t,d;

    int st=0;

    while (m--)
    {
        cin>>t>>d;
        t--;
        if(a[t]>=d)
        {
            a[t]-=d;
            cout<<c[t]*d;
            nl;continue;
        }

        int ans=0;

        ans+=a[t]*c[t];
        d-=a[t];
        a[t]=0;
        // watch(ans);
        
        int flag=0;
        F(i,st,n-1)
        {
            if(a[r[i].Y]>=d)
            {
                a[r[i].Y]-=d;
                cout<<ans+c[r[i].Y]*d;nl;
                flag=1;
                break;
            }
            ans+=a[r[i].Y]*c[r[i].Y];
            d-=a[r[i].Y];
            a[r[i].Y]=0;
            st=i+1;
            // watch(ans);
            // if(d==0){cout<<ans;nl;flag=1;break;}
        }

        if(flag==0)
        {
            cout<<0;nl;
        }
        

            
        

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