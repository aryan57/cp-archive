/*
	group : CodeChef - December Challenge 2021 Division 1 (Unrated)
	name : Min Manhattan Distance.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Min_Manhattan_Distance.cpp
	url : https://www.codechef.com/DEC21A/problems/MINMANH
*/
/**
 *    author:  Aryan Agarwal
 *    created: 08.12.2021 23:13:45 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long

void createTree(int l, int r, int ind, vector<vector<int> >& segtree, vector<int>& arr)
{
    if(l==r){
        segtree[ind].push_back(arr[l]);
        return;
    }

    int mid=(l+r)/2;
    createTree(l, mid, 2*ind+1, segtree, arr);
    createTree(mid+1, r, 2*ind+2, segtree, arr);
    int i=0, j=0;
    vector<int>& temp1=segtree[2*ind+1];
    vector<int>& temp2=segtree[2*ind+2];
    int n=temp1.size();
    int m=temp2.size();
    while(i<n && j<m)
    {
        if(temp1[i]<temp2[j])
			segtree[ind].push_back(temp1[i++]);
        else
        	segtree[ind].push_back(temp2[j++]);
    }
    while(i<n)segtree[ind].push_back(temp1[i++]);
    while(j<m)segtree[ind].push_back(temp2[j++]);
    
}

void query(int l, int r, int L, int R, int x, int y, int ind, vector<vector<int> >& segtree, int& ans)
{
	if(ans!=0)return;
    if(r<L || l>R) return;
    if(l>=L && r<=R)
    {
        int ind1=lower_bound(segtree[ind].begin(), segtree[ind].end(), x)-segtree[ind].begin();
        int ind2=upper_bound(segtree[ind].begin(), segtree[ind].end(), y)-segtree[ind].begin()-1;
        ans+=max(0l, ind2-ind1+1);
        return;
    }
    int mid=(l+r)/2;
    query(l, mid, L, R, x, y, 2*ind+1, segtree, ans);
    query(mid+1, r, L, R, x, y, 2*ind+2, segtree, ans);
}

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<pair<int,int> > v(n);
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[i].first=x-y; // D
		v[i].second=x+y; // C
	}
	sort(v.begin(),v.end());
	vector<int> C(n),D(n);
    for(int i=0;i<n;i++){
		C[i]=v[i].second;
		D[i]=v[i].first;
	}
    vector<vector<int> > segtree(4*n);
    createTree(0, n-1, 0, segtree, C);

	const int INF = 2e18;

	while (m--){
		int A,B;
		cin>>A>>B;
		int l=-INF,r=INF;
		int mn=r;

		while (l<=r){
			int m=(l+r)/2;
			int first=lower_bound(D.begin(),D.end(),-m+A-B)-D.begin();
			int last=upper_bound(D.begin(),D.end(),m+A-B)-D.begin()-1;
			int x=-m+A+B;
			int y=m+A+B;
			int ans=0;
			query(0, n-1, first, last, x, y, 0, segtree, ans);
			if(ans!=0){
				mn=min(mn,m);
				r=m-1;
			}else{
				l=m+1;
			}
		}
		cout<<mn<<"\n";
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