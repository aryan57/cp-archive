/*
	group : Codeforces - Codeforces Round #734 (Div. 3)
	name : C. Interesting Story.cpp
	srcPath : /home/aryan/Documents/cp/C_Interesting_Story.cpp
	url : https://codeforces.com/contest/1551/problem/C
*/
/*
    author : aryan57
    created : 23-July-2021 21:17:45 IST
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
int ind=0;
bool comp(string &a,string &b)
{
    int cnt[2][5]={};
 
    for(char x : a)
    {
        cnt[0][x-'a']++;
    }
    for(char x : b)
    {
        cnt[1][x-'a']++;
    }
 
    return 2*cnt[0][ind]-sz(a) > 2*cnt[1][ind]-sz(b);
}
 
void solve_LOL()
{
    int n;
    cin>>n;
 
    vector <string> vec(n);
 
    F(i,0,n-1)
    {
        cin>>vec[i];
    }
 
    int ans=0;
 
    F(j,0,4)
    {
        ind=j;
        sort(all(vec),comp);
 
        int tot=0;
        int cnt=0;
 
        int temp=0;
        vector <bool> used(n);
        F(i,0,n-1)
        {
            int c=0;
            int t=0;
            for(char x : vec[i])
            {
                t++;
                if(x-'a'==j)c++;
            }
 
            if(2*(cnt+c)>t+tot)
            {
                cnt+=c;
                tot+=t;
                temp++;
                used[i]=true;
            }
        }
        F(i,0,n-1)
        {
            if(used[i])continue;
            int c=0;
            int t=0;
            for(char x : vec[i])
            {
                t++;
                if(x-'a'==j)c++;
            }
 
            if(2*(cnt+c)>t+tot)
            {
                cnt+=c;
                tot+=t;
                temp++;
                used[i]=true;
            }
        }
 
        ans=max(ans,temp);
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
//	parsed : 23-July-2021 21:17:37 IST