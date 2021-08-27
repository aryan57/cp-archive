/*
	group : Facebook Coding Competitions - Facebook Hacker Cup 2021 Qualification Round
	name : B: Xs and Os.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Xs_and_Os.cpp
	url : https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/B
*/
/*
	author : aryan57
	created : 28-August-2021 01:14:57 IST
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

void rot(vector<vector<int>> &g)
{
	int n=g.size();

	F(i,0,n-1){
		F(j,i+1,n-1){
			if(i<j){
				swap(g[i][j],g[j][i]);
			}
		}
	}
}

pair <int,int> f(vector<vector<int>> &g){
	int n=sz(g);
	map<int,int> mp;
	F(i,0,n-1){
		bool ok = true;
		int sum=0;
		F(j,0,n-1){
			if(g[i][j]==-1){
				ok=false;
				break;
			}

			sum+=g[i][j];
		}

		if(ok){
			mp[sum]++;
		}
	}

	if(mp.empty())return {INF,0};
	return *mp.begin();
}

void solve_GOOGLE()
{
	int n;
	cin>>n;

	vector<vector<int>> g(n,vector<int>(n));

	F(i,0,n-1){
		F(j,0,n-1){
			char x;
			cin>>x;

			if(x=='.')g[i][j]=1;
			if(x=='X')g[i][j]=0;
			if(x=='O')g[i][j]=-1;
		}
	}

	auto p1=f(g);
	rot(g);
	auto p2=f(g);

	if(p1.X==INF && p2.X==INF){
		cout<<"Impossible\n";
		return;
	}

	pair <int,int>  ans;
	if(p1.X==p2.X){
		ans.X=p1.X;
		ans.Y+=p1.Y;
		ans.Y+=p2.Y;
	}
	else if(p1.X<p2.X){
		ans.X=p1.X;
		ans.Y+=p1.Y;
	}
	if(p1.X>p2.X){
		ans.X=p2.X;
		ans.Y+=p2.Y;
	}

	vector <bool> vi(n),vj(n);
	int z=0;

	if(ans.X==1)F(i,0,n-1){
			if(vi[i])continue;
		F(j,0,n-1){
			if(vj[j])continue;
			if(g[i][j]==-1){
				vi[i]=true;
				vj[j]=true;
				break;
			}
			if(g[i][j]==0){
				continue;
			}

			bool ok = true;

			F(p,i+1,n-1){
				if(g[p][j]!=0){
					ok=false;
					break;
				}
			}
			RF(p,i-1,0){
				if(g[p][j]!=0){
					ok=false;
					break;
				}
			}

			F(p,j+1,n-1){
				if(g[i][p]!=0){
					ok=false;
					break;
				}
			}
			RF(p,j-1,0){
				if(g[i][p]!=0){
					ok=false;
					break;
				}
			}

			// dbg(i,j,ok);

			if(ok)z++;

			vi[i]=true;
			vj[j]=true;
			break;
		}
	}

	cout<<ans.X<<" "<<ans.Y-z<<"\n";
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
//	parsed : 28-August-2021 01:14:50 IST