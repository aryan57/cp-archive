/*
	group : Codeforces - Codeforces Round #517 (Div. 2, based on Technocup 2019 Elimination Round 2)
	name : D. Minimum path.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Minimum_path.cpp
	url : https://codeforces.com/contest/1072/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 25.09.2021 00:28:39 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

vector<int> plus_x={0,1,0,-1};
vector<int> plus_y={-1,0,1,0};

vector<int> star_x={1,1,-1,-1};
vector<int> star_y={-1,1,1,-1};

vector<int> square_x={0,1,1,1,0,-1,-1,-1};
vector<int> square_y={-1,-1,0,1,1,1,0,-1};

bool is_inside(int x,int y,int n,int m)
{
	return (x>=0 && x<n && y>=0 && y<m);
}

void solve()
{
	int n,k;
	cin>>n>>k;

	string ans(2*n-1,'z');

	vector <string> g(n);

	for(auto &s : g)cin>>s;
	int inf  = 1e9;
	vector< vector<int> > dp(n,vector <int> (n,inf));

	vector<pair<int,pair <int,int> > > t;

	dp[0][0]=0;
	if(g[0][0]!='a')dp[0][0]=1;

	for(int i=1;i<n;i++)
	{
		dp[i][0]=dp[i-1][0];
		if(g[i][0]!='a')dp[i][0]++;

		if(dp[i][0]<=k){
			t.push_back({0+i+1,{i,0}});
		}
	}
	for(int j=1;j<n;j++)
	{
		dp[0][j]=dp[0][j-1];
		if(g[0][j]!='a')dp[0][j]++;

		if(dp[0][j]<=k){
			t.push_back({0+j+1,{0,j}});
		}
	}

	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
			if(g[i][j]!='a')dp[i][j]++;
			if(dp[i][j]<=k){
				t.push_back({i+j+1,{i,j}});
			}
		}
	}

	bool z=false;

	if(t.empty()){
		t.push_back({1,{0,0}});
		z=true;
	}

	// dbg(t);

	sort(t.begin(),t.end(),greater<>());

	string aa(t[0].first,'a');
	int mx=0;
	for(auto p : t)
	{
		mx=max(mx,p.first);
		if(p.first!=mx)break;
		int i=p.second.first;
		int j=p.second.second;

		queue<pair <int,int> > q;
		vector< vector<bool> > visited(n,vector <bool> (n));
		vector< vector<pair <int,int> > > parent(n,vector <pair <int,int> > (n,{-1,-1}));
		
		q.push({i,j});
		visited[i][j] = true;
		while (!q.empty()) {
		
			pair <int,int>  parent_node = q.front();
			q.pop();
			
			int r1 = parent_node.first+1; 
			int c1 = parent_node.second;
			int r2 = parent_node.first; 
			int c2 = parent_node.second+1;

			bool ok1=true;
			bool ok2=true;

			if(!is_inside(r1,c1,n,n) || visited[r1][c1])ok1=false;
			if(!is_inside(r2,c2,n,n) || visited[r2][c2])ok2=false;

			bool z1=false;
			bool z2=false;

			if(!ok1 && !ok2)continue;
			if(ok1 && ok2 && (g[r1][c1]==g[r2][c2])){

				z1=true;
				z2=true;
			}else if((ok1 && !ok2) || (ok1 && ok2 && (g[r1][c1]<g[r2][c2]))){
				z1=true;
				
			}else if((!ok1 && ok2) || (ok1 && ok2 && (g[r1][c1]>g[r2][c2]))){

				z2=true;
			}

			if(z1){
				q.push({r1,c1});
				parent[r1][c1]=parent_node;
				visited[r1][c1]=true;
				
			}

			if(z2){
				parent[r2][c2]=parent_node;
				visited[r2][c2]=true;
				q.push({r2,c2});
			}
		}

		string zz="";

		pair <int,int> cur={n-1,n-1};

		while (!(cur.first==i && cur.second==j))
		{
			zz+=g[cur.first][cur.second];
			cur=parent[cur.first][cur.second];
		}

		// dbg(i,j,zz);
		reverse(zz.begin(),zz.end());


		ans=min(ans,aa+zz);
		
	}

	if(z)ans[0]=g[0][0];

	cout<<ans;


}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 25-September-2021 24:06:55 IST