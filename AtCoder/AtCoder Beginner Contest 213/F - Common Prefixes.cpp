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
    
vector<int> sa_naive(const vector<int>& s) {
	int n = int(s.size());
	vector<int> sa(n);
	iota(sa.begin(), sa.end(), 0);
	sort(sa.begin(), sa.end(), [&](int l, int r) {
		if (l == r) return false;
		while (l < n && r < n) {
			if (s[l] != s[r]) return s[l] < s[r];
			l++;
			r++;
		}
		return l == n;
	});
	return sa;
}

vector<int> sa_doubling(const vector<int>& s) {
	int n = int(s.size());
	vector<int> sa(n), rnk = s, tmp(n);
	iota(sa.begin(), sa.end(), 0);
	for (int k = 1; k < n; k *= 2) {
		auto cmp = [&](int x, int y) {
			if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];
			int rx = x + k < n ? rnk[x + k] : -1;
			int ry = y + k < n ? rnk[y + k] : -1;
			return rx < ry;
		};
		sort(sa.begin(), sa.end(), cmp);
		tmp[sa[0]] = 0;
		for (int i = 1; i < n; i++) {
			tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
		}
		swap(tmp, rnk);
	}
	return sa;
}

template <int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>
vector<int> sa_is(const vector<int>& s, int upper) {
	int n = int(s.size());
	if (n == 0) return {};
	if (n == 1) return {0};
	if (n == 2) {
		if (s[0] < s[1]) {
			return {0, 1};
		} else {
			return {1, 0};
		}
	}
	if (n < THRESHOLD_NAIVE) {
		return sa_naive(s);
	}
	if (n < THRESHOLD_DOUBLING) {
		return sa_doubling(s);
	}

	vector<int> sa(n);
	vector<bool> ls(n);
	for (int i = n - 2; i >= 0; i--) {
		ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
	}
	vector<int> sum_l(upper + 1), sum_s(upper + 1);
	for (int i = 0; i < n; i++) {
		if (!ls[i]) {
			sum_s[s[i]]++;
		} else {
			sum_l[s[i] + 1]++;
		}
	}
	for (int i = 0; i <= upper; i++) {
		sum_s[i] += sum_l[i];
		if (i < upper) sum_l[i + 1] += sum_s[i];
	}

	auto induce = [&](const vector<int>& lms) {
		fill(sa.begin(), sa.end(), -1);
		vector<int> buf(upper + 1);
		copy(sum_s.begin(), sum_s.end(), buf.begin());
		for (auto d : lms) {
			if (d == n) continue;
			sa[buf[s[d]]++] = d;
		}
		copy(sum_l.begin(), sum_l.end(), buf.begin());
		sa[buf[s[n - 1]]++] = n - 1;
		for (int i = 0; i < n; i++) {
			int v = sa[i];
			if (v >= 1 && !ls[v - 1]) {
				sa[buf[s[v - 1]]++] = v - 1;
			}
		}
		copy(sum_l.begin(), sum_l.end(), buf.begin());
		for (int i = n - 1; i >= 0; i--) {
			int v = sa[i];
			if (v >= 1 && ls[v - 1]) {
				sa[--buf[s[v - 1] + 1]] = v - 1;
			}
		}
	};

	vector<int> lms_map(n + 1, -1);
	int m = 0;
	for (int i = 1; i < n; i++) {
		if (!ls[i - 1] && ls[i]) {
			lms_map[i] = m++;
		}
	}
	vector<int> lms;
	lms.reserve(m);
	for (int i = 1; i < n; i++) {
		if (!ls[i - 1] && ls[i]) {
			lms.push_back(i);
		}
	}

	induce(lms);

	if (m) {
		vector<int> sorted_lms;
		sorted_lms.reserve(m);
		for (int v : sa) {
			if (lms_map[v] != -1) sorted_lms.push_back(v);
		}
		vector<int> rec_s(m);
		int rec_upper = 0;
		rec_s[lms_map[sorted_lms[0]]] = 0;
		for (int i = 1; i < m; i++) {
			int l = sorted_lms[i - 1], r = sorted_lms[i];
			int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
			int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
			bool same = true;
			if (end_l - l != end_r - r) {
				same = false;
			} else {
				while (l < end_l) {
					if (s[l] != s[r]) {
						break;
					}
					l++;
					r++;
				}
				if (l == n || s[l] != s[r]) same = false;
			}
			if (!same) rec_upper++;
			rec_s[lms_map[sorted_lms[i]]] = rec_upper;
		}

		auto rec_sa =
			sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s, rec_upper);

		for (int i = 0; i < m; i++) {
			sorted_lms[i] = lms[rec_sa[i]];
		}
		induce(sorted_lms);
	}
	return sa;
}


