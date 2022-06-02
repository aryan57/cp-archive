/**
 *    author:  Aryan Agarwal
 *    created: 02.11.2021 20:11:06 IST
 **/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int f(int l, int r)
{
	if (l > r)
		return 0;
	int ans = ((r - l) / 2 + 1) * (l + r) / 2;
	return ans;
}

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

void solve()
{
	int x, n;
	cin >> x >> n;

	if (n <= 100)
	{
		for (int i = 1; i <= n; i++)
		{
			if (x % 2)
				x += i;
			else
				x -= i;
		}

		cout << x << "\n";
		return;
	}

	int k = (n - 1) / 4;

	int ans = 0;

	ans += k * (-4);

	if ((n - 1) % 4 == 1)
	{
		ans += n;
	}
	if ((n - 1) % 4 == 2)
	{
		ans += n;
		ans += n - 1;
	}
	if ((n - 1) % 4 == 3)
	{
		ans -= n;
		ans += n - 1;
		ans += n - 2;
	}

	ans--;

	if (x % 2)
	{
		ans = 0;
		ans += k * (4);

		if ((n - 1) % 4 == 1)
		{
			ans -= n;
		}
		if ((n - 1) % 4 == 2)
		{
			ans -= n;
			ans -= n - 1;
		}
		if ((n - 1) % 4 == 3)
		{
			ans += n;
			ans -= n - 1;
			ans -= n - 2;
		}

		ans++;
	}

	ans += x;

	cout << ans << "\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin >> _t;
	while (_t--)
		solve();
	return 0;
}
//	parsed : 02-November-2021 20:07:36 IST