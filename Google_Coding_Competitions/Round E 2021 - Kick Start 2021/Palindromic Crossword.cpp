/*
	group : Google Coding Competitions - Round E 2021 - Kick Start 2021
	name : Palindromic Crossword.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Palindromic_Crossword.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/000000000043585c/0000000000859dcd
*/
/*
	author : aryan57
	created : 22-August-2021 10:50:08 IST
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

const int mxn = 1e3 + 10;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

vector< vector<bool> > vis(mxn+1,vector <bool> (mxn+1));
vector< vector<char> > g(mxn+1,vector <char> (mxn+1,'#'));
int n,m;
vector <vector <int> > r(mxn+1);
vector <vector <int> > c(mxn+1);
int cnt=0;

void dfs(int i,int j){

	assert(g[i][j]!='#');
	vis[i][j]=true;


	auto it  = upper_bound(all(r[i]),j);
	int ri=*it;
	it--;
	int le=*it;

	int d2=ri-j;
	int d1=j-le;

	if(d1!=d2){
		if(d1<d2){
			int next=ri-d1;
			if(next>j && !vis[i][next]){
				g[i][next]=g[i][j];
				cnt++;
				dfs(i,next);
			}
		}else{
			int next=le+d2;
			if(next<j && !vis[i][next]){
				g[i][next]=g[i][j];
				cnt++;
				dfs(i,next);
			}
		}
	}

	{
		auto it  = upper_bound(all(c[j]),i);
		int ri=*it;
		it--;
		int le=*it;

		int d2=ri-i;
		int d1=i-le;

		if(d1!=d2){
			if(d1<d2){
				int next=ri-d1;
				if(next>i && !vis[next][j]){
					g[next][j]=g[i][j];
					cnt++;
					dfs(next,j);
				}
			}else{
				int next=le+d2;
				if(next<i && !vis[next][j]){
					g[next][j]=g[i][j];
					cnt++;
					dfs(next,j);
				}
			}
		}
	}

}

void solve_GOOGLE()
{
	cnt=0;
	cin>>n>>m;
	F(i,1,n+1){
		r[i].clear();
		g[i][m+1]='#';
	}
	F(j,1,m+1){
		c[j].clear();
		g[n+1][j]='#';
	}
	vector< vector<char> > g2(n+1,vector <char> (m+1,'#'));
	F(i,1,n){
		r[i].push_back(0);
		F(j,1,m){
			cin>>g[i][j];
			g2[i][j]=g[i][j];
			if(g[i][j]=='#'){
				r[i].push_back(j);
			}

			vis[i][j]=false;
		}
		r[i].push_back(m+1);
	}

	F(j,1,m){
		c[j].push_back(0);
		F(i,1,n){
			if(g[i][j]=='#'){
				c[j].push_back(i);
			}
		}
		c[j].push_back(n+1);
	}

	F(i,0,n+1){
		if(i!=0 && i!=n+1)continue;
		F(j,0,m+1){
			if(j!=0 && j!=m+1)continue;
			vis[i][j]=false;
		}
	}

	F(i,1,n){
		F(j,1,m){
			if(vis[i][j] || g[i][j]<'A' || g[i][j]>'Z')continue;
			dfs(i,j);
		}
	}

	cnt=0;

	F(i,1,n){
		F(j,1,m){
			if(g2[i][j]=='.' && g[i][j]!='.')cnt++;
		}

	}
	cout<<cnt<<"\n";
	F(i,1,n){
		F(j,1,m){
			cout<<g[i][j];
		}cout<<"\n";
	}

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
//	parsed : 22-August-2021 10:50:05 IST