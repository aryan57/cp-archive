/*
	group : HackerRank - GOC-CDC Series #11
	name : All Vowels Or Nothing.cpp
	srcPath : /home/aryan/Documents/cp/All_Vowels_Or_Nothing.cpp
	url : https://www.hackerrank.com/contests/goc-cdc-series-11/challenges/all-vowels-or-nothing
*/
/*
    author : aryan57
    created : 06-July-2021 10:37:26 IST
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

int cnt=0;

void f(string s)
{
    // dbg(s);
    int n=s.size();
    int c[26]={};
    int tot=0;

    int l=0;
    int r=0;

    while (l<=r && r<=n)
    {
        assert(tot<=5);

        // dbg(l,r,tot);

        if(tot<5)
        {
            if(r<n)
            {
                if(c[s[r]-'a']==0)
                {
                    tot++;
                }
                c[s[r]-'a']++;
                
                r++;
            }
            else
            {
                break;
            }
        }
        else
        {
            // dbg(l,r,l+1,n-r);
            cnt+=(n+1-r);
            // cnt++;
            if(c[s[l]-'a']==1)
            {
                tot--;
            }
            c[s[l]-'a']--;
            l++;
        }

    }
    

}

void solve_LOL()
{
    string s;
    cin>>s;



    cnt=0;

    s+='#';
    string cur="";

    for(char z : s)
    {
        if(!(z=='a' || z=='e' || z=='i' || z=='o' || z=='u'))
        {
            if(!cur.empty())f(cur);
            cur="";
        }
        else
        {
            cur+=z;
        }
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
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}
//	parsed : 06-July-2021 10:33:40 IST