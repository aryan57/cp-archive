//https://codeforces.com/contest/1304/problem/C

/*
    author : Aryan Agarwal, IIT KGP
    created : 21-June-2020 13:41:12
*/

#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n,m;
    cin>>n>>m;

    int minn,maxx;
    minn=maxx=m;

    bool ok=true;

    int t,lef,rig;
    int pret=0;
    for(int i=0;i<n;i++)
    {
        cin>>t>>lef>>rig;
        t-=pret;
        if((rig<(minn-t)) || (lef>(maxx+t)))ok&=false;

        minn=max(minn-t,lef);
        maxx=min(maxx+t,rig);
        pret+=t;
    }

    if(ok)cout<<"YES";
    else cout<<"NO";
}
  
signed main()
{
    #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    #endif

    int _t;
    cin>>_t;
    while(_t--)
    {
        solve();
        cout<<"\n";
    }

    return 0;
}