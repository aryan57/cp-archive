/*
	group : local
	name : c2.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/c2.cpp
	url : /home/aryan/Desktop/cp-workspace/c2.cpp
*/
#include <iostream>
using namespace std;

int main()
{
	string a,b;
	cin>>a;cin>>b;

	int cnt1[200]={};
	int cnt2[200]={};

	for(char x : a)
	{
		cnt1[x-'A']++;
	}
	for(char x : b)
	{
		cnt2[x-'A']++;
	}

	for(int i=0;i<200;i++)
	{
		if(cnt1[i]!=cnt2[i])
		{
			char ans='A'+i;
			cout<<ans<<"\n";
			return 0;
		}
	}

	return 0;
}