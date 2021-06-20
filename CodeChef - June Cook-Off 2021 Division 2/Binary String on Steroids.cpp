/*
	group : CodeChef - June Cook-Off 2021 Division 2
	name : Binary String on Steroids.cpp
	srcPath : /home/aryan/Documents/cp/Binary_String_on_Steroids.cpp
	url : https://www.codechef.com/COOK130B/problems/BNSONSTR
*/
/*
    author : aryan57
    created : 20-June-2021 22:36:28 IST
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
const int mxn_sieve = 5e5;

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

void solve_LOL()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    int tot=0;

    s='#'+s;

    F(i,1,n)
    {
        if(s[i]=='1')tot++;
    }

    int ans=n-tot;

    if(tot==1)ans=0;

    for(int t=1;t*t<=n;t++)
    {
        if(n%t==0)
        {
            set<int> k;
            k.insert(t);
            k.insert(n/t);

            for(int z : k)
            {
                vector <int> cnt(z,0);
                F(i,1,n)
                {
                    
                    if(s[i]=='1')cnt[i%z]++;
                    
                }
                F(i,0,z-1)
                {
                    ans=min(ans,n/z-cnt[i]+tot-cnt[i]);
                }
            }
        }
    }

    cout<<ans;
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
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}
//	parsed : 20-June-2021 22:31:59 IST