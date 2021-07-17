/*
	group : HackerRank - Testing 1622293244
	name : Infected Rats.cpp
	srcPath : /home/aryan/Documents/cp/Infected_Rats.cpp
	url : https://www.hackerrank.com/contests/testing-1622293244/challenges/infected-rats
*/
/*
    author : aryan57
    created : 16-July-2021 14:35:59 IST
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

void solve_LOG()
{
    int n;
    cin>>n;

    vector <int> v(n);
    set<int> alive;
    F(i,0,n-1)
    {
        cin>>v[i];
        alive.insert(i);
    }

    int ans=0;
    set<int> going_to_die;
    set<int> next_to_die;

    F(i,1,n-1)
    {
        if(v[i]>v[i-1])going_to_die.insert(i);
    }

    int day=0;

    while (!going_to_die.empty())
    {
        day++;
        next_to_die.clear();
        for(int x : going_to_die)
        {
            alive.erase(x);
        }

        for(int x : going_to_die)
        {
            auto it = alive.upper_bound(x);
            if(it==alive.begin() || it==alive.end())continue;
            auto pre=it;
            pre--;
            if(v[*pre]<v[*it])next_to_die.insert(*it);
        }

        going_to_die=next_to_die;
    }
    cout<<day;
    

    
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
//	parsed : 16-July-2021 14:35:20 IST