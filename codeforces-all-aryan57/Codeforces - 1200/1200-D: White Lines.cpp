//https://codeforces.com/contest/1200/problem/D

/*
    author : Aryan Agarwal, IIT KGP
    created : 08-August-2020 23:46:00
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
typedef vector< string > vs;
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

signed main()
{
    #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    #endif
    fast;

    int n,k;
    cin>>n>>k;

    vvi gr(n, vi (n,0));
    vvi ho(n, vi (n,0));
    vvi preho(n, vi (n,0));
    vvi ve(n, vi (n,0));
    vvi preve(n, vi (n,0));
    vi okrow(n,1);
    vi preokrow(n,0);
    vi okcolumn(n,1);
    vi preokcolumn(n,0);
    int tot=n+n;
    char c;

    F(i,0,n-1)
    {
        F(j,0,n-1)
        {
            cin>>c;
            if(c=='B')gr[i][j]++;
        }
    }

    F(i,0,n-1)
    {
        F(j,0,n-1)
        {
            if(gr[i][j])
            {
                okrow[i]=0;
                tot--;
                break;
            }
        }
    }
    preokrow[0]=okrow[0];
    F(i,1,n-1)
    {
        preokrow[i]=preokrow[i-1]+okrow[i];
    }
    F(j,0,n-1)
    {
        F(i,0,n-1)
        {
            if(gr[i][j])
            {
                okcolumn[j]=0;
                tot--;
                break;
            }
        }
    }
    preokcolumn[0]=okcolumn[0];
    F(j,1,n-1)
    {
        preokcolumn[j]=preokcolumn[j-1]+okcolumn[j];
    }

    F(i,0,n-1)
    {
        bool tt = false;
        int x,y;
        F(j,0,n-1)
        {
            if(gr[i][j] && !tt)
            {
                tt= true;
                x=y=j;
            }
            else
            {
                if(gr[i][j] && tt)
                {
                    y=j;
                }
            }
            
        }

        if(!tt)F(j,0,n-k)
        {
            ho[i][j]=1;
        }
        else
        {
            if(y-x+1<=k)F(j,max((ll)0,y-k+1),x)
            {
                ho[i][j]=1;
            }
        }

        
        

    }

    // F(i,0,n-1)
    // {
    //     F(j,0,n-1)
    //     {
    //         cout<<ho[i][j]<<" ";
    //     }nl;
    // }nl;


    F(j,0,n-1)
    {
        

        preho[0][j]=ho[0][j];

        F(i,1,n-1)
        {
            preho[i][j]=preho[i-1][j]+ho[i][j];
        }


    }


    F(j,0,n-1)
    {
        bool tt = false;
        int x,y;
        F(i,0,n-1)
        {
            if(gr[i][j] && !tt)
            {
                tt= true;
                x=y=i;
            }
            else
            {
                if(gr[i][j] && tt)
                {
                    y=i;
                }
            }
            
        }

        if(!tt)F(i,0,n-k)
        {
            ve[i][j]=1;
        }
        else
        {
            if(y-x+1<=k)F(i,max((ll)0,y-k+1),x)
            {
                ve[i][j]=1;
            }
        }
        

    }

    // F(i,0,n-1)
    // {
    //     F(j,0,n-1)
    //     {
    //         cout<<ve[i][j]<<" ";
    //     }nl;
    // }nl;

    F(i,0,n-1)
    {
        

        preve[i][0]=ve[i][0];

        F(j,1,n-1)
        {
            preve[i][j]=preve[i][j-1]+ve[i][j];
        }


    }

    int ans=0;



    F(i,0,n-k)
    {
        F(j,0,n-k)
        {
            int tt=0;
            tt+=preokrow[i+k-1];
            if(i)tt-=preokrow[i-1];
            tt+=preokcolumn[j+k-1];
            if(j)tt-=preokcolumn[j-1];

            // dbg(tt,tot);
            // tt=to
            
            
            int x=preve[i][j+k-1],y=preho[i+k-1][j];
            if(j)x-=preve[i][j-1];
            if(i)y-=preho[i-1][j];

            ans=max(ans,x+y+tot-tt);
            
            

            
        }
    }

    cout<<ans;





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