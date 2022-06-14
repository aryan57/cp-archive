/**
 *    author:  Aryan Agarwal
 *    created: 22.05.2022 17:15:28 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node {
	int a,b;
	bool operator<(const Node& y) const { 
		if(a!=y.a)return a<y.a;
		return b<y.b;
	 }
};

void solve()
{
	int n,L;
	cin>>n>>L;
	vector<Node> relative_time(n);
	vector<Node> relative_position(n);


	for(int i=0;i<n;i++){
		int x,d;
		cin>>x>>d;
		int t = 0;
		if(d==0){
			t=x;
		}else{
			t=L-x;
		}
		relative_time[i] = {t,d};
		relative_position[i] = {x,i};
	}

	sort(relative_time.begin(),relative_time.end());
	sort(relative_position.begin(),relative_position.end());
	vector<Node> ants;
	int l=0;
	int r=n-1;
	for(auto t : relative_time){
		int d = t.b;
		if(d==0)ants.push_back({t.a,relative_position[l++].b});
		else ants.push_back({t.a,relative_position[r--].b});
	}

	sort(ants.begin(),ants.end());
	for(auto p : ants)cout<<p.b+1<<" ";
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}