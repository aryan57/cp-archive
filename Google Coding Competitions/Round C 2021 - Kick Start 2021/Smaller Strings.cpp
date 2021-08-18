/*
	group : Google Coding Competitions - Round C 2021 - Kick Start 2021
	name : Smaller Strings.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Smaller_Strings.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435c44/00000000007ebe5e
*/
/*
    author : aryan57
    created : 23-May-2021 16:36:53 IST
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

int ceil(int a, int b)
{
    return (a + b - 1) / b;
}

void solve_GOOGLE()
{
   int n,k;
   cin>>n>>k;

   string s;
   cin>>s;

   int cnt=0;

   int nn=ceil(n,2);

   F(i,0,nn-1)
   {
       int z=s[i]-'a';
       if(z==0)continue;
        // dbg(i,s,z);
        if(nn-i-1>0)z*=binpow(k,nn-i-1);
        z%=M;

        cnt+=z;
        cnt%=M;

        // dbg(i,nn-i-1,z,cnt);
       
   }

//    dbg(cnt);
    string z=s;
   F(i,0,nn-1)
   {
       z[n-1-i]=s[i];
   }

   if(z<s)
   {
       cnt++;
       cnt%=M;
   }

   cout<<cnt;
   cout<<"\n";


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
      cout<<"Case #"<<i<<": ";
      solve_GOOGLE();
   }
   return 0;
}
//	parsed : 23-May-2021 16:36:49 IST