/*
	group : Google Coding Competitions - Round G 2021 - Kick Start 2021
	name : Banana Bunches.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Banana_Bunches.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/00000000004362d6/00000000008b44ef
*/
/*
	author : aryan57
	created : 16-October-2021 18:13:17 IST
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

// #define int long long
#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

const long long INF = 1e9;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

struct node{
	int st, l, mn;
};

void solve_GOOGLE()
{
	int n,k;
	cin>>n>>k;

	int ans=INF;

	vector <node > pos[k+1];

	vector <int> a(n);
	for(int &x : a)cin>>x;

	F(i,0,n-1)
	{
		int s=0;
		F(j,i,n-1)
		{
			s+=a[j];
			if(s==k)ans=min(ans,j-i+1);
			if(s<k)pos[s].push_back({i,j-i+1,INF});
			else break;
		}
	}

	

	F(s,1,k)
	{
		int mn=INF;
		int t=pos[s].size();

		RF(i,t-1,0)
		{
			mn=min(mn,pos[s][i].l);
			pos[s][i].mn=mn;
		}
	}

	F(i,0,n-1)
	{
		int s=0;
		F(j,i,n-1)
		{
			s+=a[j];
			if(s>=k)break;

			// dbg(i,j,s);


			int ind=INF;
			int t=pos[k-s].size();
			if(t==0)continue;
			int l=0;
			int r=t-1;


			while (l<=r)
			{
				int m=(l+r)/2;

				if(pos[k-s][m].st<=j){
					l=m+1;
				}else{
					ind=m;
					r=m-1;
				}
			}

			if(ind!=INF){
				// dbg(i,j,s,ind);
				ans=min(ans,pos[k-s][ind].mn+j-i+1);
			}
			
		}
	}


	if(ans==INF)ans=-1;

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
//	parsed : 16-October-2021 18:04:43 IST