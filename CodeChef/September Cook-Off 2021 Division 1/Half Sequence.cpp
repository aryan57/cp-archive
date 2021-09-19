/*
	group : CodeChef - September Cook-Off 2021 Division 1
	name : Half Sequence.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Half_Sequence.cpp
	url : https://www.codechef.com/COOK133A/problems/HFSEQ
*/
/*
	author : aryan57
	created : 19-September-2021 23:07:07 IST
*/
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

int gcd(int a, int b) /*__gcd doesn't work for big no.s*/
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

// Function that finds the prime
// factors of a number
vector<int> findPrimeFactors(int n)
{
    // To store the prime factor
    vector<int> primeFactors(9, 0);
 
    int j = 0;
 
    // 2s that divide n
    if (n % 2 == 0) {
        primeFactors[j++] = 2;
        while (n % 2 == 0)
            n >>= 1;
    }
 
    // N must be odd at this point
    // Skip one element
    for (int i = 3;
         i * i <= n; i += 2) {
 
        if (n % i == 0) {
 
            // Update the prime factor
            primeFactors[j++] = i;
            while (n % i == 0)
                n /= i;
        }
    }
 
    // If n is a prime number
    // greater than 2
    if (n > 2)
        primeFactors[j++] = n;
     
    vector<int> PrimeFactors(j);
     
    for(int i = 0; i < j; i++)
    {
        PrimeFactors[i] = primeFactors[i];
    }
     
    return PrimeFactors;
}
 
// Function that finds the shortest
// subsequence
void findShortestSubsequence(vector<int> &dp, vector<int> a,
                        int index, vector<int> primeFactors)
{
    int n = a.size();
 
    for (int j = index; j < n; j++) {
        int bitmask = 0;
 
        for (int p = 0;
             p < primeFactors.size(); p++) {
 
            // Check if the prime factor
            // of first number, is also
            // the prime factor of the
            // rest numbers in array
            if ((a[j] % primeFactors[p]) == 0) {
 
                // Set corresponding bit
                // of prime factor to 1,
                // it means both these
                // numbers have the
                // same prime factor
                bitmask ^= (1 << p);
            }
        }
 
        for (int i = 0; i < dp.size(); i++) {
 
            // If no states encountered
            // so far continue for this
            // combination of bits
            if (dp[i] == n + 1)
                continue;
 
            // Update this state with
            // minimum ways to reach
            // this state
            dp[bitmask & i]
                = min(dp[bitmask & i],
                           dp[i] + 1);
        }
    }
}
 
// Function that print the minimum
// length of subsequence
int printMinimumLength(vector<int> &a)
{
    int Min = a.size() + 1;
 
    for (int i = 0; i < a.size() - 1; i++) {
 
        // Find the prime factors of
        // the first number
        vector<int> primeFactors
            = findPrimeFactors(a[i]);
 
        int n = primeFactors.size();
     
        // Initialize the array with
        // maximum steps, size of the
        // array + 1 for instance
        vector<int> dp(1 << n, a.size() + 1);
 
        // Express the prime factors
        // in bit representation
 
        // Total number of set bits is
        // equal to the total number
        // of prime factors
        int setBits = (1 << n) - 1;
 
        // Indicates there is one
        // way to reach the number
        // under consideration
        dp[setBits] = 1;
        findShortestSubsequence(dp, a, i + 1,
                                primeFactors);
 
        // State 0 corresponds
        // to gcd of 1
        Min = min(dp[0], Min);
    }
 
    // If not found such subsequence
    // then print "-1"
    if (Min == (a.size() + 1))
        return -1;
 
    // Else print the length
    else
        return Min;
}	

void solve_LOL()
{
	int n;
	cin>>n;

	vector <int> a(n+1);
	vector <int> t;
	F(i,1,n){
		cin>>a[i];
		if(a[i]%2==0)
		{
			t.push_back(a[i]/2);
		}
	}

	if(n==2)
	{
		if(a[1]==2 || a[2]==2){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}

		return;
	}

	int z=(n+1)/2;
	int tt=sz(t);

	if(z>tt){
		cout<<"NO\n";
		return;
	}

	int g=0;
	for(int x : t){
		g=gcd(g,x);
	}

	if(g!=1){
		cout<<"NO\n";
		return;
	}

	int mx=40;

	if(z>=mx){
		cout<<"YES\n";
		return;
	}

	
	if(printMinimumLength(t)<=z){
		cout<<"YES\n";
	}else cout<<"NO\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#ifndef ONLINE_JUDGE
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
#endif
#ifdef ARYAN_SIEVE
	sieve();
#endif
#ifdef ARYAN_SEG_SIEVE
	segmented_sieve();
#endif
#ifdef ARYAN_FACT
	fact_init();
#endif
	// cout<<fixed<<setprecision(10);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++)
	{
		// cout<<"Case #"<<i<<": ";
		solve_LOL();
	}
	return 0;
}