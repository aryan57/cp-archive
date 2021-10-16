/*
	group : Google Coding Competitions - Round G 2021 - Kick Start 2021
	name : Staying Hydrated.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Staying_Hydrated.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/00000000004362d6/00000000008b3a1c
*/
/*
	author : aryan57
	created : 16-October-2021 17:42:51 IST
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
int n;

int f(vector <pair <int,int> > &x)
{
	int mn=INF;

	vector <int> x1(n),x2(n);
	F(i,0,n-1){
		x1[i]=x[i].X;
		x2[i]=x[i].Y;
	}

	sort(all(x1));
	sort(all(x2));

	vector <int> p1(n+1),p2(n+1);
	F(i,1,n){
		p1[i]=p1[i-1]+x1[i-1];
		p2[i]=p2[i-1]+x2[i-1];
	}

	// dbg(x1);
	// dbg(x2);

	int ans=INF;

	F(i,0,n-1)
	{
		{
			int p=x1[i];

			int sum=0;
			sum+=p1[n]-p1[i+1];
			sum-=(n-i-1)*p;

			int ind = upper_bound(all(x2),p)-x2.begin();
			ind--;

			if(ind>=0){
				sum+=(ind+1)*p;
				sum-=p2[ind+1];
			}

			if(sum<mn){
				mn=sum;
				ans=p;
			}else if(sum==mn){
				ans=min(ans,p);
			}
		}
		{
			int p=x2[i];

			int sum=0;
			sum-=p2[i];
			sum+=i*p;

			int ind = lower_bound(all(x1),p)-x1.begin();

			if(ind<n){
				sum+=p1[n]-p1[ind];
				sum-=(n-ind)*p;
			}

			if(sum<mn){
				mn=sum;
				ans=p;
			}else if(sum==mn){
				ans=min(ans,p);
			}
		}
	}

	// dbg(mn,ans);

	return ans;

}

void solve_GOOGLE()
{
	
	cin>>n;

	vector<pair<int,int> > x(n),y(n);

	F(i,0,n-1)
	{
		cin>>x[i].X>>y[i].X;
		cin>>x[i].Y>>y[i].Y;
	}

	// f(x);
	cout<<f(x)<<" "<<f(y);
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
//	parsed : 16-October-2021 17:33:54 IST