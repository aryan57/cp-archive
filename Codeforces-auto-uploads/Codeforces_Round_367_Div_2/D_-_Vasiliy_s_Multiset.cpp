/**
 *    author:  Aryan Agarwal
 *    created: 30.04.2022 17:08:03 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long


class TrieNode{
public:
	static const int child_size=2; // use 26 for alphabets
	TrieNode* next[child_size];
	
	int cnt; // add any other data each node requires to hold
	TrieNode(){
		cnt=0;
		for(int i=0;i<child_size;i++){
			next[i]=nullptr;
		}
	}
};

class Trie{
public:
	
	TrieNode* head;
	static const int mxbit=29;

	Trie(){
		head=new TrieNode();
	}

	void insert(int num){
		TrieNode* temp = head;
		for(int bit=mxbit;bit>=0;bit--){
			int isset = (num>>bit)&1;
			if(temp->next[isset]==nullptr)temp->next[isset]=new TrieNode();
			temp->next[isset]->cnt++;
			temp=temp->next[isset];
		}
	}
	void remove(int num){
		TrieNode* temp = head;
		for(int bit=mxbit;bit>=0;bit--){
			int isset = (num>>bit)&1;
			assert(temp->next[isset]!=nullptr);
			temp->next[isset]->cnt--;
			temp=temp->next[isset];
		}
	}

	int query(int num){
		int ans=0;

		TrieNode* temp = head;
		for(int bit=mxbit;bit>=0;bit--){
			int isset = (num>>bit)&1;
			if(temp->next[1^isset]!=nullptr && temp->next[1^isset]->cnt>0){
				ans+=(1UL<<bit);
				temp=temp->next[1^isset];
			}else{
				assert(temp->next[isset]!=nullptr && temp->next[isset]->cnt>0);
				temp=temp->next[isset];
			}
		}


		return ans;
	}


};

void solve()
{
	Trie trie;
	trie.insert(0);
	int q;
	cin>>q;
	while (q--)
	{
		char op;
		cin>>op;
		int x;
		cin>>x;
		if(op=='+')trie.insert(x);
		if(op=='-')trie.remove(x);
		if(op=='?')cout<<trie.query(x)<<"\n";
	}
	
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}