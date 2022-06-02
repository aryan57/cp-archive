#include<bits/stdc++.h>
using namespace std;

#define int long long

class TrieNode{
public:
	static const int child_size=2; // use 26 for alphabets
	/**
	 * this implmentation required
	 * size and the index of the node
	*/
	int sz,index;
	TrieNode* next[child_size];
	TrieNode* parent;
	TrieNode(){
		sz=0;
		index=-1;
		for(int i=0;i<child_size;i++){
			next[i]=nullptr;
		}
		parent=nullptr;
	}
	~TrieNode(){
		for(int i=0;i<child_size;i++){
			delete next[i];
		}
		// delete this;
	}
};

class Trie{
public:
	
	static const int mxbit = 30;
	TrieNode* head;
	int maxdp;
	int maxdpid;

	Trie(){
		head=new TrieNode();
		maxdp=0;
		maxdpid=-1;
	}

	void insert(int num,int ind){
		TrieNode* temp = head;
		for(int bit=mxbit-1;bit>=0;bit--){
			int isset = (num>>bit)&1;
			if(temp->next[isset]==nullptr){
				temp->next[isset] = new TrieNode();
				temp->next[isset]->index = ind;
				temp->next[isset]->parent = temp;
			}
			temp=temp->next[isset];
		}
	}

	int query(int num,int ind,int k){
		TrieNode* r1 = head;
		TrieNode* r2 = head;

		int mx=0;
		int pre=-1;

		for(int bit=mxbit-1;bit>=0;bit--){
			int bitnum = (num>>bit)&1;
			int bitk = (k>>bit)&1;

			if(bitk==1){
				if(r2->next[!bitnum]==nullptr)break;
				r2=r2->next[!bitnum];
				r1=r1->next[bitnum];
				continue;
			}

			if(r2->next[!bitnum]!=nullptr && mx < 1 + r2->next[!bitnum]->sz){
				mx= 1 + r2->next[!bitnum]->sz;
				pre=r2->next[!bitnum]->index;
			}

			if(r2->next[bitnum]!=nullptr){
				r2=r2->next[bitnum];
				r1=r1->next[bitnum];
				continue;
			}

			break;
		}

		if(maxdp<mx){
			maxdp=mx;
			maxdpid=ind;
		}

		TrieNode* temp = head;
		for(int bit=mxbit-1;bit>=0;bit--){
			int isset = (num>>bit)&1;
			if(mx < temp->next[isset]->sz)break;
			temp->next[isset]->sz=mx;
			temp->next[isset]->index=ind;
			temp=temp->next[isset];
		}
		return pre;
	}

	~Trie(){
		delete head;
	}

};

void solve(){
	int n,k;
	cin>>n>>k;

	if(k==0){
		cout<<n<<"\n";
		while(n--)cout<<n+1<<" ";
		cout<<"\n";
		return;
	}

	k--;
	vector<pair<int,int>> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a.begin(),a.end());

	vector<int>prev(n,-1);
	Trie trie;

	for(int i=0;i<n;i++){
		trie.insert(a[i].first,i);
		prev[i]=trie.query(a[i].first,i,k);
	}
	vector<int> ans;
	int cur=trie.maxdpid;
	while(cur!=-1){
		ans.push_back(a[cur].second);
		cur=prev[cur];
	}
	assert(trie.maxdp==0 || trie.maxdp+1==ans.size());
	if(ans.empty())cout<<"-1\n";
	else{
		cout<<ans.size()<<"\n";
		for(int x : ans)cout<<x+1<<" ";
		cout<<"\n";
	}
	
}

signed main(){
	int _t=1;
	//cin>>_t;
	while(_t--){
		solve();
	}
	return 0;
}
//	parsed : 22-April-2022 13:22:32 IST