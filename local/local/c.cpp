/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/c.cpp
	url : /home/aryan/Desktop/cp-workspace/c.cpp
*/

#include <iostream>
using namespace std;

int bucketID(string x)
{
	int ans=0;
	for(char c : x)
	{
		ans=max(ans,c-'0');
	}

	return ans;
}

signed main()
{
	string x;
	cin>>x;
	cout<<bucketID(x);
	return 0;
}