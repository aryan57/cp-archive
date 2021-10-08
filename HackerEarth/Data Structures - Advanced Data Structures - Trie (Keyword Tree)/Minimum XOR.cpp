/*
	group : HackerEarth - Data Structures - Advanced Data Structures - Trie (Keyword Tree)
	name : Minimum XOR.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Minimum_XOR.cpp
	url : https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/kth-min-xor-37903b94/
*/
/**
 *    author:  Aryan Agarwal
 *    created: 08.10.2021 11:03:50 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

class trie{

private:
	static const int mx_nodes = 64*1e5 + 5;
	static const int mx_children = 2;
	int nxt = 1; // 0 is the root node
	vector< vector<int> > child;
	vector <int> no_of_ends;

public:

	trie() : child(vector< vector<int> > (mx_nodes,vector <int> (mx_children))),
	no_of_ends (vector <int> (mx_nodes))
	{
	}

	void insert(string const& s){
		int node=0;
		for(char c : s){
			no_of_ends[node]++;
			assert(node<mx_nodes);
			if(child[node][c-'0']==0)child[node][c-'0']=nxt++;
			node=child[node][c-'0'];
		}
		no_of_ends[node]++;
	}

	int search(string const& key,int k){
		int node=0;
		int ans=0;
		bool not_check=false;

		int pw=(int)pow(2,59);

		// dbg(pw);

		for(char c : key){
			// dbg(c,node,not_check,ans,pw,no_of_ends[child[node][c-'0']],k);

			if(not_check){
				if(c=='1')ans+=pw;
			}else{
				if(child[node][c-'0']!=0){
					if(no_of_ends[child[node][c-'0']]<k){
						k-=no_of_ends[child[node][c-'0']];
						ans+=pw;
						node = child[node][(c-'0')^1];
					}else{
						node = child[node][(c-'0')];
					}
				}
				else if(child[node][(c-'0')^1]!=0){
					ans+=pw;
					node = child[node][(c-'0')^1];
				}else{
					not_check=true;
				}
			}

			if(node==0)not_check=true;

			pw/=2;
		}

		return ans;
	}
};

string get_str(int n)
{
	string str = bitset<60>(n).to_string();
	// reverse(str.begin(),str.end());
	return str;
}

void solve()
{
	int q;
	cin>>q;

	trie t;
	while (q--)
	{
		int op,x;
		cin>>op>>x;
		string str = get_str(x);
		if(op==1){
			// dbg(str);
			t.insert(str);
		}else{
			int k;
			cin>>k;
			cout<<t.search(str,k);
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
//	parsed : 08-October-2021 11:03:43 IST