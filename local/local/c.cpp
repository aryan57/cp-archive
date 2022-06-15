/**
 *    author:  Aryan Agarwal
 *    created: 14.06.2022 19:27:44 IST
**/
#include <bits/stdc++.h>
using namespace std;


int dp(int i,int j,const string &A,const string &B,vector<vector<int>> &memo){
    int n=A.size();
    int m=B.size();
    if(i==n && j==m)return 1;
    if(j==m)return 0;
    
	assert(i<=n && j<=m);
    if(memo[i][j]!=-1)return memo[i][j];
    
    if(B[j]=='*'){
        int ans=0;
        
        ans|=dp(i,j+1,A,B,memo);
        if(i<n)ans|=dp(i+1,j,A,B,memo);
        
        memo[i][j]=ans;
        return ans;
    }
    
    if(i==n){
        return memo[i][j]=0;
    }
    
    if(B[j]=='?')return memo[i][j]=dp(i+1,j+1,A,B,memo);
    if(B[j]!=A[i])return memo[i][j]=0;
    return memo[i][j]=dp(i+1,j+1,A,B,memo);
}

int isMatch(const string A, const string B) {
    int n=A.size();
    int m=B.size();

	// cout<<n<<", "<<m;
    
    vector<vector<int>> memo(n+1,vector<int>(m+1,-1));
    
    return dp(0,0,A,B,memo);
}


void solve()
{
	string a,b;
	cin>>a>>b;
	cout<<isMatch(a,b);
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}