/*
	group : CodeChef - September Lunchtime 2021 Division 1
	name : Subsequence LCS.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Subsequence_LCS.cpp
	url : https://www.codechef.com/LTIME100A/problems/SUBLCS
*/
/*
	author : aryan57
	created : 25-September-2021 20:58:20 IST
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


int longestCommonSubsequence(vector <int>  text1, vector <int>  text2) {
        int x = text1.size();
        int y = text2.size();
        int dp[x+1][y+1];

            for(int i=0;i<=x;i++)
                dp[i][0] = 0;

            for(int i=0;i<=y;i++)
                dp[0][i] = 0;

            for(int i=1;i<=x;i++){
                for(int j=1;j<=y;j++){
                    if(text1[i-1]==text2[j-1])
                        dp[i][j] = 1+dp[i-1][j-1];
                    else
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }

            return dp[x][y];
    }

void solve_LOL()
{
	int n;
	cin>>n;

	vector <int> a(n);
	for(int &x : a)cin>>x;
	int l=0;
	int r=0;
	vector<int> d1(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && d1[i] < d1[j] + 1) {
                d1[i] = d1[j] + 1;
				l=max(l,d1[i]);
            }
        }
    }
	vector<int> d2(n, 1);
    for (int i = n-1; i >=0; i--) {

        for (int j = i+1; j < n; j++) {
            if (a[i]<a[j] && d2[i] < d2[j] + 1) {
                d2[i] = d2[j] + 1;
            }
        }
    }
	vector<int> d3(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i] && d3[i] < d3[j] + 1) {
                d3[i] = d3[j] + 1;
				r=max(r,d3[i]);
            }
        }
    }
	vector<int> d4(n, 1);
    for (int i = n-1; i >=0; i--) {

        for (int j = i+1; j < n; j++) {
            if (a[i]>a[j] && d4[i] < d4[j] + 1) {
                d4[i] = d4[j] + 1;
            }
        }
    }

	// dbg(l,r);
	// dbg(d1,d2);
	// dbg(d3,d4);

	F(i,0,n-1)
	{
		if(d1[i]==l && d3[i]==r){
			// dbg(i,i);
			cout<<1;
			cout<<"\n";
			return;
		}
		if(d2[i]==l && d4[i]==r){
			// dbg(i);
			cout<<1;
			cout<<"\n";
			return;
		}
	}

	cout<<0;
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
		// cout<<"Case #"<<i<<": ";
		solve_LOL();
	}
	return 0;
}
//	parsed : 25-September-2021 20:58:17 IST