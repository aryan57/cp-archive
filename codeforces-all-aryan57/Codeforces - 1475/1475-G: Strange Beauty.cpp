//https://codeforces.com/contest/1475/problem/G

// copy pasted editorial solution
#include <bits/stdc++.h>
using namespace std;

const int N = (int) 2e5 + 100;

int dp[N];
int cnt[N];

void solve() {
  int n;
  cin >> n;
  fill(dp, dp + N, 0);
  fill(cnt, cnt + N, 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  for (int i = 1; i < N; i++) {
    dp[i] += cnt[i];
    for (int j = 2 * i; j < N; j += i) {
      dp[j] = max(dp[j], dp[i]);
    }
  }
  cout << (n - *max_element(dp, dp + N)) << endl;
}

int main() {
  int test;
  cin >> test;
  while (test-- > 0) {
    solve();
  }
  return 0;
}