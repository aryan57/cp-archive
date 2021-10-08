/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/c.cpp
	url : /home/aryan/Desktop/cp-workspace/c.cpp
*/
/**
 *    author:  Aryan Agarwal
 *    created: 08.10.2021 16:54:16 IST
**/
#include <bits/stdc++.h>
using namespace std;


class EllysKeys{

	public:
	int getMax(vector <string> v)
	{
		int n=v.size();
		int ans=0;

		for(int i=0;i<n;i++)
		{
			vector<int> can;
			int m=v[i].size();

			for(int j=0;j<n;j++)
			{
				if(i==j)continue;

				bool bad=false;

				for(int k=0;k<m;k++)
				{
					if(v[i][k]=='^' && v[j][k]=='^'){
						bad=true;
						break;
					}
				}

				if(!bad)can.push_back(j);
			}

			if(can.size() > 11)continue;

			int pw=(1ll<<(int(can.size())));

			for(int num=0;num<pw;num++)
			{
				int cnt[m]={};
				bool bad=false;
				int tot=1;
				for(int bit=0;bit<can.size();bit++)
				{
					if((num>>bit)&1)
					{
						tot++;
						for(int j=0;j<m;j++)
						{
							if(v[can[bit]][j]=='^')cnt[j]++;
							if(cnt[j]>1){
								bad=true;
								break;
							}
						}
					}
					if(bad)break;
				}

				if(!bad)ans=max(ans,tot);
			}

		}

		return ans;
	}

};

void solve()
{
	EllysKeys obj;
	cout<<obj.getMax({"....................", "^^^^^^..^^^^..^^^^^.", "..^^...^^..^^.^^..^^", "..^^...^^..^^.^^^^^.", "..^^...^^..^^.^^....", "..^^....^^^^..^^....", "....................", ".^^^^...^^^^..^^^^..", "^^...^.^^..^^.^^..^^", "^^.....^^..^^.^^..^^", "^^...^.^^..^^.^^..^^", ".^^^^...^^^^..^^^^..", "....................", "...^^^^^^...^^^^^...", "...^^.......^^..^^..", "...^^^^^....^^^^^...", "...^^.......^^.^^...", "...^^^^^^...^^..^^..", "...................."});
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}