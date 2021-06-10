/*
	group : Codeforces - Codeforces Round #725 (Div. 3)
	name : E. Funny Substrings.cpp
	srcPath : /home/aryan/Documents/cp/E_Funny_Substrings.cpp
	url : https://codeforces.com/contest/1538/problem/E
*/
/*
    author : aryan57
    created : 10-June-2021 23:17:48 IST
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

// #define int long long
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
vector <string>  lines;
int ind=0;
void solve_LOL()
{
    int n;
    n=stoi(lines[ind++]);

    unordered_map<string,string> mp;
    string z="";

    for(int j=0;j<n;j++)
    {
        

        string s=lines[ind++];

        int pos=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='=')
            {
                pos=i;
                break;
            }
        }

        // dbg(j,pos,mp);
        if(s[pos-1]==':')
        {
            
            int l=0;
            int r=pos-3;

            mp[s.substr(l,r-l+1)]=s.substr(pos+2,sz(s)-pos-2);

            if(j==n-1)z=s.substr(pos+2,sz(s)-pos-2);
        }
        else
        {
            int plus=0;
            for(int i=pos+2;i<s.size();i++)
            {
                if(s[i]=='+')
                {
                    plus=i;
                    break;
                }
            }
            int l[3]={};
            int r[3]={};

            l[0]=0;
            r[0]=pos-2;

            l[1]=pos+2;
            r[1]=plus-2;

            l[2]=plus+2;
            r[2]=sz(s)-1;

            string ss[3];

            F(i,0,2)
            {
                ss[i]=s.substr(l[i],r[i]-l[i]+1);
            }

            mp[ss[0]]=mp[ss[1]]+mp[ss[2]];

            if(j==n-1)z=mp[ss[0]];
            
        }

    }

    // dbg(sz(z));

    int cnt=0;

    for(int i=0;i<=sz(z)-4;i++)
    {
        if(z[i]==z[i+2] && z[i]=='h' && z[i+1]==z[i+3] && z[i+1]=='a')cnt++;
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

    string line;
    while (std::getline(std::cin, line))
    {
        lines.push_back(line);
    }

    // dbg(lines);
    // cout<<fixed<<setprecision(10);
    int _t=1;
    // cin>>_t;
    _t=stoi(lines[ind++]);
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}
//	parsed : 10-June-2021 23:17:42 IST