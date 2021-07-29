/*
	group : Codeforces - Codeforces Round #735 (Div. 2)
	name : C. Mikasa.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Mikasa.cpp
	url : https://codeforces.com/contest/1554/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.07.2021 20:59:12 IST
**/
#include <bits/stdc++.h>
using namespace std;

int f(int n,int m)
{
    assert(n>=0 && m>=0);

    if(m<n)return 0;
    if(n==0)return m+1;

    int l = (int)floor(log2(n));

    int lem = 2 * ((int)(pow(2, l)));

    int k=m/lem;

    if(k==0)return f(n-lem/2,m-lem/2);

    int rem = m % lem;

    return f(n,rem) + k*lem;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    cout<<f(n,m);
    cout<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    cin >> _t;
    while (_t--)
        solve();
    return 0;
}
//	parsed : 29-July-2021 20:59:04 IST