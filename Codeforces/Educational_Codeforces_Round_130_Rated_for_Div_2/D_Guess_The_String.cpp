/**
 *    author:  Aryan Agarwal
 *    created: 12.06.2022 20:59:15 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

char ask1(int ind){
	++ind;
	cout<<"? 1 "<<ind<<endl;
	fflush(stdout);
	char ans;
	cin>>ans;
	if(ans==0){
		exit(1);
	}
	return ans;
}

int ask2(int l,int r){
	++l;++r;
	cout<<"? 2 "<<l<<" "<<r<<endl;
	fflush(stdout);
	int ans;
	cin>>ans;
	if(ans==0){
		exit(1);
	}
	return ans;
}

int n;
const int mxn = 1000;
vector <int> val(mxn,-1);
set<int,greater<>> s;
vector <int> last(26,-1);
int to_use;

void f(int i){
	if(i>=n-1)return;

	for(int j=i+1;j<n;j++){
		int z = ask2(i,j);
		if(z==1){

			auto it = s.find(j-1);
			assert(it!=s.end());
			s.erase(it);

			last[val[i]]=j;
			s.insert(j);
			val[j]=val[i];
			continue;
		}
		assert(z==2);
	
		vector < pair <int,int>  > temp;
		int to_expect=2;
		for(auto p : s)temp.push_back({p,to_expect++});
		temp.erase(temp.begin());

		int l=0;
		int tempsz=temp.size();
		int r=tempsz-1;
		int ans=-1;
		bool extra=true;

		while (l<=r)
		{
			int m=(l+r)/2;
			int num = ask2(temp[m].first,j);
			if(num==temp[m].second){
				l=m+1;
			}else{
				assert(num<temp[m].second);
				extra=false;
				ans=m;
				r=m-1;
			}
		}

		if(!extra){
			auto it = s.find(temp[ans].first);
			assert(it!=s.end());
			s.erase(it);
			int oldval = val[temp[ans].first];
			last[oldval]=j;
			s.insert(j);
			extra=false;
			val[j]=oldval;
		}
		

		if(extra){
			val[j]=to_use++;
			last[val[j]]=j;
			s.insert(j);
		}

		f(j);
		return;
	}
}

void solve()
{
	cin>>n;
	val[0]=0;
	last[0]=0;
	to_use=1;
	s.insert({0,0});
	f(0);
	assert(to_use<=26);

	vector <char> mp(to_use);

	for(int i=0;i<to_use;i++){
		mp[i]=ask1(last[i]);
	}
	string ans(n,'0');
	for(int i=0;i<n;i++){
		ans[i]=mp[val[i]];
	}
	cout<<"! "<<ans<<endl;
	fflush(stdout);
}

signed main()
{
	solve();
	return 0;
}