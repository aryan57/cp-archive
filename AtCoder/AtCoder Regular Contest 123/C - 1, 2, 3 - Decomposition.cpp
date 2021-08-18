/*
	group : AtCoder - AtCoder Regular Contest 123
	name : C - 1, 2, 3 - Decomposition.cpp
	srcPath : /home/aryan/Documents/cp/C_1_2_3_Decomposition.cpp
	url : https://atcoder.jp/contests/arc123/tasks/arc123_c
*/
/*
    author : aryan57
    created : 18-July-2021 17:57:19 IST
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

int stonum(string s)
{
    int ans=0;
    int pww=1;
    RF(i,sz(s)-1,0)
    {
        ans+=pww*(s[i]-'0');
        pww*=10;
    }
    return ans;
}
unordered_map<int,int> previous_cache;
int previous(int n)
{
    if(n<=0)return 0;
    if(previous_cache[n])return previous_cache[n];

    string t=to_string(n);
    int z=sz(t);
    int lastpos=-1;
    int prev=n;

    F(i,0,z-1)
    {
        if(t[i]>='4')
        {
            int remlen=z-i;
            string temp(remlen,'3');
            temp = t.substr(0,i) + temp;
            prev =  stonum(temp);
            break;
        }

        if(t[i]=='0')
        {
            if(lastpos==-1)
            {
                assert(z>1);
                string temp(z-1,'3');
                prev =  stonum(temp);
                break;
            }

            string temp="";

            temp+=t.substr(0,lastpos);
            char zz=t[lastpos]-1;
            temp+=zz;
            temp+=string(z-lastpos-1,'3');

            prev =  stonum(temp);
            break;

        }

        if(t[i]>'1')lastpos=i;
    }

    previous_cache[n]=prev;
    return prev;
}

unordered_map<int,int> cache;

int f(int n)
{
    if(n==0)return 0;
    if(cache[n])return cache[n];

    // dbg(n);
    int ans = INF;
    ans=min(ans,f(n-previous(n))+1);
    int x1=previous(n)-1;
    x1=previous(x1);
    if(x1>0)
    {
        ans=min(ans,f(n-x1)+1);

    }
    

    cache[n] = ans;

    return ans;
}


void solve_LOL()
{
    // dbg(previous(3330));
    // dbg(previous(previous(3330)-1));
    int n;
    cin>>n;
    cout<<f(n);
    cout<<"\n";
}

signed main()
{
    // dd();

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
//	parsed : 18-July-2021 17:40:20 IST