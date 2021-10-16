/*
	group : Google Coding Competitions - Round G 2021 - Kick Start 2021
	name : Simple Polygon.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Simple_Polygon.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/00000000004362d6/00000000008b36f9
*/
/*
	author : aryan57
	created : 16-October-2021 19:42:01 IST
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

void f3(int a)
{
	cout<<"POSSIBLE\n";
	cout<<"0 0\n";
	cout<<"1 0\n";
	cout<<"0 "<<a<<"\n";
}
void f4(int a)
{
	if(a%2==0){
		cout<<"POSSIBLE\n";
		cout<<"0 0\n";
		cout<<"1 0\n";
		cout<<"1 "<<a/2<<"\n";
		cout<<"0 "<<a/2<<"\n";
		return;
	}

	if(a==1){
		cout<<"IMPOSSIBLE\n";
		return;
	}

	cout<<"POSSIBLE\n";
	cout<<"0 0\n";
	cout<<(a-1)/2+1<<" 0\n";
	cout<<(a-1)/2+1<<" 1\n";
	cout<<"1 1\n";
}

void f5(int a)
{
	for(int i=1;i*i<=a;i++)
	{
		if(a%i==0){
			set<int> fa;
			fa.insert(i);
			fa.insert(a/i);

			for(int lem : fa)
			{
				lem--;
				if(lem==0)continue;
				int z=a/(lem+1);
				int x=-1;
				int y=-1;
				if(z%2){
					x=1;
					y=(z-1)/2;
				}else{
					x=2;
					y=(z-2)/2;
				}

				if(x<=0 || y<=0)continue;

				cout<<"POSSIBLE\n";
				cout<<"0 0\n";
				cout<<1+lem<<" 0\n";
				cout<<1+lem<<" "<<y<<"\n";
				cout<<1<<" "<<x+y<<"\n";
				cout<<"0 "<<y<<"\n";

				return;
			}
		}
	}
	int mx=1e5;
	int z2=1e9;
	F(h,1,mx)
	{
		int z = a-2*(1+h);
		if((z%(2+h))==0 && z>0 && z/(2+h)>0 ){
			int lem = z/(2+h);

			if(lem+2>z2)continue;

			cout<<"POSSIBLE\n";
			cout<<"1 0\n";
			cout<<1+lem<<" 0\n";
			cout<<2+lem<<" "<<1<<"\n";
			cout<<1<<" "<<h+1<<"\n";
			cout<<"0 "<<1<<"\n";
			return;

		}
	}
	F(x,1,mx)
	{
		int z = a-(1+2*x);
		if((z%(1+x))==0 && z>0 && z/(1+x)>0 ){
			int y = z/(1+x);

			if(x>z2)continue;
			if(y>z2)continue;

			cout<<"POSSIBLE\n";
			cout<<"0 1\n";
			cout<<"1 0\n";
			cout<<1+x<<" 0\n";
			cout<<1+x<<" 1\n";
			cout<<"0 "<<y+1<<"\n";
			return;

		}
	}

	cout<<"IMPOSSIBLE\n";
}

void solve_GOOGLE()
{
	int n,a;
	cin>>n>>a;

	if(n==3)f3(a);
	else if(n==4)f4(a);
	else if(n==5)f5(a);
	
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
//	parsed : 16-October-2021 19:41:50 IST