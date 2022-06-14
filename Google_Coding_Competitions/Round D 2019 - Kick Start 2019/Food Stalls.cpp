/*
	group : Google Coding Competitions - Round D 2019 - Kick Start 2019
	name : Food Stalls.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Food_Stalls.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/0000000000051061/0000000000161476
*/
/*
	author : aryan57
	created : 17-September-2021 21:37:40 IST
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

void cal(vector<pair<int,int> > &v,vector <int> &a,int mx)
{
	int n=v.size();
	priority_queue<int> pq;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		a[i]=INF;
		if(pq.size()==mx){
			a[i]=sum-mx*v[i].first;
		}

		pq.push(v[i].first+v[i].second);
		sum+=v[i].first+v[i].second;
		if(pq.size() > mx)
		{
			sum-=pq.top();
			pq.pop();
		}
	}
}

void solve_GOOGLE()
{
	int n,k;
	cin>>k>>n;

	int z=1e9;

	vector<pair<int,int> > v(n);

	for(int i=0;i<n;i++)cin>>v[i].first;
	for(int i=0;i<n;i++)cin>>v[i].second;

	sort(all(v),greater<pair <int,int> > ());

	vector <int> left(n),right(n);

	cal(v,left,k/2);

	for(int i=0;i<n;i++){
		v[i].first=z-v[i].first;
	}

	reverse(all(v));
	cal(v,right,k-k/2);
	reverse(all(v));
	reverse(all(right));

	int ans=INF;

	// dbg(left,right,v);

	for(int i=0;i<n;i++)
	{
		ans=min(ans,left[i]+right[i]+v[i].second);
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
//	parsed : 17-September-2021 21:07:09 IST