/*
	group : Codeforces - Codeforces Round #726 (Div. 2)
	name : E2. Erase and Extend (Hard Version).cpp
	srcPath : /home/aryan/Documents/cp/E2_Erase_and_Extend_Hard_Version_.cpp
	url : https://codeforces.com/contest/1537/problem/E2
*/
/*
    author : aryan57
    created : 18-June-2021 21:37:09 IST
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
    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    vector <int>  pos[26];

    F(i,0,n-1)
    {
        pos[s[i]-'a'].push_back(i);
    }

    int last=n;

    F(c,s[0]-'a'+1,25)
    {
        int x=lower_bound(all(pos[c]),0)-pos[c].begin();
        if(x!=sz(pos[c]))
        {
            // dbg(c,x,pos[c][x]);
            last=min(last,pos[c][x]);
        }
    }

    last--;

    while (last>0 && s[last]==s[0])
    {
        last--;
    }

    dbg(last,s[last]);
    


    string pre=s.substr(0,last+1);
    string zz="";
    while (sz(zz)<k)
    {
        zz+=pre;
    }

    cout<<zz.substr(0,k);
    
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
//	parsed : 18-June-2021 21:22:55 IST