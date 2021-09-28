/*
	group : Codeforces - Codeforces Round #744 (Div. 3)
	name : C. Ticks.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Ticks.cpp
	url : https://codeforces.com/contest/1579/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.09.2021 20:25:40 IST
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
	int n,m,k;
	cin>>n>>m>>k;

	vector <string> v(n),a(n);

	for(int i=0;i<n;i++){
		cin>>v[i];
		a[i]=string(m,'.');
	}

	vector< vector<bool> > center(n,vector <bool> (m,false));

	for(int i=k;i<n;i++){
		for(int j=k;j<m-k;j++){
			if(v[i][j]=='.')continue;

			center[i][j]=true;

			for(int h=0;;h++){
				if(i-h<0)break;
				if(j-h<0)break;
				if(j+h>=m)break;

				a[i-h][j-h]='*';
				a[i-h][j+h]='*';
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(v[i][j]=='*' && a[i][j]!='*'){
				cout<<"NO\n";
				return;
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(v[i][j]=='.')continue;

			int hh=0;

			for(int h=1;;h++){
				if(i-h<0)break;
				if(j-h<0)break;
				if(j+h>=m)break;

				if(v[i-h][j-h]!='*' || v[i-h][j+h]!='*'){
					break;
				}
				hh=h;
			}

			if(hh>=k && center[i][j]){
				dbg(i,j);
				continue;
			}

			bool ok = false;

			

			for(int h=1;;h++){
				if(i+h>=n || ok)break;

				if(j+h<m && j+2*h<m && center[i+h][j+h]){
					

					bool tt=true;
					for(int zz=0;zz<=h;zz++){
						if(v[i+h-zz][j+h+zz]!='*' || v[i+h-zz][j+h-zz]!='*' || a[i+h-zz][j+h+zz]!='*' || a[i+h-zz][j+h-zz]!='*'){
							tt=false;
							break;
						}
					}

					if(tt){
						ok=true;
						break;
					}
					
				}
				if(j-h>=0 && j-2*h>=0 && center[i+h][j-h]){
					bool tt=true;
					for(int zz=0;zz<=h;zz++){
						if(v[i+h-zz][j-h+zz]!='*' || v[i+h-zz][j-h-zz]!='*' || a[i+h-zz][j-h+zz]!='*' || a[i+h-zz][j-h-zz]!='*'){
							tt=false;
							break;
						}
					}

					if(tt){
						ok=true;
						break;
					}
				}
			}

			if(!ok){
				// dbg(i,j);
				cout<<"NO\n";
				return;
			}

		}
	}

	cout<<"YES\n";
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
//	parsed : 28-September-2021 20:21:02 IST