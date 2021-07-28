/*
	group : CodeChef - July Cook-Off 2021 Division 2
	name : Chef and GCD.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Chef_and_GCD.cpp
	url : https://www.codechef.com/COOK131B/problems/CHFGCD
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.07.2021 22:42:01 IST
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b) /*__gcd doesn't work for big no.s*/
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int ans;
void f(int a,int b,int cur)
{
    if(ans!=-1)return;
    if(gcd(a,b)>1){
        ans=cur;
        return;
    }
    if(gcd(a+1,b)>1){
        ans=cur+1;
        return;
    }
    if(gcd(a,b+1)>1){
        ans=cur+1;
        return;
    }
    if(gcd(a+1,b+1)>1){
        ans=cur+1+1;
        return;
    }

    f(a+1,b+1,cur+1);
    f(a+1,b,cur+1);
    f(a,b+1,cur+1);

}

void solve()
{
    ans=-1;
    int a,b;
    cin>>a>>b;

    f(a,b,0);

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
//	parsed : 28-July-2021 22:40:52 IST