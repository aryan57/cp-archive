/*
	group : Codeforces - Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)
	name : A. Colour the Flag.cpp
	srcPath : /home/aryan/Documents/cp/A_Colour_the_Flag.cpp
	url : https://codeforces.com/contest/1534/problem/0
*/
/*
    author : aryan57
    created : 13-June-2021 21:06:06 IST
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
    int n,m;
    cin>>n>>m;

    char g1[n][m];
    char g2[n][m];
    char g3[n][m];

    F(i,0,n-1)
    {
        string s;
        cin>>s;
        F(j,0,m-1)
        {
            g3[i][j]=s[j];

            if((i+j)%2)
            {
                g1[i][j]='R';
                g2[i][j]='W';
            }
            else{
                g1[i][j]='W';
                g2[i][j]='R';

            }
        }
    }

    bool ok1=true;
    bool ok2=true;

    F(i,0,n-1)
    {
        F(j,0,m-1)
        {
            if(g3[i][j]=='.')continue;
            if(g3[i][j]!=g1[i][j])
            {
                ok1=false;
            }
            if(g3[i][j]!=g2[i][j])
            {
                ok2=false;
            }
        }
    }

    if(ok1)
    {
        cout<<"YES\n";
        F(i,0,n-1)
        {
            F(j,0,m-1)cout<<g1[i][j];
            cout<<"\n";
        }
        return;
    }
    if(ok2)
    {
        cout<<"YES\n";
        F(i,0,n-1)
        {
            F(j,0,m-1)cout<<g2[i][j];
            cout<<"\n";
        }
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
//	parsed : 13-June-2021 21:05:09 IST