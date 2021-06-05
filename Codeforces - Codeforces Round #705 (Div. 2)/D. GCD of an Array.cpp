/*
	group : Codeforces - Codeforces Round #705 (Div. 2)
	name : D. GCD of an Array.cpp
	srcPath : /home/aryan/Documents/cp/D_GCD_of_an_Array.cpp
	url : https://codeforces.com/problemset/problem/1493/D
*/
/*
    author : aryan57
    created : 05-June-2021 18:16:38 IST
*/
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

const int mxn = 2e5;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

int gcd(int a, int b) /*__gcd doesn't work for big no.s*/
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

#define ARYAN_SIEVE  
const int mxn_sieve = 2e5+10;

int spf[mxn_sieve + 1]; // spf -> smallest prime factor
// if spf[x]==x ,then x is prime
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i <= mxn_sieve; i++)
        spf[i] = i;

    for (int i = 4; i <= mxn_sieve; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i <= mxn_sieve; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= mxn_sieve; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

/*
    modInverse(a) = binpow(a, phi(n)-1, n)
    If n is prime, phi(n) = n-1
    phi(n) = number of no.s from 1 to n co-prime with n
*/
int binpow(int a, int b=M-2, int m=M)
{
    assert(a>=0 && b>=0);
    a%=m;
    int res=1;
    while (b)
    {
        if(b%2)res=res*a%m;
        a=a*a%m;
        b/=2;
    }
    return res;
}

int ans=1;
int n,q;
vector<unordered_map<int,int>>  v(mxn_sieve+1);
void fun(int z,int i)
{
    int mn=INF;
    for(int i=1;i<=n;i++)mn=min(mn,v[z][i]);
    ans*=binpow(z,mn);
    ans%=M;

    for(int i=1;i<=n;i++)
    {
        v[z][i]-=mn;
        if(v[z][i]==0)v[z].erase(i);
    }

}

void solve_LOG()
{
    
    cin>>n>>q;

    F(t,1,n+q)
    {
        int i,x;
        if(t<=n)
        {
            i=t;
            cin>>x;
        }else cin>>i>>x;

        while (x!=1)
        {
            int z=spf[x];
            int cnt=0;
            while (x%z==0)
            {
                x/=z;
                cnt++;
            }
            v[z][i]+=cnt;
            if(sz(v[z])==n)fun(z,i);
        }

        if(t>n)cout<<ans<<"\n";
    }
    
    
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
    sieve();
#endif
#ifdef ARYAN_SEG_SIEVE
    segmented_sieve();
#endif
#ifdef ARYAN_FACT
    fact_init();
#endif
    // cout<<fixed<<setprecision(10);
    int _t=1;
    // cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOG();
    }
    return 0;
}
//	parsed : 05-June-2021 18:16:34 IST