/*
	group : AtCoder - UNICORN Programming Contest 2021(AtCoder Beginner Contest 225)
	name : D - Play Train.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Play_Train.cpp
	url : https://atcoder.jp/contests/abc225/tasks/abc225_d
*/
/**
 *    author:  Aryan Agarwal
 *    created: 30.10.2021 18:06:35 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long

struct node
{
	node* left=nullptr;
	node* right=nullptr;
	int val=0;
};


void solve()
{
	int n,q;
	cin>>n>>q;
	vector <node*> v;
	for(int i=0;i<n;i++){
		node* t = new node;
		t->val=i+1;
		v.push_back(t);
	}

	while (q--)
	{
		int op;
		cin>>op;
		if(op==1){
			int x,y;
			cin>>x>>y;
			--x;
			--y;
			assert(v[x]->right==nullptr);
			assert(v[y]->left==nullptr);
			v[x]->right=v[y];
			v[y]->left=v[x];
		}else if(op==2){
			int x,y;
			cin>>x>>y;
			--x;
			--y;

			assert(v[x]->right!=nullptr);
			assert(v[y]->left!=nullptr);

			v[x]->right=nullptr;
			v[y]->left=nullptr;

		}else{
			int x;
			cin>>x;
			--x;

			vector <int> ans;

			node* t = v[x];

			while (t!=nullptr)
			{
				ans.push_back(t->val);
				t=t->left;
			}

			reverse(ans.begin(),ans.end());

			t=v[x]->right;

			while (t!=nullptr)
			{
				ans.push_back(t->val);
				t=t->right;
			}

			cout<<ans.size()<<" ";
			for(int x : ans)cout<<x<<" ";
			cout<<"\n";
			
		}
	}
	


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
//	parsed : 30-October-2021 17:36:35 IST