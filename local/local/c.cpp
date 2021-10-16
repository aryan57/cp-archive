/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/c.cpp
	url : /home/aryan/Desktop/cp-workspace/c.cpp
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 64;

bool dp[MAX_N][MAX_N][MAX_N][MAX_N]; // (taken, red, mod A, mod B) -> may be
pair<bool, int> sert[MAX_N][MAX_N][MAX_N][MAX_N]; // the same -> (true (red) | false(black), prev red/black)

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, a, b;
		string x;
		cin >> n >> a >> b >> x;

		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				for (int k = 0; k < a; k++)
					for (int l = 0; l < b; l++)
						dp[i][j][k][l] = false;

		dp[0][0][0][0] = true;

		for(int taken = 0; taken < n; taken++)
			for(int red = 0; red <= taken; red++)
				for(int remA = 0; remA < a; remA++)
					for(int remB = 0; remB < b; remB++)
						if (dp[taken][red][remA][remB])
						{
							// dbg(taken,red,remA,remB);

						

							// red transition
							dp[taken + 1][red + 1][(remA * 10 + (x[taken] - '0')) % a][remB] = true;
							sert[taken + 1][red + 1][(remA * 10 + (x[taken] - '0')) % a][remB] = { true, remA };

							// black transition
							dp[taken + 1][red][remA][(remB * 10 + (x[taken] - '0')) % b] = true;
							sert[taken + 1][red][remA][(remB * 10 + (x[taken] - '0')) % b] = { false, remB };

							if(taken==4 && red==2 && remA==0 && (remB==6)){
								dbg(taken,red,remA,remB);
								dbg((remB*10 + (x[taken]-'0'))%b);
								dbg(sert[5][2][0][0]);
								dbg(sert[taken+1][red][remA][(remB*10 + (x[taken]-'0'))%b]);

							}
						}

		// dbg(n,a,b,x);

		int bestRed = 0;

		for (int red = 1; red < n; red++)
			if (dp[n][red][0][0] && abs(red - (n - red)) < abs(bestRed - (n - bestRed)))
				bestRed = red;

		if (bestRed == 0)
		{
			cout << "-1\n";
		}
		else
		{
			int taken = n;
			int red = bestRed;
			int remA = 0;
			int remB = 0;
			string ans = "";
			
			while (taken > 0)
			{
				// dbg(taken,red,remA,remB);
				assert(dp[taken][red][remA][remB]);
				auto way = sert[taken][red][remA][remB];
				// dbg(way);

				if (way.first)
				{
					red--;
					remA = way.second;
					ans.push_back('R');
				}
				else
				{
					remB = way.second;
					ans.push_back('B');
				}
				taken--;
			}

			reverse(ans.begin(), ans.end());
			cout << ans << '\n';
		}
	}

	return 0;
}