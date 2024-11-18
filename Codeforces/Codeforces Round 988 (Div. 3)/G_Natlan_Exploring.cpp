/**
 *    author:  Aryan Agarwal
 *    created: 17.11.2024 21:21:10 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxn = 1e6;
const int M = 998244353;

int spf[mxn+1];

void sieve(){

	for(int i=1;i<=mxn;i++){
		spf[i]=i;
	}

	for(int i=2;i*i<=mxn/*no need to check for spf of number's more then root mxn*/;i++){
		if(spf[i]!=i)continue; // if this is not prime continue
		for(int j=i*i;j<=mxn;j+=i){
			if(spf[j]==j)spf[j]=i;
		}
	}
}

vector<int> getUniquePrimeFactors(int x){
	set<int> s;

	while (x>1){
		int factor = spf[x];
		s.insert(factor);
		x/=factor;
	}

	return vector<int> (s.begin(),s.end());
}

void solve()
{

	sieve();
	int n;
	cin>>n;
	vector <int> dp(mxn+1); // At a current index i, dp[x] is the sum of all ways to
	                    // reach any index till (i-1) such that the element at that
						// index has a factor of 'x'

	int a, sum;

	for(int i=0;i<n;i++){
		cin>>a;

		const vector<int> factors = getUniquePrimeFactors(a);
		int m = factors.size();
		sum = (i?0:1);

		// Do inclusion-exclusion, principle using masks
		// Ex. = No of ways to reach 6, is (2) + (3) - (6)
		// i.e., |A U B| = |A| + |B| - |A intersect B|
		// This can be generalised with sets of any size like,
		// |A U B U C U D|, where we add the value of odd size intersections
		// like |A intersect C intersect D|, but subtract the even sized ones
		// like |A intersect C|
		if(i!=0) 
		for(int num = 1;num<(1ll<<m);num++){
			int product = 1;
			int totBits = 0;

			for(int bit=0;bit<m;bit++){
				if((num>>bit)&1){
					product*=factors[bit];
					totBits++;
				}
			}
			if(totBits&1){
				sum += dp[product];
				sum %= M;
			}
			else{
				sum -= dp[product];
				sum %= M;
				sum += M;
				sum %= M;
			}
		}

		// now sum is the no of ways to reach element at current index
		// update the dp of factors of this element, with this sum, for future indexes
		for(int num = 0;num<(1ll<<m);num++){
			int product = 1;

			for(int bit=0;bit<m;bit++){
				if((num>>bit)&1){
					product*=factors[bit];
				}
			}
			dp[product]+=sum;
			dp[product]%=M;
		}

	}

	cout<<sum;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		solve();
	}
	return 0;
}