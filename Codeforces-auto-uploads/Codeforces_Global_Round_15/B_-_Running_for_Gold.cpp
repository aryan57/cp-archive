/**
 *    author:  Aryan Agarwal
 *    created: 26.07.2021 15:14:18 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int w[5]={};
    int c[n][5]={};
    int ind=0;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<5;j++){
            cin>>c[i][j];
            if(w[j]<c[i][j])cnt++;
        }

        if(cnt<3 || i==0)for(int j=0;j<5;j++){
            w[j]=c[i][j];
            ind=i;
        }
    }

    

    for(int i=0;i<n;i++){
        if(i==ind)continue;
        int cnt=0;
        for(int j=0;j<5;j++){
            if(c[ind][j]<c[i][j])cnt++;
        }
        if(cnt<3){
            cout<<"-1\n";
            return;
        }
    }

    cout<<ind+1<<"\n";
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