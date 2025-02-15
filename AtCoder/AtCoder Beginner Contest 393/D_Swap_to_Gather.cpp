/**
 *    author:  Aryan Agarwal
 *    created: 15.02.2025 17:57:55 IST
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
	int n;
	cin>>n;
	string s;
	cin>>s;

	int tot=0;
	for(char x : s){
		if(x=='1')tot++;
	}

	function<vector<int>()> fun = [&]() -> vector<int> {
		vector<int> ans(n);
		
		stack<int> zero;
		for(int i=n-1;i>=0;i--){
			if(s[i]=='0')zero.push(i);
		}

		int sum0=0,sum1=0;
		deque<int> window;
		for(int i=0;i<tot;i++){
			if(s[i]=='0')window.push_back(i);
		}

		for(int l=0,r=tot-1;r<n;l++,r++){
			ans[l] = sum0-sum1;

			if(r+1==n)break;

			if(s[r+1]=='0'){
				window.push_back(r+1);
			}

			if(s[l]=='0'){
				if(sum0>0){
					sum0-=l;
					sum0+=window.front();
					window.pop_front();
				}
			}else if(s[l]=='1'){
				sum1+=l;
				while (!window.empty()){
					if(window.front()>=l){
						sum0+=window.front();
						window.pop_front();
						break;
					}
					window.pop_front();
				}
								
			}
			
		}

		return ans;
	};

	vector<int> f1 = fun();
	// dbg(f1);
	reverse(s.begin(),s.end());
	vector<int> f2 = fun();
	reverse(f2.begin(),f2.end());
	// dbg(f2);
	int inf = 1e18;
	int ans=inf;

	for(int l=0,r=tot-1;r<n;l++,r++){
		ans = min(ans, f1[l]+f2[r]);
	}

	cout<<ans;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		solve();
	}
	return 0;
}