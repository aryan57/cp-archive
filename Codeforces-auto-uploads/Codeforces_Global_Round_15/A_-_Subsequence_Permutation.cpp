/**
 *    author:  Aryan Agarwal
 *    created: 26.07.2021 11:01:11 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    int cnt=0;

    string t=s;
    sort(t.begin(),t.end());

    for(int i=0;i<n;i++){
        if(s[i]!=t[i])cnt++;
    }

    cout<<cnt<<"\n";
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
//	parsed : 26-July-2021 11:00:08 IST