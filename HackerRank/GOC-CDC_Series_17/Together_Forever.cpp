/**
 *    author:  Aryan Agarwal
 *    created: 18.06.2022 16:50:52 IST
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

pair <int,int> f(const string &s,int mid){
	if(mid==-1)return {-1,-1};
	int n=s.size();
	assert(mid>=1 && mid<=n);
	assert(s[mid-1]=='X');
	int mn=mid;
	int mx=mid;

	int move=0;
	int dirty=0;
	int tot=0;
	for(int i=1;i<mid;i++){
		if(s[i-1]=='X'){
			tot++;
		}
	}
	int pos=mid-tot;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='X'){
			move+=abs(i-pos);
			pos++;
			mn=min(mn,i);
			mx=max(mx,i);
		}
	}

	for(int i=mn;i<=mx;i++){
		if(s[i-1]=='D')dirty++;
	}

	return {move,dirty};
}

void solve()
{
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	int tot=0;
	for(int i=0;i<n;i++){
		if(s[i]=='X')tot++;
	}
	int mid1=-1;
	int mid2=-1;
	int id=0;
	for(int i=0;i<n;i++){
		if(s[i]!='X')continue;
		id++;
		if(tot&1){
			if(id==(tot+1)/2){
				mid1=i+1;
			}
		}else{
			if(id==tot/2){
				mid1=i+1;
			}
			if(id-1==tot/2){
				mid2=i+1;
			}
		}
	}

	// dbg(mid1,mid2);

	pair <int,int> a = f(s,mid1);
	pair <int,int> b = f(s,mid2);

	// dbg(a,b);

	int inf=  2e18;

	while (q--)
	{
		int mo,di;
		cin>>mo>>di;

		int ans=inf;

		if(a.first!=-1){
			ans=min(ans,mo*a.first + di*a.second);
		}
		if(b.first!=-1){
			ans=min(ans,mo*b.first + di*b.second);
		}

		cout<<ans<<" ";
	}
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}