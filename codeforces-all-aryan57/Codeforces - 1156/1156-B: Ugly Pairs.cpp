//https://codeforces.com/contest/1156/problem/B

/*
    author : aryan57
    created : 28-April-2021 07:55:53 IST
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

bool check(string s)
{
    bool ok = true;

    F(i,1,sz(s)-1)
    {
        if(abs(s[i]-s[i-1])==1)ok=false;
    }

    return ok;
}

void solve_LOL()
{

    string s;
    cin>>s;

    sort(all(s));

    if(check(s))
    {
        cout<<s;
        cout<<"\n";
        return;
    }

    int cnt[26]={};

    for(char x : s){
        cnt[x-'a']++;
        // dbg(x);
    }

    // F(i,0,25)dbg(cnt[i]);

    for(int i=0;i<=24;i+=2)
    {
        for(int j=1;j<=25;j+=2)
        {
            if(abs(i-j)==1)continue;
            // dbg(i,j,cnt[i],cnt[j]);
            if(!cnt[i] || !cnt[j])continue;
            // dbg(i,j);

            for(int k=0;k<=i-2;k+=2)
            {
                while(cnt[k]--)cout<<(char)('a'+k);
            }
            for(int k=i+2;k<=24;k+=2)
            {
                while(cnt[k]--)cout<<(char)('a'+k);
            }
            for(int k=i;k<=i;k+=2)
            {
                while(cnt[k]--)cout<<(char)('a'+k);
            }
            for(int k=j;k<=j;k+=2)
            {
                while(cnt[k]--)cout<<(char)('a'+k);
            }
            for(int k=1;k<=j-2;k+=2)
            {
                while(cnt[k]--)cout<<(char)('a'+k);
            }
            for(int k=j+2;k<=25;k+=2)
            {
                while(cnt[k]--)cout<<(char)('a'+k);
            }
            cout<<"\n";
            return;
        }
    }

    cout<<"No answer\n";
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