//https://codeforces.com/contest/1326/problem/D2


/*
    author : aryan57
*/
#include<bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
int PEG = 998244353;
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

int longestPrefixSuffix(string s) 
{ 
    int n = s.length(); 
  
    int lps[n]; 
    lps[0] = 0; // lps[0] is always 0 
  
    // length of the previous 
    // longest prefix suffix 
    int len = 0; 
  
    // the loop calculates lps[i] 
    // for i = 1 to n-1 
    int i = 1; 
    while (i < n) 
    { 
        if (s[i] == s[len]) 
        { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider 
            // the example. AAACAAAA 
            // and i = 7. The idea is 
            // similar to search step. 
            if (len != 0) 
            { 
                len = lps[len-1]; 
  
                // Also, note that we do 
                // not increment i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
  
    int res = lps[n-1]; 
  
    // Since we are looking for 
    // non overlapping parts. 
    int ans= (res > n/2)? n/2 : res; 
    return ans-1;
}

 
void solve()
{
    string s,w;
    cin>>s;
    
    int k=-1,n=s.size();

    for(int i=0;i<n/2;i++)if(s[i]!=s[n-1-i]){k=i-1;break;}
    

    string a=s.substr(k+1,n-2-2*k);
    string ra=a;
    reverse(ra.begin(),ra.end());

    int p1=longestPrefixSuffix(a+'#'+ ra);
    int p2=longestPrefixSuffix(ra+'#'+ a);

    w = p1>=p2?a.substr(0,p1+1):ra.substr(0,p2+1);
    // cout<<w<<"+"<<k;nl;



    string ans=s.substr(0,k+1)+w+s.substr(n-1-k,k+1);
    // cout<<s.substr(0,k+1)<<"+"<<w<<"+"<<s.substr(n-1-k,k+1)<<"\n";
    cout<<ans<<"\n";

}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("11.txt", "r", stdin);
    #endif
    fast;

    int _t;
    cin>>_t;
    while(_t--)
    {
        solve();
    }

    return 0;
}