/*
	group : Codeforces - Codeforces Round #712 (Div. 2)
	name : C. Balance the Bits.cpp
	srcPath : /home/aryan/Documents/cp/C_Balance_the_Bits.cpp
	url : https://codeforces.com/contest/1504/problem/C
*/
/*
    author : aryan57
    created : 07-June-2021 16:39:46 IST
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

void solve_LOL()
{
    int n;
    cin>>n;
    string s;
    cin>>s;

    int c0=0;
    for(char x : s)c0+=x=='0';

    if(s[0]=='0' || s[n-1]=='0' || c0%2)
    {
        cout<<"NO\n";
        return;
    }

    string s1="",s2="";

    int c1=n-c0;
    int k=0;
    bool flip=false;
    for(char x : s)
    {
        if(x=='1')
        {
            if(k<c1/2)s1+='(',s2+='(',k++;
            else s1+=')',s2+=')';
        }
        else
        {
            s1+=(flip?'(':')');
            s2+=(flip?')':'(');
            flip^=true;
        }
    }

    cout<<"YES\n";
    cout<<s1;
    cout<<"\n";
    cout<<s2;
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
//	parsed : 07-June-2021 16:39:42 IST