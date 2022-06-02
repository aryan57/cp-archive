/**
 *    author:  Aryan Agarwal
 *    created: 30.04.2022 15:54:17 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long


class TrieNode{
public:
	static const int child_size=26; // use 26 for alphabets
	
	TrieNode* next[child_size];
	
	bool win,lose;

	TrieNode(){
		win=lose=false;
		for(int i=0;i<child_size;i++){
			next[i]=nullptr;
		}
	}
};

class Trie{
public:
	
	TrieNode* head;

	Trie(){
		head=new TrieNode();
	}

	void insert(string s){
		TrieNode* temp = head;
		for(char c :s){
			if(temp->next[c-'a']==nullptr){
				temp->next[c-'a'] = new TrieNode();
			}
			temp=temp->next[c-'a'];
		}
	}

	void dfs(TrieNode* temp){
		if(temp==nullptr)return;
		bool isleaf=true;
		for(auto node : temp->next){
			if(node!=nullptr){
				isleaf=false;
				dfs(node);
				temp->win|=(!(node->win));
				temp->lose|=(!(node->lose));
			}
		}
		if(isleaf){
			temp->lose=true;
			temp->win=false;
		}
	}

	void query(){
		dfs(head);
	}


};

void solve()
{
	int n,k;
	cin>>n>>k;
	Trie trie;
	while (n--)
	{
		string s;
		cin>>s;
		trie.insert(s);
	}

	trie.query();

	// cout<<trie.head->win<<" "<<trie.head->lose<<"\n";

	if(!(trie.head->win)){
		cout<<"Second\n";
		return;
	}
	if(trie.head->win && trie.head->lose){
		cout<<"First\n";
		return;
	}


	if(k%2)cout<<"First";
	else cout<<"Second";
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