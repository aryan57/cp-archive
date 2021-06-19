/*
	group : AtCoder - AtCoder Beginner Contest 206（Sponsored by Panasonic）
	name : E - Divide Both.cpp
	srcPath : /home/aryan/fdsms/E_Divide_Both.cpp
	url : https://atcoder.jp/contests/abc206/tasks/abc206_e
*/
/*
    author : aryan57
    created : 19-June-2021 18:23:11 IST
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

const int mxn = 1e6;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

vector<int> phi(mxn + 1);
void phi_1_to_n() {
    
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= mxn; i++)
        phi[i] = i;

    for (int i = 2; i <= mxn; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= mxn; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

int f(int n)
{
    if(n<=2)return 0;

    int cnt=0;

    F(i,1,n-1)
    {
        cnt+=(n-i)-(n/i-1);
        // dbg(i,cnt);
    }

    F(i,1,n)
    {
        cnt-=phi[i]-1;
        // dbg(i,cnt);
    }

    assert(cnt>=0);

    return cnt;
}

int ceil(int a, int b)
{
    return (a + b - 1) / b;
}

int part(int l,int r)
{
    int cnt=0;
    F(i,1,r)
    {
        cnt+=phi[i];
    }

    cnt-=(l-1)/2;
    cnt-=(r-l+1)/2;
    cnt-=(r-l+1)/2;

    return cnt;
}
int part2(int l,int r)
{
    int cnt=0;
    F(i,1,l-1)
    {
        cnt+=r-l+1;

        int first=ceil(l,i);
        int last=r/i;

        int bad=last-first+1;

        if(bad>0)cnt-=bad;
    }


    return cnt;
}

void solve_LOG()
{
    int l,r;
    cin>>l>>r;
    // f(6);
    // dbg(f(6));

    int ans=0;

    ans+=f(r);
    ans-=f(l-1);

    int bad=0;
    bad+=part2(l,r);
    bad-=part(l,r);

    dbg(f(r),f(l-1),part(l,r),part2(l,r));

    cout<<ans-bad;
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
    phi_1_to_n();
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOG();
    }
    return 0;
}
//	parsed : 19-June-2021 18:15:49 IST