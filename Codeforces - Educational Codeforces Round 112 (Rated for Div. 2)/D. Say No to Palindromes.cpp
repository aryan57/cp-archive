/*
	group : Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
	name : D. Say No to Palindromes.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Say_No_to_Palindromes.cpp
	url : https://codeforces.com/contest/1555/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 30.07.2021 20:54:28 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,q;
    cin>>n>>q;

    string s;
    cin>>s;

    s='#'+s;

    vector<string> z;

    string p="abc";

    do{

        string t="#";
        while(t.size()<n+3){
            t+=p;
        }

        z.push_back(t);
        // cout<<t<<"^\n";

    }while(next_permutation(p.begin(),p.end()));

    vector<vector<int>> pre(6,vector<int>(n+1));

    for(int i=0;i<6;i++){
        for(int j=1;j<=n;j++){
            pre[i][j]=pre[i][j-1]+(z[i][j]!=s[j]?1:0);
        }
    }

    while(q--){
        int l,r;
        cin>>l>>r;

        int ans=1e18;

        for(int i=0;i<6;i++){
            ans=min(ans,pre[i][r]-pre[i][l-1]);
        }

        cout<<ans<<"\n";
    }

    
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
//	parsed : 30-July-2021 20:54:25 IST