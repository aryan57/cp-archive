/*
	group : Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
	name : B. Two Tables.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Two_Tables.cpp
	url : https://codeforces.com/contest/1555/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 30.07.2021 20:24:44 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int w,h;
    cin>>w>>h;
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    
    int r,c;
    cin>>c>>r;
    int inf=1e18;
    int ans=inf;

    if(r<=y1){
        cout<<0<<"\n";
        return;
    }
    if(r-y1+y2<=h){
        ans=min(ans,r-y1);
    }

    if(r<=(h-y2)){
        cout<<0<<"\n";
        return;
    }
    if(y1-(r-(h-y2))>=0){
        ans=min(ans,(r-(h-y2)));
    }

    swap(r,c);
    swap(h,w);
    swap(x1,y1);
    swap(x2,y2);

    if(r<=y1){
        cout<<0<<"\n";
        return;
    }
    if(r-y1+y2<=h){
        ans=min(ans,r-y1);
    }

    if(r<=(h-y2)){
        cout<<0<<"\n";
        return;
    }
    if(y1-(r-(h-y2))>=0){
        ans=min(ans,(r-(h-y2)));
    }


    if(ans==inf)ans=-1;
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
//	parsed : 30-July-2021 20:18:15 IST