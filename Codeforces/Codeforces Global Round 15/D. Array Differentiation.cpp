/*
	group : Codeforces - Codeforces Global Round 15
	name : D. Array Differentiation.cpp
	srcPath : /home/aryan/cp-workspace/D_Array_Differentiation.cpp
	url : https://codeforces.com/contest/1552/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 26.07.2021 12:56:13 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &x : a)cin>>x;

    for(int num=1;num<(int)pow(3,n);num++){
        int sum=0;
        int ind=0;
        int nnum=num;
        while(nnum)
        {
            if(nnum%3==1)sum+=a[ind];
            if(nnum%3==2)sum-=a[ind];
            nnum/=3;
            ind++;
        }

        if(sum==0)
        {
            cout<<"Yes\n";
            return;
        }
    }

    cout<<"No\n";
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
//	parsed : 26-July-2021 12:56:08 IST