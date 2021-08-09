/*
	group : AtCoder - AtCoder Beginner Contest 213
	name : F - Common Prefixes.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/F_Common_Prefixes.cpp
	url : https://atcoder.jp/contests/abc213/tasks/abc213_f
*/
/**
 *    author:  Aryan Agarwal
 *    created: 09.08.2021 09:38:05 IST
**/
#include <bits/stdc++.h>
using namespace std;

// O(N*logN*logN)
// https://web.stanford.edu/class/cs97si/suffix-array.pdf
vector<int> suffix_array(const string &s){

	struct entry{
		int nr[2], p;
	};

	int N = s.size();
	if(N==1)return {0};

	vector<entry> L(N);
	vector<int> P(N);


	for (int i = 0; i < N; i++)
		P[i] = s[i] - 'a';

	for (int cnt = 1; cnt < N; cnt *= 2){
		for (int i = 0; i < N; i++){
			L[i].nr[0] = P[i];
			L[i].nr[1] = i + cnt < N ? P[i + cnt] : -1;
			L[i].p = i;
		}
		sort(L.begin(), L.end(),
			[](const entry &a, const entry &b) -> bool{
				return a.nr[0] != b.nr[0] ? (a.nr[0] < b.nr[0]) : (a.nr[1] < b.nr[1]);
			});
		for (int i = 0; i < N; i++){
			P[L[i].p] = 
			( i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] )
			? P[L[i - 1].p]
			: i;
		}
	}
	/*
		P[i] = position of ith suffix after sorting
		sa[i] = index of ith smallest suffix
	*/
	vector<int> sa(N);
	for(int i=0;i<N;i++)
		sa[P[i]]=i;

	return sa;
}

// O(N)
// https://cp-algorithms.com/string/suffix-array.html
vector<int> lcp_array(string const& s, vector<int> const& suffix_array) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[suffix_array[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = suffix_array[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
	// lcp[i] = length of the longest common prefix of the suffixes starting at suffix_array[i] and suffix_array[i+1]
    return lcp;
}

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;

	if(n==1){
		cout<<1;
		return;
	}

	vector<int> sa=suffix_array(s);
	vector<int> lcp=lcp_array(s,sa);

	vector<long long> ans(n);
	stack<pair<long long,long long>> ss;
	long long sum=0;

	for(int k=1;k<n;k++){

		long long cnt=1;
		while(!ss.empty() && (ss.top()).first>lcp[k-1]){
			sum-=(1ll*(ss.top()).first)*((ss.top()).second);
			cnt+=(ss.top()).second;
			ss.pop();
		}

		ss.push({lcp[k-1],cnt});
		sum+=(lcp[k-1]*cnt);

		ans[sa[k]]+=sum;
	}

	while(!ss.empty())ss.pop();
	sum=0;
	for(int k=n-2;k>=0;k--){

		long long cnt=1;
		while(!ss.empty() && (ss.top()).first>lcp[k]){
			sum-=(1ll*(ss.top()).first)*((ss.top()).second);
			cnt+=(ss.top()).second;
			ss.pop();
		}

		ss.push({lcp[k],cnt});
		sum+=(lcp[k]*cnt);
		ans[sa[k]]+=sum;
	}

	for(int i=0;i<n;i++){
		ans[i]+=n-i;
		cout<<ans[i]<<"\n";
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while (_t--)
		solve();
	return 0;
}
//	parsed : 09-August-2021 09:37:48 IST