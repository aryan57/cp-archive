/**
 *    author:  Aryan Agarwal
 *    created: 12.09.2021 20:46:40 IST
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


void solve()
{
	int n,m;
	cin>>n>>m;
	int k=n*m;

	map<int,vector <int> > mp;

	for(int i=0;i<k;i++)
	{
		int x;
		cin>>x;
		mp[x].push_back(i);
	}


	int ans=0;

	vector< vector<int> > g(n,vector <int> (m,-1));
	vector< vector<int> > tt(n,vector <int> (m,-1));
	vector<pair<int,int> > pos(k);

	int ind=0;

	for(auto p : mp)
	{
		auto &v = p.second;
		sort(v.begin(),v.end());
		int t=v.size();

		int r=ind/m;
		int c=ind%m;

		if(c+t<=m)
		{
			int temp=0;
			for(int j=c+t-1;j>=c;j--)
			{
				g[r][j]=v[temp++];
				pos[g[r][j]]={r,j};
			}
			assert(temp==t);
			ind+=t;
		}
		else
		{
			int temp=0;
			for(int j=m-1;j>=c;j--)
			{
				g[r][j]=v[temp++];
				pos[g[r][j]]={r,j};
			}
			// reverse(v.begin(),v.end());
			int q=ind+t-1;
			int xx=temp;
			temp=t-1;

			pair <int,int> f={-1,-1};
			pair <int,int> l={-1,-1};

			while(temp>=xx)
			{
				if(l.first==-1)
				{
					l={q/m,q%m};
				}
				f={q/m,q%m};

				g[q/m][q%m]=v[temp--];
				pos[g[q/m][q%m]]={q/m,q%m};
				q--;
			}

			dbg(l,f);

			for(int rr=f.first;rr<l.first;rr++)
			{
				reverse(g[rr].begin(),g[rr].end());
			}

			reverse(g[l.first].begin(),g[l.first].begin()+l.second+1);

			// for(int j=t+c-m-1;j>=0;j--)
			// {
			// 	g[r+1][j]=v[temp++];
			// 	pos[g[r+1][j]]={r+1,j};
			// }
			// assert(temp==t);
			ind+=t;
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			pos[g[i][j]]={i,j};
		}
	}

	dbg(g);
	dbg(pos);

	for(int i=0;i<k;i++)
	{
		int r=pos[i].first;
		int c=pos[i].second;

		for(int j=0;j<m;j++)
		{
			if(j==c)
			{
				tt[r][c]=i;
				break;
			}

			if(tt[r][j]!=-1)ans++;
		}
	}

	cout<<ans;
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 12-September-2021 20:46:35 IST
//	parsed : 12-September-2021 21:00:37 IST