//https://codeforces.com/contest/94/problem/B

/*
    // tut used
    author : aryan57
    created : 01-May-2021 00:08:32 IST
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

    set<pair <int,int> > s;

    F(i,1,n)
    {
        int u,v;
        cin>>u>>v;
        s.insert({u,v});
        s.insert({v,u});
    }

    vector <int> g1[6];
    vector <int> g2[6];

    F(i,1,5)
    {
        F(j,1,5)
        {
            if(i==j)continue;
            if(s.find({i,j})!=s.end()){
                g1[i].push_back(j);
                g1[j].push_back(i);
            }else{
                g2[i].push_back(j);
                g2[j].push_back(i);
            }
        }
    }

    F(i,1,5)
    {
        for(int to : g1[i]){
            for(int to2 : g1[i]){
                if(s.find({to,to2})!=s.end()){
                    // dbg(i,to,to2);
                    cout<<"WIN\n";
                    return;
                }
            }
        }
    }
    F(i,1,5)
    {
        for(int to : g2[i]){
            for(int to2 : g2[i]){
                if(s.find({to,to2})==s.end() && to!=to2){
                    // dbg(i,to,to2);
                    cout<<"WIN\n";
                    return;
                }
            }
        }
    }

    cout<<"FAIL\n";
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