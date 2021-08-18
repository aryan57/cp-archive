/*
	group : Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
	name : A. PizzaForces.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_PizzaForces.cpp
	url : https://codeforces.com/contest/1555/problem/0
*/
/**
 *    author:  Aryan Agarwal
 *    created: 30.07.2021 20:08:04 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;
    int inf=1e18;
    int ans=inf;

    for(int x=0;x<=4;x++){
        for(int y=0;y<=4;y++){
            for(int z=0;z<=4;z++){
                
                int t = n-6*x+8*y+10*z;
                if(t<0)continue;
                int kk=inf;
                kk=min(kk,25*((t+9)/10));
                kk=min(kk,20*((t+7)/8));
                kk=min(kk,15*((t+5)/6));

                ans=min(ans,15*x+20*y+25*z+kk);

            }
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
//	parsed : 30-July-2021 20:05:06 IST