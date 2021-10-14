/*
	group : Codeforces - Codeforces Round #748 (Div. 3)
	name : F. Red-Black Number.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/F_Red_Black_Number.cpp
	url : https://codeforces.com/contest/1593/problem/F
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.10.2021 21:33:16 IST
**/



#include <bits/stdc++.h>
using namespace std;

int n,a,b;
string z;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

string encode(int cx,int cy,int p1,int p2)
{
	string temp="";

	if(cx<10)temp+='0';
	temp+=to_string(cx);
	if(cy<10)temp+='0';
	temp+=to_string(cy);
	if(p1<10)temp+='0';
	temp+=to_string(p1);
	if(p2<10)temp+='0';
	temp+=to_string(p2);

	return temp;
}

string f(int x,int y)
{
	int k=n/2;

	unordered_map<string,bool> mp;
	unordered_map<string,int> mp2;

	for(int num=0;num<(1<<k);num++)
	{
		int p1=0;
		int p2=0;

		int cx=0;
		int cy=0;

		for(int bit=k-1;bit>=0;bit--)
		{
			if((num>>bit)&1)
			{
				p1*=10;
				p1%=a;
				p1+= (z[n-1-bit]-'0');
				p1%=a;
				cx++;
			}else{
				p2*=10;
				p2%=b;
				p2+= (z[n-1-bit]-'0');
				p2%=b;
				cy++;
			}
		}

		if(x-cx<0 || y-cy<0)continue;
		
		mp[encode(cx,cy,p1,p2)]=true;
		mp2[encode(cx,cy,p1,p2)]=num;
	}

	k=n-n/2;
	for(int num=0;num<(1<<k);num++)
	{
		int p1=0;
		int p2=0;

		int cx=0;
		int cy=0;

		for(int bit=0;bit<k;bit++)
		{
			if((num>>bit)&1)
			{
				p1*=10;
				p1%=a;
				p1+= (z[bit]-'0');
				p1%=a;
				cx++;
			}else{
				p2*=10;
				p2%=b;
				p2+= (z[bit]-'0');
				p2%=b;
				cy++;
			}
		}

		if(x-cx<0 || y-cy<0)continue;

		for(int temp=x-cx;temp>0;temp--){
			p1*=10;
			p1%=a;
		}
		for(int temp=y-cy;temp>0;temp--){
			p2*=10;
			p2%=b;
		}

		if(mp[encode(x-cx,y-cy,(a-p1)%a,(b-p2)%b)])
		{
			string ans="";
			for(int bit=0;bit<n-n/2;bit++)
			{
				if((num>>bit)&1)
				{
					ans+='R';
				}else{
					ans+='B';
				}
			}


			int val = mp2[encode(x-cx,y-cy,(a-p1)%a,(b-p2)%b)];

			for(int bit=n/2-1;bit>=0;bit--)
			{
				if((val>>bit)&1)
				{
					ans+='R';
				}else{
					ans+='B';
				}
			}

			return ans;
		}
	}

	return "-1";
}

void solve()
{
	
	cin>>n>>a>>b;
	cin>>z;

	// reverse(z.begin(),z.end());

	string ans="";

	ans=f((n+1)/2,n-(n+1)/2);
	if(ans!="-1"){
		cout<<ans;
		cout<<"\n";
		return;
	}

	ans=f((n)/2,n-(n)/2);
	if(ans!="-1"){
		cout<<ans;
		cout<<"\n";
		return;
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
//	parsed : 14-October-2021 21:32:46 IST