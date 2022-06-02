#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	string s;
	cin>>s;
	int n=s.size();
	int tot=0;
	
	for(char x : s){
		tot+=x-'a'+1;
	}
	
	if(n%2==0){
		cout<<"Alice "<<tot<<"\n";
		return;
	}
	int b=min(s[0]-'a',s[n-1]-'a')+1;
	tot-=b;
	assert(tot!=b);
	if(tot<b){
		cout<<"Bob "<<b-tot<<"\n";
	}else{
		cout<<"Alice "<<tot-b<<"\n";
	}
	
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int _t=1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
