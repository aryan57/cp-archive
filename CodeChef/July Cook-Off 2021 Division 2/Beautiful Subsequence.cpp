/*
	group : CodeChef - July Cook-Off 2021 Division 2
	name : Beautiful Subsequence.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Beautiful_Subsequence.cpp
	url : https://www.codechef.com/COOK131B/problems/BEAUSUB
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.07.2021 10:43:07 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long
const int mxn=1000 + 5;

int f[mxn][mxn];
int pre[mxn][mxn];
int a[mxn];
int last[mxn];
int n,k;

void solve()
{
    cin>>n>>k;
    
    vector<int> lastpos(1001);

    for(int i=0;i<=n;i++){
        if(i){
            cin>>a[i];
            last[i]=lastpos[a[i]];
            lastpos[a[i]]=i;
        }
        for(int j=0;j<=k;j++){
            f[i][j]=0;
            pre[i][j]=0;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(j>0){
                f[i][j] = max(f[i][j], 1 + pre[i-1][j-1]);
            }
            f[i][j] = max(f[i][j], 1 + f[last[i]][j]);

            pre[i][j] = max(pre[i][j],pre[i-1][j]);
            pre[i][j] = max(pre[i][j],f[i][j]);
            ans=max(ans,pre[i][j]);
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