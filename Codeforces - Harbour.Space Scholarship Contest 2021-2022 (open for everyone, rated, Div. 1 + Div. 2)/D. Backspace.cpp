/*
	group : Codeforces - Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)
	name : D. Backspace.cpp
	srcPath : /home/aryan/Documents/cp/D_Backspace.cpp
	url : https://codeforces.com/contest/1553/problem/D
*/
/*
    author : aryan57
    created : 22-July-2021 21:10:02 IST
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

bool f1(string &s,string &t,int par)
{
    int n=sz(s);
    int m=sz(t);

    int prev=-1;

    int i=0;
    int j=0;

    while (i<n && j<m)
    {
        if(s[i]==t[j])
        {
            if(prev==-1)
            {
                if(i%2==par)
                {
                    prev=i;
                    j++;
                    i++;

                }
                else
                {
                    i++;
                }
            }
            else
            {
                
                if(i%2==prev%2)
                {
                    i++;
                }else
                {
                    prev=i;
                    i++;
                    j++;
                }
            }
        }
        else
        {
            i++;
        }
    }

    return j==m && (n-i)%2==0;
}

void solve_LOL()
{
    string s,t;
    cin>>s>>t;

    if(f1(s,t,0) || f1(s,t,1))
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
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
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}
//	parsed : 22-July-2021 21:02:40 IST