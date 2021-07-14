//https://codeforces.com/contest/1140/problem/E

/*
    author : aryan57
    created : 29-April-2021 11:06:28 IST
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
// const int32_t M = 1000000007;
const int32_t M = 998244353;
const long double pie = acos(-1);

/*
    Binary Exponentiation
    // (a^b)%m
    // O(logb)
    // modInverse(a) = binpow(a, phi(n)-1, n)
    // If n is prime, phi(n)=n-1
*/
int binpow(int a, int b=M-2, int m=M) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int k;

int calc(int len,int c,int end)
{
    int ans=0;

    RF(i,len,end)
    {
        if(i%2==len%2)ans+=binpow(c,i);
        else ans-=binpow(c,i);

        ans%=M;
        ans+=M;
        ans%=M;
    }

    return ans;
}

int fun(vector <int> a)
{
    int n=sz(a);
    int cnt1=0;
    F(i,0,n-1)
    {
        if(a[i]==-1)cnt1++;
        if(i && a[i]==a[i-1] && a[i]!=-1)
        {
            return 0;
        }
    }

    if(cnt1==n)
    {
        int ans=k;
        ans*=binpow(k-1,n-1);
        ans%=M;

        return ans;
    }

    int ans=1;

    int start=-1;
    F(i,0,n-1)
    {
        if(a[i]!=-1){
            start=i;
            break;
        }
        ans*=(k-1);
        ans%=M;
    }
    RF(i,n-1,0)
    {
        if(a[i]!=-1)break;
        ans*=(k-1);
        ans%=M;
    }

    F(i,start+1,n-1)
    {
        if(a[i]!=-1)
        {
            int end=0;
            if(a[i]==a[start])
            {
                end=1;
            }
            int num=calc(i-start-1,k-1,end);
            ans*=num;
            ans%=M;
            start=i;
        }
    }


    return ans;
}

void solve_LOG()
{
    int n;
    cin>>n>>k;

    vector <int> a(n);
    vector <int> v1;
    vector <int> v2;

    F(i,0,n-1)
    {
        cin>>a[i];
        if(i%2)v1.push_back(a[i]);
        else v2.push_back(a[i]);
    }

    int k1=fun(v1);
    int k2=fun(v2);

    // dbg(k1,k2,v1,v2);

    int ans=k1*k2;
    ans%=M;

    cout<<ans;
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