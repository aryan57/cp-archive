/*
	group : Codeforces - Educational Codeforces Round 111 (Rated for Div. 2)
	name : C. Manhattan Subarrays.cpp
	srcPath : /home/aryan/cp-workspace/C_Manhattan_Subarrays.cpp
	url : https://codeforces.com/contest/1550/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 25.07.2021 00:48:56 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;
    int v[n];
    int ans=2*n-1;
    for(int &x : v){
        cin>>x;
    }
    for(int l=0;l<=n-3;l++){
        bool ok = true;
        for(int r=l+2;r<=n-1;r++){
            for(int i=l;i<=r-2;i++){
                for(int j=i+1;j<=r-1;j++){
                    for(int k=j+1;k<=r;k++){
                        if(abs(v[i]-v[k])==abs(v[i]-v[j]) + abs(v[j]-v[k])){
                            ok=false;
                            break;
                        }
                    }if(!ok)break;
                }if(!ok)break;
            }if(!ok)break;
            ans++;
        }
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
//	parsed : 25-July-2021 24:48:49 IST