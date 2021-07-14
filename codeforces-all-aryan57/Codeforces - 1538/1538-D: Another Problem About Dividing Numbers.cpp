//https://codeforces.com/contest/1538/problem/D

/*
    author : aryan57
    created : 10-June-2021 20:23:25 IST
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

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);



#define ARYAN_SIEVE  
const int mxn_sieve = 31622+100;

int spf[mxn_sieve + 1]; // spf -> smallest prime factor
// if spf[x]==x ,then x is prime
vector <int> primes;
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

    for(int i=2;i<=mxn_sieve;i++)
    {
        if(spf[i]==i)primes.push_back(i);
    }
}

int f1(int a)
{
    int ans=0;
    for(int i=2;i*i<=a;i++)
    {
        while(a%i==0)
        {
            ans++;
            a/=i;
            // dbg(a,i);
        }
    }
 
    if(a>1)
    {
        ans++;
    }
 
    return ans;
}

void solve_LOL()
{
    int a,b,k;
    cin>>a>>b>>k;

    if(k==1)
    {
        if((a==1 && b==1) || (a==b))
        {
            cout<<"NO\n";
            return;
        }
        if(a==1 || b==1)
        {
            cout<<"YES\n";
            return;
        }
        if(max(a,b)%min(a,b)==0)
        {
            cout<<"YES\n";
            return;
        }
        cout<<"NO\n";
        return;
    }

    // for(int i=0;i<100;i++)dbg(primes[i]);

    // dbg(f1(a),f1(b));

    int x=0;
    int y=0;
    // dbg(sz(primes));
    for(int z : primes)
    {
        while (a%z==0)
        {
            a/=z;
            x++;
        }
        
    }
    if(a>1)x++;
    for(int z : primes)
    {
        while (b%z==0)
        {
            b/=z;
            y++;
        }
        
    }

    if(b>1)y++;
    
    // dbg(x,y);

    if(x+y>=k)
    {
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";


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
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}
//	parsed : 10-June-2021 20:23:22 IST