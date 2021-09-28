/*
	group : Codeforces - Codeforces Round #744 (Div. 3)
	name : E2. Array Optimization by Deque.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E2_Array_Optimization_by_Deque.cpp
	url : https://codeforces.com/contest/1579/problem/E2
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.09.2021 21:18:49 IST
**/
// INCLUDE AT TOP (no #define int long long)
// If you want to convert into ordered_multiset change less<int> to less_equal<int>
// But then lower_bound will act as upper_bound
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set; 
// order_of_key: The number of items in a set that are strictly smaller than k
// find_by_order: It returns an iterator to the ith largest element

#define int long long

int merge(vector <int> &a,int left,int mid,int right)
{
	int i=left;
	int j=mid+1;
	int k=0;
	int inversions=0;
	vector <int> temp(right-left+1);

	while (i<=mid && j<=right){
		if(a[i]<=a[j]) temp[k++]=a[i++];
		else temp[k++]=a[j++],inversions+=mid-i+1;
	}

	while (i<=mid) temp[k++]=a[i++];
	while (j<=right) temp[k++]=a[j++];
	for(int i=left;i<=right;i++) a[i]=temp[i-left];
	
	return inversions;
}

int merge_sort(vector <int> &a,int left,int right)
{
	if(left>=right)return 0;

	int mid=(left+right)/2;
	int inversions = 0;

	inversions+=merge_sort(a,left,mid);
	inversions+=merge_sort(a,mid+1,right);
	inversions+=merge(a,left,mid,right);

	return inversions;
}

void solve()
{
	int n;
	cin>>n;

	ordered_set m;
	deque<int> d;
	unordered_map<int,int> cnt;
	
	int x;
	cin>>x;
	
	int t=0;
	d.push_back(x);
	m.insert(x);
	t++;
	cnt[x]++;

	for(int i=1;i<n;i++){
		cin>>x;

		int l=m.order_of_key(x);
		int geq=t-l;
		int eq=cnt[x];
		int g=geq-eq;

		assert(l>=0 && geq>=0 && g>=0);


		if(l<=g){
			d.push_front(x);
		}else{
			d.push_back(x);
		}

		m.insert(x);
		cnt[x]++;
		t++;
	}

	vector <int> z(n);
	int ind=0;

	while (!d.empty())
	{
		z[ind++]=d.front();
		d.pop_front();
	}
	
	cout<<merge_sort(z,0,n-1)<<"\n";

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 28-September-2021 21:18:43 IST