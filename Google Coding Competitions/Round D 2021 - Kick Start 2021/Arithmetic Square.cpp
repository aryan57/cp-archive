/*
	group : Google Coding Competitions - Round D 2021 - Kick Start 2021
	name : Arithmetic Square.cpp
	srcPath : /home/aryan/Documents/cp/Arithmetic_Square.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/00000000004361e3/000000000082b813
*/
/*
    author : aryan57
    created : 11-July-2021 10:34:06 IST
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

void solve_GOOGLE()
{
    vector< vector<int> > v(4,vector <int> (4));

    F(j,1,3)cin>>v[1][j];
    cin>>v[2][1]>>v[2][3];
    F(j,1,3)cin>>v[3][j];

    vector <int> t;
    t.push_back((v[1][2]+v[3][2])/2);
    t.push_back((v[2][1]+v[2][3])/2);
    t.push_back((v[1][3]+v[3][1])/2);
    t.push_back((v[1][1]+v[3][3])/2);

    int ans=0;

    for(int x : t)
    {
        int cnt=0;
        v[2][2]=x;

        F(i,1,3)if(2*v[i][2]==v[i][1]+v[i][3])cnt++;
        F(j,1,3)if(2*v[2][j]==v[1][j]+v[3][j])cnt++;

        if(2*v[2][2]==v[1][1]+v[3][3])cnt++;
        if(2*v[2][2]==v[1][3]+v[3][1])cnt++;

        ans=max(ans,cnt);
    }

    cout<<ans;
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
    // cout<<fixed<<setprecision(10);
    int _t=1;
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        cout<<"Case #"<<i<<": ";
        solve_GOOGLE();
    }
    return 0;
}
//	parsed : 11-July-2021 10:30:17 IST