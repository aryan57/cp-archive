//https://codeforces.com/contest/1331/problem/D

/*
    author : Aryan Agarwal, 19CS30005, IIT KGP
*/

#include<bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7; /*more than (10)^9*/
int PEG = 998244353; /*less than (10)^9*/	/*1 + 7*17*(2)^23*/
const double pie=2*acos(0.0);

typedef long long int ll;
typedef unsigned long long ull;

#define watch(x) cout<<(#x)<<" is " << (x) <<"\n"
#define int ll
#define F(i,a,b) for (ll i=a;i<=b;i++)
#define RF(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) F(i,0,n-1)cin>>a[i]
#define in1(a,n) F(i,1,n)cin>>a[i]
#define out(a,n) F(i,0,n-1)cout<<a[i]<<" ";cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pfy cout<<"YES"
#define pfn cout<<"NO"
#define pfn1 cout<<"-1"  // printf negative 1
#define pf1 cout<<"1"
#define nl cout<<"\n"
#define gcd(a,b) __gcd((a),(b))

int binpow(int x,int y,int p)/* (x^y)%p in O(log y) */{int res=1;x=x%p;while (y > 0){if(y&1)res=(res*x)%p;y = y>>1;x=(x*x)%p;}return res;}
int mod_inverse(int n,int p)/* Returns n^(-1) mod p */{return binpow(n,p-2,p);}



// function to convert 
string HexToBin(string hexdec) 
{ 
	int i = 0;
    string ans="";

	while (hexdec[i]) { 

		switch (hexdec[i]) { 
		case '0': 
			 ans+="0000"; 
			break; 
		case '1': 
			ans+= "0001"; 
			break; 
		case '2': 
			ans+= "0010"; 
			break; 
		case '3': 
			ans+= "0011"; 
			break; 
		case '4': 
			ans+= "0100"; 
			break; 
		case '5': 
			ans+= "0101"; 
			break; 
		case '6': 
			ans+= "0110"; 
			break; 
		case '7': 
			ans+= "0111"; 
			break; 
		case '8': 
			ans+= "1000"; 
			break; 
		case '9': 
			ans+= "1001"; 
			break; 
		case 'A': 
		case 'a': 
			ans+= "1010"; 
			break; 
		case 'B': 
		case 'b': 
			ans+= "1011"; 
			break; 
		case 'C': 
		case 'c': 
			ans+= "1100"; 
			break; 
		case 'D': 
		case 'd': 
			ans+= "1101"; 
			break; 
		case 'E': 
		case 'e': 
			ans+= "1110"; 
			break; 
		case 'F': 
		case 'f': 
			ans+= "1111"; 
			break; 
		default: 
			cout << "\nInvalid hexadecimal digit "
				<< hexdec[i]; 
		} 
		i++; 
	}

    return ans;
} 



signed main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("11.txt", "r", stdin);
    // #endif
    fast;

    // Get the Hexadecimal number 
	// char hexdec[100] = ""; 

	string ans="",s;
    cin>>s;
    ans=HexToBin(s);

    if(ans[ans.size()-1]=='1')cout<<1;
    else cout<<0;

    // cout<<ans;
 
    
 
    return 0;
}