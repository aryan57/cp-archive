/*
	group : Codeforces - Codeforces Round #724 (Div. 2)
	name : D. Omkar and Medians.cpp
	srcPath : /home/aryan/Documents/cp/D_Omkar_and_Medians.cpp
	url : https://codeforces.com/contest/1536/problem/D
*/
/*
    author : aryan57
    created : 06-June-2021 22:47:42 IST
*/
#include <bits/stdc++.h>
using namespace std;
// INCLUDE AT TOP (no #define int long long)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set; 
// order_of_key: The number of items in a set that are strictly smaller than k
// find_by_order: It returns an iterator to the ith largest element

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
const int INF = 2e9;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);


void solve_LOL()
{
    int n;
    cin>>n;
    vector <int> b(n+1);
    ordered_set s;
    F(i,1,n)
    {
        cin>>b[i];
    }

    s.insert(b[1]);

    // dbg(s);

    F(i,2,n)
    {

        int leq=s.order_of_key(b[i]+1);
        int l=s.order_of_key(b[i]);
        int eq=leq-l;
        int g=sz(s)-l-eq;

        if(g>=i)
        {
            cout<<"NO\n";
            return;
        }
        if(l>=i)
        {
            cout<<"NO\n";
            return;
        }

        

        auto it=s.lower_bound(b[i]);
        int tt=2;
        if(it==s.begin())
        {
            s.insert(b[i]);
            tt--;
        }
        else
        {
            it--;
            if(*it!=b[i])
            {
                s.insert(b[i]);
                tt--;
            }
        }
        int lesa=i-1-l;
        int grea=i-1-g;
        // dbg(lesa,tt);
        while (tt>0 && lesa>0)
        {
            s.insert(-INF);
            lesa--;
            tt--;
        }
        while (tt>0 && grea>0)
        {
            s.insert(INF);
            grea--;
            tt--;

        }
        while (tt--)
        {
            s.insert(b[i]);
        }
        // dbg(i,s);
        
    }

    cout<<"YES\n";
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
//	parsed : 06-June-2021 22:34:02 IST