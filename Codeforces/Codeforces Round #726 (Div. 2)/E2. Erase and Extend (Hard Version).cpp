/*
	group : Codeforces - Codeforces Round #726 (Div. 2)
	name : E2. Erase and Extend (Hard Version).cpp
	srcPath : /home/aryan/Documents/cp/E2_Erase_and_Extend_Hard_Version_.cpp
	url : https://codeforces.com/contest/1537/problem/E2
*/
/*
    author : aryan57
    created : 19-June-2021 02:24:21 IST
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

vector<int> z_function(string &s) {
    int n=s.length();
    vector<int> z(n);
    for (int i=1,l=0,r=0;i<n;++i) {
        if (i<=r)z[i]=min(r-i+1,z[i-l]);
        while (i+z[i]<n && s[z[i]]==s[i+z[i]])z[i]++;
        if(i+z[i]-1>r)l=i,r=i+z[i]-1;
    }
    return z;
}

void solve_LOG()
{
    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    vector <int> z=z_function(s);

    int m=1;

    F(i,2,n)
    {
        // dbg(i,m);
        int p=-1;

        if(i%m==0)p=m;
        else p=i%m;
        if(s[i-1]<s[p-1])
        {
            m=i;
            continue;
        }
        if(s[i-1]>s[p-1])
        {
            break;
        }
        p++;
        if(p>m)p-=m;

        int pos=p+z[p-1];

        if(pos<=m)
        {
            if(s[1+z[p-1]-1]<s[pos-1])
            {
                m=i;
            }
        }else
        {
            p=m-p+2;
            if(p>m)p-=m;
            pos=p+z[p-1];
            if(pos<=m)
            {
                if(s[1+z[p-1]-1]<s[pos-1])
                {
                    m=i;
                }
            }else
            {
                m=i;
            }
        }
    }

    string ans=s.substr(0,m);

    while(sz(ans)<k)ans+=ans;

    cout<<ans.substr(0,k);

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
//	parsed : 19-June-2021 02:24:13 IST