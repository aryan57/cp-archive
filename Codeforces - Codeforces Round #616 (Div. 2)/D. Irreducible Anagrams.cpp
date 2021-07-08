/*
	group : Codeforces - Codeforces Round #616 (Div. 2)
	name : D. Irreducible Anagrams.cpp
	srcPath : /home/aryan/Documents/cp/D_Irreducible_Anagrams.cpp
	url : https://codeforces.com/contest/1291/problem/D
*/
/*
    author : aryan57
    created : 08-July-2021 13:15:33 IST
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

void solve_LOG()
{
    string s;
    cin>>s;

    int n=sz(s);

    s='#'+s;
    int cnt[n+1][26]={};

    F(i,1,n)
    {
        cnt[i][s[i]-'a']++;
        F(j,0,25)
        {
            cnt[i][j]+=cnt[i-1][j];
        }
    }

    int q;
    cin>>q;
    while (q--)
    {
        int l,r;
        cin>>l>>r;

        if(l==r)
        {
            cout<<"Yes\n";
            continue;
        }

        int t=0;

        F(i,0,25)
        {
            if(cnt[r][i]-cnt[l-1][i])t++;
        }

        if(t>=3 || s[l]!=s[r])
        {
            cout<<"Yes";
        }else
        {
            cout<<"No";
        }

        cout<<"\n";
        continue;
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
//	parsed : 08-July-2021 13:15:23 IST