/*
	group : local
	name : c2.cpp
	srcPath : /home/aryan/cp-workspace/c2.cpp
	url : /home/aryan/cp-workspace/c2.cpp
*/
/**
 *    author:  Aryan Agarwal
 *    created: 20.03.2022 10:47:33 IST
 **/
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool check5(string s)
{
	int n = s.size();
	for (int i = 2; i <= n - 3; i++)
	{

		if (s[i + 2] != s[i - 2])
			continue;
		if (s[i + 1] != s[i - 1])
			continue;
		return false;
	}
	return true;
}
bool check6(string s)
{
	int n = s.size();
	for (int i = 2; i <= n - 4; i++)
	{

		if (s[i] != s[i + 1])
			continue;
		if (s[i - 1] != s[i + 2])
			continue;
		if (s[i - 2] != s[i + 3])
			continue;
		return false;
	}
	return true;
}

void solve()
{
	int n;
	cin >> n;

	string s;
	cin >> s;
	for (int num = 0; num < (1 << 15); num++)
	{

		bool ok = true;
		string t = s;

		for (int bit = 0; bit < n; bit++)
		{
			if (s[bit] != '?' && s[bit] - '0' != ((num >> bit) & 1))
			{
				ok = false;
				break;
			}
			t[bit] = '0';
			if ((num >> bit) & 1)
				t[bit] = '1';
		}
		if (ok && check5(t) && check6(t))
		{
			cout << "POSSIBLE\n";
			return;
		}
	}
	cout << "IMPOSSIBLE\n";
	return;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin >> _t;
	for (int i = 1; i <= _t; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}