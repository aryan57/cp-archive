/*
	group : Codeforces - Codeforces Round #724 (Div. 2)
	name : A. Omkar and Bad Story.cpp
	srcPath : /home/aryan/Documents/cp/A_Omkar_and_Bad_Story.cpp
	url : https://codeforces.com/contest/1536/problem/0
*/
/*
    author : aryan57
    created : 06-June-2021 20:07:47 IST
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
    int n;
    cin>>n;

    unordered_set <int> a;

    unordered_map<int,int> cnt;

    F(i,0,n-1)
    {
        int x;
        cin>>x;
        a.insert(x);
        cnt[x]++;
    }

    while (sz(a)<=300)
    {
        unordered_set <int> b;

        for(auto it=a.begin();it!=a.end();it++)
        {
            auto it2=it;
            it2++;
            for(;it2!=a.end();it2++)
            {
                if(cnt[abs(*it-*it2)]==0)
                {
                    b.insert(abs(*it-*it2));
                    cnt[abs(*it-*it2)]=1;
                }
            }
        }

        if(b.empty())break;

        for(int x : b)
        {
            a.insert(x);
        }
    }

    if(sz(a)<=300)
    {
        cout<<"YES\n";
        cout<<sz(a);
        cout<<"\n";
        for(int x : a)cout<<x<<" ";
        cout<<"\n";
        return;
    }

    cout<<"NO\n";
    
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
//	parsed : 06-June-2021 20:07:40 IST