/*
	group : Google Coding Competitions - Round E 2021 - Kick Start 2021
	name : Shuffled Anagrams.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Shuffled_Anagrams.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/000000000043585c/000000000085a152
*/
/*
	author : aryan57
	created : 22-August-2021 09:54:44 IST
*/
#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
	os << '{';
	string sep;
	for (const T &x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
	cerr << ' ' << H;
	dbg_out(T...);
}
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

void solve_GOOGLE()
{
	string s;
	cin >> s;
	string s2 = s;
	vector<vector<int>> pos(26);
	vector<int> idx(26);
	int n = sz(s);
	int cnt[26] = {};
	F(i, 0, n - 1)
	{
		pos[s[i] - 'a'].push_back(i);
		cnt[s[i] - 'a']++;
		if (cnt[s[i] - 'a'] > (n) / 2)
		{
			cout << "IMPOSSIBLE\n";
			return;
		}
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>> q;

	F(i, 0, 25)
	{
		if (cnt[i] > 0)
		{
			q.push({cnt[i], i});
		}
	}

	while (sz(q) >= 2)
	{
		pair<int, int> p1 = q.top();
		q.pop();
		pair<int, int> p2 = q.top();
		q.pop();

		int id1 = pos[p1.Y][idx[p1.Y]++];
		int id2 = pos[p2.Y][idx[p2.Y]++];

		swap(s[id1], s[id2]);

		p1.X--;
		p2.X--;

		if (p1.X > 0)
		{
			q.push(p1);
		}
		if (p2.X > 0)
		{
			q.push(p2);
		}
	}

	F(i, 0, n - 1)
	{
		if (s[i] == s2[i])
		{
			int p = -1;
			F(j, 0, n - 1)
			{
				if (s2[j] != s2[i] && s[j] != s2[i])
				{
					p = j;
					break;
				}
			}

			if (p == -1)
			{
				cout << "IMPOSSIBLE\n";
				return;
			}

			swap(s[p], s[i]);
		}
	}
	F(i, 0, n - 1)
	{
		if (s[i] == s2[i])
		{
			cout << "IMPOSSIBLE\n";
			return;
		}
	}

	cout << s << "\n";
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
	int _t = 1;
	cin >> _t;
	for (int i = 1; i <= _t; i++)
	{
		cout << "Case #" << i << ": ";
		solve_GOOGLE();
	}
	return 0;
}