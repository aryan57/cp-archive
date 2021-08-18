/*
	group : AtCoder - AtCoder Beginner Contest 211
	name : E - Red Polyomino.cpp
	srcPath : /home/aryan/cp-workspace/E_Red_Polyomino.cpp
	url : https://atcoder.jp/contests/abc211/tasks/abc211_e
*/
/**
 *    author:  Aryan Agarwal
 *    created: 27.07.2021 11:13:00 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<string> s;
int ans;
set<vector<string>> used;

vector<int> hx = {0,1,0,-1};
vector<int> hy = {1,0,-1,0};

bool is_inside(int x,int y,int n,int m){
    return x>=0 && x<n && y>=0 && y<m;
}
int n,k;

void dfs(int remain){
    if(used.find(s)!=used.end())return;
    used.insert(s);
    if(remain==0){
        ans++;
        return;
    }
    vector<pair<int,int>> next_points;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j]!='.')continue;
            bool possible = false;

            for(int k=0;k<4;k++){
                int r=i+hx[k];
                int c=j+hy[k];
                if(is_inside(r,c,n,n) && s[r][c]=='@'){
                    possible = true;
                    break;
                }
            }

            if(possible){
                next_points.push_back({i,j});
            }
        }
    }

    for(auto p : next_points) {
        s[p.first][p.second]='@';
        dfs(remain-1);
        s[p.first][p.second]='.';
    }
}

void solve()
{
    
    cin>>n>>k;
    s.resize(n);

    for(string &z : s){
        cin>>z;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j]=='.'){
                s[i][j]='@';
                dfs(k-1);
                s[i][j]='.';
            }
        }
    }

    cout<<ans;

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
//	parsed : 27-July-2021 11:12:55 IST