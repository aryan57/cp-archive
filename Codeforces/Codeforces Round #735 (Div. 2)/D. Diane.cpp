/*
	group : Codeforces - Codeforces Round #735 (Div. 2)
	name : D. Diane.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Diane.cpp
	url : https://codeforces.com/contest/1554/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.07.2021 23:01:59 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    if(n==1){
        cout<<"a\n";
        return;
    }
    if(n==2){
        cout<<"ab\n";
        return;
    }

    if(n%2==0){
        int k=(n-2)/2;
        cout<<string(k+1,'a')<<"b"<<string(k,'a')<<"\n";
        return;
    }
    int k=(n-3)/2;
    cout<<string(k+1,'a')<<"bc"<<string(k,'a')<<"\n";
    return;
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
//	parsed : 29-July-2021 23:01:54 IST