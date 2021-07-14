//https://codeforces.com/contest/1324/problem/C

/*
    author : aryan57
*/
#include<bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
typedef long long int ll;
typedef unsigned long long ull;
 
#define int ll
#define F(i,a,b) for (ll i=a;i<=b;i++)
#define RF(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) F(i,0,n-1)cin>>a[i]
#define in1(a,n) F(i,1,n)cin>>a[i]
#define out(a,n) F(i,0,n-1)cout<<"a[i]\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pfy cout<<"YES"
#define pfn cout<<"NO"
#define pfn1 cout<<"-1"  // printf negative 1
#define pf1 cout<<"1"
#define nl cout<<"\n"
 
void solve()
{
    string s;
    cin>>s;
    int n=s.length();
    int count=0,flag=0,coum=0;

    F(i,0,n-2){
        if(s[i]=='L'){flag=1;}


        if(s[i]==s[i+1] && s[i]=='L')count++;

        else {if(coum<count){coum=count;}count=0; }   
    }

    if(coum<count)coum=count;count=0;

    if(s[n-1]=='L' && coum==0)cout<<"2\n";


    else if(n==1){
        if(s[0]=='L')cout<<"2\n";
        else cout<<"1\n";
    }

    else{
        if(flag){cout<<coum+2;nl;}
        else cout<<"1\n";
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    int tt = clock();
    #endif
    fast;

    int _t;
    cin>>_t;
    while(_t--)
    {
        solve();

 
        #ifndef ONLINE_JUDGE
        cerr << "--- TIME = " << clock() - tt <<" ms ---\n";
        tt = clock();
        #endif
    }

    return 0;
}