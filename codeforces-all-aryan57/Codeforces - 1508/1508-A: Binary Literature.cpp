//https://codeforces.com/contest/1508/problem/A

/*
    author : aryan57
    created : 27-April-2021 11:22:42 IST
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

string fun(char xx,string s[3],int n)
{
    int cnt[3][2]={};

    F(i,0,2)
    {
        for(char x : s[i])
        {
            cnt[i][x-'0']++;
        }
    }


    string s1,s2;
    bool ok = false;
    F(i,0,2)
    {
        if(cnt[i][xx-'0']>=n && cnt[(i+1)%3][xx-'0']>=n)
        {
            if(cnt[i][xx-'0']>cnt[(i+1)%3][xx-'0'])s1=s[i],s2=s[(i+1)%3];
            else s1=s[(i+1)%3],s2=s[i];
            ok=true;
            break;
        }
    }

    if(!ok)
    {
        return "";
    }

    int pos[2*n+1]={};


    int i=0,j=0;

    int tn=2*n;
    s1+=xx;
    // dbg(s1);
    // dbg(s2);

    while(i<tn+1 && j<tn)
    {
        while (i<tn+1 && s1[i]!=xx)
        {
            i++;
        }

        assert(i<tn+1);

        if(s2[j]==xx)
        {
            i++;
            j++;
        }else
        {
            j++;
            pos[i]++;
        }
        
    }
    string ans="";
    F(i,0,tn)
    {
        if(s1[i]=='0'^'1'^xx)ans+='0'^'1'^xx;
        else{
            while (pos[i]--)
            {
                ans+='0'^'1'^xx;
            }
            ans+=xx;
        }
    }

    return ans.substr(0,sz(ans)-1);
}

void solve_LOL()
{
    int n;
    cin>>n;

    string s[3];
    cin>>s[0]>>s[1]>>s[2];

    string ans1=fun('1',s,n);
    string ans0=fun('0',s,n);

    // dbg(ans0,ans1);

    string ans=ans1;
    if(sz(ans0)>sz(ans1))ans=ans0;    

    cout<<ans<<"\n";
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