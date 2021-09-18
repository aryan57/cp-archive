/*
	group : AtCoder - Sciseed Programming Contest 2021（AtCoder Beginner Contest 219）
	name : E - Moat.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Moat.cpp
	url : https://atcoder.jp/contests/abc219/tasks/abc219_e
*/
/**
 *    author:  Aryan Agarwal
 *    created: 18.09.2021 18:20:51 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> plus_x={0,1,0,-1};
vector<int> plus_y={-1,0,1,0};

bool is_inside(int x,int y)
{
	return (x>=1 && x<=4 && y>=1 && y<=4);
}

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void solve()
{

	vector< vector<int> > x(5,vector <int> (5,0));
	int tot=0;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			cin>>x[i][j];
			if(x[i][j])tot++;
		}
	}

	int ans=0;

	for(int i=1;i<(int)pow(2,16);i++)
	{
		vector< vector<int> > g(5,vector <int> (5,0));
		vector< vector<bool> > vis(5,vector <bool> (5,false));

		int rem2=0;
		for(int num=0;num<16;num++)
		{
			if((i>>num)&1)
			{
				g[num/4+1][num%4+1]=1;
				rem2++;
			}
		}

		int flag=0;
		int rem=tot;
		for(int i=1;i<=4;i++)
		{
			for(int j=1;j<=4;j++)
			{
				if(!g[i][j])continue;
				queue<pair <int,int> > q;
				
				q.push({i,j});
				vis[i][j] = true;
				if(x[i][j])rem--;
				
				while (!q.empty()) {
				
					pair <int,int>  parent_node = q.front();
					q.pop();
					rem2--;

					for(int k=0;k<4;k++)
					{
						int r=parent_node.first+plus_x[k];
						int c=parent_node.second+plus_y[k];

						if(!is_inside(r,c) || g[r][c]!=1 || vis[r][c])continue;
						vis[r][c]=true;
						q.push({r,c});
						if(x[r][c])rem--;
					}
				}

				if(rem==0 && rem2==0){
					flag=1;
				}else{
					flag=-1;
				}

				break;
			}

			if(flag!=0)break;
		}

		if(flag==1){

			for(int i : {2,3})
			{
				for(int j : {2,3})
				{
					if(g[i][j])continue;
					queue<pair <int,int> > q;
					vector< vector<bool> > vis(5,vector <bool> (5,false));
					q.push({i,j});
					vis[i][j] = true;

					bool ok = false;
					
					while (!q.empty()) {
					
						pair <int,int>  parent_node = q.front();
						q.pop();

						if(parent_node.first==1 || parent_node.second==1){
							ok=true;
							break;
						}
						if(parent_node.first==4 || parent_node.second==4){
							ok=true;
							break;
						}

						for(int k=0;k<4;k++)
						{
							int r=parent_node.first+plus_x[k];
							int c=parent_node.second+plus_y[k];

							if(!is_inside(r,c) || g[r][c] || vis[r][c])continue;
							vis[r][c]=true;
							q.push({r,c});
						}
					}

					if(!ok){
						flag=-1;
						break;
					}
				}

				if(flag!=1)break;
			}
			

			if(flag==1)ans++;
		}



	}

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
//	parsed : 18-September-2021 18:01:12 IST