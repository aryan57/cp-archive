/*
	group : Google Coding Competitions - Round H 2021 - Kick Start 2021
	name : Silly Substitutions.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Silly_Substitutions.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435914/00000000008d94f5
*/
/*
	author : aryan57
	created : 14-November-2021 08:57:40 IST
*/
#include <bits/stdc++.h>
using namespace std;


#define int long long
#define F(i, a, b) for (int i = a; i <= b; i++)

struct node
{
	int val = 0;
	bool active = false;
	node* left = nullptr;
	node* right = nullptr;
	bool use = false;
};


void solve_GOOGLE()
{
	int n;
	cin>>n;

	string s;
	cin>>s;

	vector <node*> v; 
	vector <vector <node*>> d(10);

	F(i,0,n-1)
	{
		node* t = new node;
		t->val = s[i]-'0';
		v.push_back(t);
	}

	F(i,0,n-1)
	{
		if(i)v[i]->left = v[i-1];
		if(i<n-1){
			v[i]->right = v[i+1];
			if(v[i+1]->val == (v[i]->val + 1)%10){
				v[i]->active = true;
			}
		}

		if(v[i]->active)d[v[i]->val].push_back(v[i]);
	}

	vector <bool> use(n);

	while (true)
	{
		bool ok = false;

		F(i,0,9)
		{
			for(node* t : d[i])
			{
				if(t->use)continue;
				if(t->right==nullptr)continue;
				if((t->val+1)%10 != t->right->val)continue;
				

				t->right->use = true;
				t->val = (t->val + 2)%10;

				node* left = t;
				node* right = t->right->right;

				ok=true;

				left->right = right;
				if(right!=nullptr)right->left = left;

				if(right!=nullptr && (left->val+1)%10 == right->val){
					left->active=true;
					d[left->val].push_back(left);
				}else if(left!=nullptr){
					left->active=false;
				}

				if(t->left!=nullptr && (t->left->val+1)%10 == t->val){
					t->left->active=true;
					d[t->left->val].push_back(t->left);
				}else if(t->left!=nullptr){
					t->left->active=false;
				}
			}

			d[i].clear();
		}
		
		if(!ok)break;
	}
	
	F(i,0,n-1){
		if(!v[i]->use)cout<<v[i]->val;
	}
	cout<<"\n";
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
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve_GOOGLE();
	}
	return 0;
}
//	parsed : 14-November-2021 08:57:36 IST