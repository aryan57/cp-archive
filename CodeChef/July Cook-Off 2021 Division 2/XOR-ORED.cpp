/*
	group : CodeChef - July Cook-Off 2021 Division 2
	name : XOR-ORED.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/XOR_ORED.cpp
	url : https://www.codechef.com/COOK131B/problems/XORORED
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.07.2021 23:00:02 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;
    int mxbit=32;
    int cnt[mxbit]={},a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];

        int num=a[i];
        int bit=0;
        while(num){
            if(num%2)cnt[bit]++;
            bit++;
            num/=2;
        }
    }

    int bxor=0;
    int x=0;
    int pw=1;
    for(int bit=0;bit<mxbit;bit++){
        if(cnt[bit]==0){
            
        }
        else if(cnt[bit]==n){
            x+=pw;
        }else{
            bxor+=pw;
        }

        pw*=2;
    }

    cout<<x<<" "<<bxor<<"\n";
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
//	parsed : 28-July-2021 22:59:58 IST