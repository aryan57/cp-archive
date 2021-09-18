/*
	group : Google Coding Competitions - Round F 2021 - Kick Start 2021
	name : Star Trappers.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Star_Trappers.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435bae/0000000000888d45
*/
/*
	author : aryan57
	created : 18-September-2021 23:09:12 IST
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



long double cal(pair <int,int> x,pair <int,int> y,pair <int,int> z)
{
	long double ans=0.0;
	vector<pair<int,int> > v;
	v.push_back(x);
	v.push_back(y);
	v.push_back(z);

	F(i,0,2)
	{
		F(j,i+1,2)
		{
			ans+=sqrt((v[i].X-v[j].X)*(v[i].X-v[j].X) + (v[i].Y-v[j].Y)*(v[i].Y-v[j].Y));
		}
	}

	return ans;
}
bool f(pair <int,int> x,pair <int,int> y,pair <int,int> z)
{
	vector<pair<int,int> > v;
	v.push_back(x);
	v.push_back(y);
	v.push_back(z);

	// dbg(v);

	F(i,0,2)
	{
		F(j,i+1,2)
		{
			int s1=(v[j].X-v[i].X)*(-v[i].Y) - (v[j].Y-v[i].Y)*(-v[i].X);
			if(s1==0)return false;
			int s2=(v[j].X-v[i].X)*(v[i^j^3].Y-v[i].Y) - (v[j].Y-v[i].Y)*(v[i^j^3].X-v[i].X);
			if(s2==0)return false;
			// dbg(i,j,s1,s2);
			if(s1>0 && s2<0)return false;
			if(s1<0 && s2>0)return false;
		}
	}

	return true;
}

void solve_GOOGLE()
{
	int n;
	cin>>n;

	vector<pair<int,int> > v(n);
	int x,y;

	F(i,0,n-1)
	{
		cin>>v[i].X>>v[i].Y;
	}

	cin>>x>>y;
	F(i,0,n-1)
	{
		v[i].X-=x;
		v[i].Y-=y;
	}

	long double ans=2e18;
	bool ok = false;

	set<long double> ss;

	F(i,0,n-1)
	{
		F(j,i+1,n-1)
		{
			F(k,j+1,n-1)
			{
				if(f(v[i],v[j],v[k]))
				{
					ok=true;
					long double zz= cal(v[i],v[j],v[k]);
					ans=min(ans,zz);
					ss.insert(zz);
				}
			}
		}
	}

	if(!ok){
		if(ss.size()>=2)
		{
			long double zz= 0;
			zz+=*ss.begin();
			ss.erase(ss.begin());
			zz+=*ss.begin();

			cout<<zz;
			cout<<"\n";
			return;
		}
		cout<<"IMPOSSIBLE";
		cout<<"\n";
		return;
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
	cout<<fixed<<setprecision(10);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve_GOOGLE();
	}
	return 0;
}