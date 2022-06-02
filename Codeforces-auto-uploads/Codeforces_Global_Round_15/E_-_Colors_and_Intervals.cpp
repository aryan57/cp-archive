/**
 *    author:  Aryan Agarwal
 *    created: 26.07.2021 14:55:53 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long

int pos[101][101]={};
int ind=0;
bool comp(int i,int j)
{
    return pos[i][ind] < pos[j][ind];
}

void solve()
{
    int n,k;
    cin>>n>>k;

    int cnt[101] = {};

    int c[n*k+1]={};

    for(int i=1;i<=n*k;i++) {
        cin>>c[i];
        cnt[c[i]]++;
        pos[c[i]][cnt[c[i]]]=i;
    }

    int rem=n;
    vector<pair<int,int>> ans(n);

    vector<int> colors(n);
    iota(colors.begin(),colors.end(),1);
    vector<bool> used(n+1);
    int iter=0;
    while(rem>0)
    {
        ind=iter+2;
        sort(colors.begin(),colors.end(),comp);

        int limit = (n+k-2)/(k-1);

        for(int x : colors)
        {
            if(limit==0 || rem==0)break;
            if(used[x])continue;
            limit--;
            rem--;

            ans[x-1] = {pos[x][iter+1],pos[x][iter+2]};
            used[x]=true;
        }
        iter++;
    }

    for(auto p : ans)cout<<p.first<<" "<<p.second<<"\n";

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    // cin>>_t;
    while(_t--)solve();
    return 0;
}