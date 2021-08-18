/*
	group : CodeChef - July Lunchtime 2021 Division 2
	name : Beautiful Pairs.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Beautiful_Pairs.cpp
	url : https://www.codechef.com/LTIME98B/problems/BUTYPAIR
*/
/**
 *    author:  Aryan Agarwal
 *    created: 31.07.2021 18:01:23 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;
    unordered_map<int,int> cnt;

    int tot=0;

    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }

    for(int i=0;i<n;i++)
    {
        tot+=n-cnt[a[i]];
    }

    cout<<tot<<"\n";
    
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
//	parsed : 31-July-2021 18:00:17 IST