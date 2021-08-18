/*
	group : CodeChef - July Cook-Off 2021 Division 2
	name : Mod Equality.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Mod_Equality.cpp
	url : https://www.codechef.com/COOK131B/problems/MODEQUAL
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.07.2021 23:14:39 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);

    int cnt=1;
    bool ok = true;
    for(int i=1;i<n;i++){
        if(a[i]==a[0])cnt++;
        else {
            if(a[i]<=2*a[0]){
                ok=false;
                break;
            }
        }
    }

    cout<<(ok ? n-cnt : n)<<"\n";

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
//	parsed : 28-July-2021 23:05:45 IST