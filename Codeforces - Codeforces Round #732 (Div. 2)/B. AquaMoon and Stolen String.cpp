/*
	group : Codeforces - Codeforces Round #732 (Div. 2)
	name : B. AquaMoon and Stolen String.cpp
	srcPath : /home/aryan/Documents/cp/B_AquaMoon_and_Stolen_String.cpp
	url : https://codeforces.com/contest/1546/problem/B
*/
/*
    author : aryan57
    created : 11-July-2021 20:25:17 IST
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
    vector <string> s1(n),s2(n-1);
    
    int cnt1[m][26]={};
    int cnt2[m][26]={};

    F(i,0,n-1)
    {
        cin>>s1[i];
        F(j,0,m-1)
        {
            cnt1[j][s1[i][j]-'a']++;
        }
    }
    F(i,0,n-2)
    {
        cin>>s2[i];
        F(j,0,m-1)
        {
            cnt2[j][s2[i][j]-'a']++;
        }
    }

    F(i,0,n-1)
    {
        bool ok = true;

        F(j,0,m-1)
        {
            F(c,0,25)
            {
                int minus=0;
                if(s1[i][j]-'a'==c)minus++;
                if(cnt1[j][c]-minus!=cnt2[j][c])
                {
                    ok=false;
                    break;
                }
            }

            if(!ok)break;
            
        }

        if(ok)
        {
            cout<<s1[i]<<endl;
            return;
        }
    }

    cout<<s1[0]<<endl;


}

signed main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
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
//	parsed : 11-July-2021 19:54:23 IST