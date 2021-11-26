/*
	group : Codeforces - Codeforces Round #756 (Div. 3)
	name : C. Polycarp Recovers the Permutation.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Polycarp_Recovers_the_Permutation.cpp
	url : https://codeforces.com/contest/1611/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 25.11.2021 20:23:15 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
bool ok;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void f(deque<int> &d1,deque<int> &d2)
{

	// dbg(d1,d2);

	if(d1.empty()){
		ok=true;
		return;
	}
		if(d1.front() < d2.back()){
			d2.push_front(d1.front());
			d1.pop_front();
			f(d1,d2);
			return;
		}

		if(d1.back() < d2.front()){
			d2.push_back(d1.back());
			d1.pop_back();
			f(d1,d2);
			return;
		}

		ok=false;
		return;
	
}

void f2(deque<int> &d1)
{
	while (!d1.empty())
	{
		cout<<d1.front()<<" ";
		d1.pop_front();
	}
	cout<<"\n";
	
}

void solve()
{
	int n;
	cin>>n;
	
	vector <int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}

	
	{
		deque<int> d1,d2;
		d2.push_back(v[0]);
		for(int i=1;i<n;i++){
			d1.push_back(v[i]);
		}
		ok=false;
		f(d1,d2);
		if(ok){f2(d2);return;}
		
	}
	{
		deque<int> d1,d2;
		d2.push_back(v[n-1]);
		for(int i=0;i<n-1;i++){
			d1.push_back(v[i]);
		}
		ok=false;
		f(d1,d2);
		if(ok){f2(d2);return;}
		
	}

	cout<<"-1\n";
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
//	parsed : 25-November-2021 20:12:33 IST