/*
	group : CodeChef - July Cook-Off 2021 Division 1
	name : Hidden Colored Graph.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Hidden_Colored_Graph.cpp
	url : https://www.codechef.com/COOK131A/problems/COLRGRPH
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.07.2021 13:34:07 IST
**/
#include <bits/stdc++.h>
using namespace std;


void solve()
{
    int n;
    cin>>n;
    if(n==1){
        cout<<"!"<<endl<<0<<endl;
        return;
    }

    int g[n+1][n+1]={};
    int sum[n+1]={};
    int col[n+2][n+1]={};

    char x;

    for(int r=2;r<=n+1;r++){
        for(int i=1;i<=min(r,n);i++){
            cout<<"? "<<i<<endl;
            cin>>x;
            if(x=='B')col[r][i]=1;
        }
    }

    for(int r=2;r<=n;r++){
        for(int i=1;i<=r-1;i++){
            int after=col[r+1][i];
            int before=col[r][i];

            if(sum[i]%2!=(abs(after-before))%2){
                sum[i]++;
                sum[r]++;
                g[i][r]=g[r][i]=1;
            }
        }
    }

    cout<<"!"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<g[i][j];
        }
        cout<<endl;
    }


}

signed main()
{
    int _t = 1;
    // cin>>_t;
    while(_t--)solve();
    return 0;
}
//	parsed : 29-July-2021 11:01:47 IST