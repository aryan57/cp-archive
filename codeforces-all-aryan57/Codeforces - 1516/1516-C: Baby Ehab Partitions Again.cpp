//https://codeforces.com/contest/1516/problem/C

// A Dynamic Programming based
// C++ program to partition problem
#include <bits/stdc++.h>
using namespace std;

#define int long long


class PartitionSet {
public:
  bool canPartition(const vector<int> &num) {
    int sum = 0;
    for (int i = 0; i < num.size(); i++) {
      sum += num[i];
    }

    // if 'sum' is a an odd number, we can't have two subsets with equal sum
    if (sum % 2 != 0) {
      return false;
    }

    vector<vector<int>> dp(num.size(), vector<int>(sum / 2 + 1, -1));
    return this->canPartitionRecursive(dp, num, sum / 2, 0);
  }

private:
  bool canPartitionRecursive(vector<vector<int>> &dp, const vector<int> &num, int sum,
                             int currentIndex) {
    // base check
    if (sum == 0) {
      return true;
    }

    if (num.empty() || currentIndex >= num.size()) {
      return false;
    }

    // if we have not already processed a similar problem
    if (dp[currentIndex][sum] == -1) {
      // recursive call after choosing the number at the currentIndex
      // if the number at currentIndex exceeds the sum, we shouldn't process this
      if (num[currentIndex] <= sum) {
        if (canPartitionRecursive(dp, num, sum - num[currentIndex], currentIndex + 1)) {
          dp[currentIndex][sum] = 1;
          return true;
        }
      }

      // recursive call after excluding the number at the currentIndex
      dp[currentIndex][sum] = canPartitionRecursive(dp, num, sum, currentIndex + 1) ? 1 : 0;
    }

    return dp[currentIndex][sum] == 1 ? true : false;
  }
};

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	int n;
    cin>>n;

    vector <int> a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
	PartitionSet ps;
	// Function call
	if (!ps.canPartition(a))
    {
        cout<<0;
        return 0;
    }
    int mn=1e9;
    int mnind=-1;
    for(int i=0;i<n;i++)
    {
        int cnt=0;

        int num=a[i];

        while(num%2==0)
        {
            num/=2;
            cnt++;
        }
        if(mn>cnt)
        {
            mn=cnt;
            mnind=i+1;
        }
    }

    cout<<1;
    cout<<"\n";
    cout<<mnind;
    cout<<"\n";

	return 0;
}

// This code is contributed by rathbhupendra
