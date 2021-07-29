/*
	group : Codeforces - Codeforces Round #735 (Div. 2)
	name : C. Mikasa.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Mikasa.cpp
	url : https://codeforces.com/contest/1554/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.07.2021 22:37:06 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,m;
    cin>>n>>m;

    m++;

    int ans=0;
    for(int bit=32;bit>=0;bit--)
    {
        int a=((n>>bit)&1);
        int b=((m>>bit)&1);
        if(a==b)continue;
        if(a)break;
        ans+=(int)pow(2,bit);
    }
    cout<<ans<<"\n";
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