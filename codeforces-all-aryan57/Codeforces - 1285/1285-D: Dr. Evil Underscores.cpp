//https://codeforces.com/contest/1285/problem/D

/*
    author : aryan57
    created : 27-April-2021 14:44:02 IST
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

int ans=INF;
// int cntzz=0;
void dfs(vector <int> &vec,int bit,int cur){

    // if(cntzz++>10)return;

    if(bit<0){
        ans=min(ans,cur);
        return;
    }

    vector <int> v1;
    vector <int> v0;
    for(int x : vec){
        if((x>>(bit-1))&1)v1.push_back(x);
        else v0.push_back(x);
    }

    // dbg(v0,v1,bit,cur);

    if(sz(v1)%sz(vec)){
        dfs(v1,bit-1,cur+(int)pow(2,bit-1));
        dfs(v0,bit-1,cur+(int)pow(2,bit-1));
    }else{
        if(!v1.empty())dfs(v1,bit-1,cur);
        if(!v0.empty())dfs(v0,bit-1,cur);
    }
}

void solve_LOG()
{
    int n;
    cin>>n;
    vector <int> v(n);
    F(i,0,n-1)cin>>v[i];

    dfs(v,31,0);

    cout<<ans;
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