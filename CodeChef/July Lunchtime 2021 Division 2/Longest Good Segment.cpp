/*
	group : CodeChef - July Lunchtime 2021 Division 2
	name : Longest Good Segment.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Longest_Good_Segment.cpp
	url : https://www.codechef.com/LTIME98B/problems/LGSEG
*/
/**
 *    author:  Aryan Agarwal
 *    created: 31.07.2021 21:21:03 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,k,s;
    cin>>n>>k>>s;

    vector<int> a(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    a[n]=s+1;

    int mxbit=20;
    vector<vector<int>> child(n+1,vector<int>(mxbit,n));

    int i=0;int j=0;
    int sum=a[0];
    
    for(int i=0;i<n;i++){
        
        while(true){
            
            if(sum>s){
                child[i][0]=j;
                break;
            }
            j++;
            sum+=a[j];
        }
        sum-=a[i];
    }

    for(int bit=1;bit<mxbit;bit++){
        for(int i=0;i<n;i++){
            if(child[i][bit-1]>=0 && child[i][bit-1]<=n){
                child[i][bit]=child[child[i][bit-1]][bit-1];
            }
        }
    }

    int ans=0;
    for(int i=0;i<n;i++){
        /*
            we want to travel next
            'k' nodes from node 'i'
        */
       int cur=i;
       for(int bit=mxbit-1;bit>=0 && cur<n;bit--){
           if((k>>bit)&1)cur=child[cur][bit];
       }

       ans=max(ans,cur-i);
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
//	parsed : 31-July-2021 21:20:55 IST