vector<int> suffix_array(const vector<int>& s, int upper) {
	assert(0 <= upper);
	for (int d : s) {
		assert(0 <= d && d <= upper);
	}
	auto sa = sa_is(s, upper);
	return sa;
}

template <class T> vector<int> suffix_array(const vector<T>& s) {
	int n = int(s.size());
	vector<int> idx(n);
	iota(idx.begin(), idx.end(), 0);
	sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
	vector<int> s2(n);
	int now = 0;
	for (int i = 0; i < n; i++) {
		if (i && s[idx[i - 1]] != s[idx[i]]) now++;
		s2[idx[i]] = now;
	}
	return sa_is(s2, now);
}

vector<int> suffix_array(const string& s) {
	int n = int(s.size());
	vector<int> s2(n);
	for (int i = 0; i < n; i++) {
		s2[i] = s[i];
	}
	return sa_is(s2, 255);
}

/*
	(1) vector<int> suffix_array(string s)
	(2) vector<int> suffix_array<T>(vector<T> s)
	(3) vector<int> suffix_array(vector<int> s, int upper)

	Given a string s of length n, it returns the suffix array of s.
	Here, the suffix array sa of s is a permutation of 0,1,2,...,n-1
	such that s[sa[i]..n) < s[sa[i+1]..n) holds for all i = 0,1,2,...,n-2

	Constraints
		0 <= n <= 10^8
		T is int, uint, ll, or ull
		0 <= upper <= 10^8 
		0 <= x <= upper for all elements x of s

	Complexity
		(1) O(n)-time
		(2) O(n*logn)-time, O(n)-space
		(3) O(n + upper)-time
*/

template <class T>
vector<int> lcp_array(const vector<T>& s,
						   const vector<int>& sa) {
	int n = int(s.size());
	assert(n >= 1);
	vector<int> rnk(n);
	for (int i = 0; i < n; i++) {
		rnk[sa[i]] = i;
	}
	vector<int> lcp(n - 1);
	int h = 0;
	for (int i = 0; i < n; i++) {
		if (h > 0) h--;
		if (rnk[i] == 0) continue;
		int j = sa[rnk[i] - 1];
		for (; j + h < n && i + h < n; h++) {
			if (s[j + h] != s[i + h]) break;
		}
		lcp[rnk[i] - 1] = h;
	}
	return lcp;
}

vector<int> lcp_array(const string& s, const vector<int>& sa) {
	int n = int(s.size());
	vector<int> s2(n);
	for (int i = 0; i < n; i++) {
		s2[i] = s[i];
	}
	return lcp_array(s2, sa);
}

/*
	(1) vector<int> lcp_array(string s, vector<int> sa)
	(2) vector<int> lcp_array<T>(vector<T> s, vector<int> sa)

	Given a string s of length n, it returns the LCP array of s.
	Here, the LCP array of s is the array of length n-1,
	such that the i-th element is the length of the LCP (Longest Common Prefix) of s[sa[i]..n) and s[sa[i+1]..n).

	Constraints
		sa is the suffix array of s.
		1 <= n <= 10^8
		T is int, uint, ll, or ull.
	
	Complexity
		O(n)
*/

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