/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/c.cpp
	url : /home/aryan/Desktop/cp-workspace/c.cpp
*/
#include <iostream>
using namespace std;

string tostring(int x)
{
	string ans="";

	while (x)
	{
		ans+='0'+x%10;
		x/=10;
	}

	int n=ans.size();

	int l=0;
	int r=n-1;

	while(l<r)
	{
		swap(ans[l],ans[r]);
		l++;
		r--;
	}

	return ans;
	
}

signed main()
{
	int n;
	cin>>n;
	if(n==1){
		cout<<1;
		cout<<"\n";
		return 0;
	}

	string v[n];
	int id=1;
	for(int i=0;i<n;i++)
	{
		string t="";
		for(int j=0;j<n-1;j++)
		{
			t+=tostring(id++);
			t+="*";
		}
		t+=tostring(id++);
		v[i]=t;
	}

	int l=0;
	int r=n-1;

	string ans[n];
	int use=0;

	int rem=n;
	id=0;
	while (rem--)
	{
		if(use==0){
			ans[l++]=v[id++];
			
		}
		else{
			ans[r--]=v[id++];

		}
		use^=1;
	}

	for(int i=0;i<n;i++){
		cout<<ans[i]<<"\n";
	}
	

	return 0;
}