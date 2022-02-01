/*
	group : DMOJ - An Animal Contest 5
	name : P3 - Ski Resort.cpp
	srcPath : /home/aryan/Desktop/P3_Ski_Resort.cpp
	url : https://dmoj.ca/problem/aac5p3
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
const int inf = 2e5 + 5;

int n, k;
vector<pi> adj[inf];
vi skills; int used[inf]; pi range[inf];

void dfs(int v, pi bounds) {
    used[v] = true;
	int l=bounds.F;
	int r=bounds.S;
	if(l>r || (l==0 && r==0))return;
    pi lastrange = bounds;
	int sz = adj[v].size();
	for (int i =0; i < sz; i++) {

		int u = adj[v][i].S, x = adj[v][i].F;
		if(used[u])continue;
		int nextx=-1;
		int nextu=-1;

		if(i+1==sz){
		}else{
			if(!used[adj[v][i+1].S]){
				nextu=adj[v][i+1].S;
				nextx=adj[v][i+1].F;
			}else if(i+3<=sz){
				nextu=adj[v][i+2].S;
				nextx=adj[v][i+2].F;
			}
		}

		int left=lastrange.F;
		int right=lastrange.S;
		// bool bad=false;
		if(nextx==-1){
			range[u]=lastrange;
			break;
		}else{
			range[u].F=lastrange.F;
			range[u].S=min(right,(nextx+x)/2);
		}

		lastrange.F = max(lastrange.F,range[u].S+1);
		if(lastrange.F>lastrange.S)break;
	}
	for (int i =0; i < adj[v].size(); i++) {
		pi p1 = adj[v][i];
		int u1 = p1.S;
		if (!used[u1]) dfs(u1, range[u1]);
	}
    

}

int main() {
    cin >> n >> k;
    skills.resize(k);
    memset(used, 0, sizeof used);
    for (int i =0; i <n-1; i++) {
        int a,b,d; cin >> a >> b >> d;
        adj[a].PB({d, b});
        adj[b].PB({d, a});
    }
    for (int i=1; i<=n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    //for (auto [w, u] : adj[2]) cout << u << " " << w << endl;
    for (int i=0; i <k; i++) {cin >> skills[i];}
    range[1] = {1, 1e9};
    dfs(1,  {1, 1e9});
	sort(skills.begin(),skills.end());
    for (int i=1; i <=n; i++) {
        // cout << range[i].F << " " << range[i].S << endl;
		if(range[i].F>range[i].S){
			range[i]={0,0};
		}
        auto a = upper_bound(skills.begin(), skills.end(), range[i].S)-skills.begin();
        auto b = lower_bound(skills.begin(), skills.end(), range[i].F)-skills.begin();
        //if (a == skills.end()) {a++;}
        //if (b == skills-1) b++;
        if(i<n)cout << a-b << " ";
		else cout<<a-b;
    }
	cout<<endl;
}















//	parsed : 02-February-2022 03:14:42 IST