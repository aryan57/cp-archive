/*
	group : CodeChef - July Lunchtime 2021 Division 2
	name : Array Rotation Returns.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Array_Rotation_Returns.cpp
	url : https://www.codechef.com/LTIME98B/problems/ARRT
*/
/**
 *    author:  Aryan Agarwal
 *    created: 31.07.2021 18:08:15 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool les(vector<int> &a,vector<int> &b){

    int n=a.size();
    for(int i=0;i<n;i++){
        if(a[i]!=b[i])return a[i]<b[i];
    }

    return true;
}

void solve()
{
    int n;
    cin>>n;

    vector<int> a(n),b(n);

    for(int &x : a)cin>>x;
    for(int &x : b)cin>>x;

    
    int inf=1e18;
    int mn=inf;

    for(int i=0;i<n;i++){
        if(mn>(a[0]+b[i])%n){
            mn=(a[0]+b[i])%n;
        }
    }

    assert(mn!=inf);
    vector<int> pos;

    for(int i=0;i<n;i++){
        if(mn==(a[0]+b[i])%n){
            pos.push_back(i);
        }
    }

    assert(pos.size()<=2);

    vector<vector<int>> c(2,vector<int>(n));

    for(int i=0;i<pos.size();i++){
        
        for(int j=0;j<n;j++){
            c[i][j] = (a[j] + b[(j+pos[i])%n])%n;
        }
    }
    int id=1;
    if(pos.size()==1 || les(c[0],c[1])){
        id=0;
    }

    for(int x : c[id]){
        cout<<x<<" ";
    }cout<<"\n";

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
//	parsed : 31-July-2021 18:03:02 IST