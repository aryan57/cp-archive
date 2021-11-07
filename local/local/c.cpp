/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/c.cpp
	url : /home/aryan/Desktop/cp-workspace/c.cpp
*/
/**
 *    author:  Aryan Agarwal
 *    created: 06.11.2021 10:32:38 IST
**/
#include <bits/stdc++.h>
using namespace std;

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
/*
	counting inversions from fenwick tree/segment tree :-
		(a) by making indices as array values, will have to do co-ordinate shifting if some values are negative

			time complexity : O(MAX*log(MAX))
			auxiliary space complexity : BigTheta(MAX)

		(b) by first sorting the array and make their values as permutation of n elements,
			keeping the relative order of smaller and greater elements same

			time complexity : O(nlogn)
			auxiliary space complexity : O(n)

		https://codeforces.com/edu/course/2/lesson/4/3
		https://www.geeksforgeeks.org/count-inversions-array-set-3-using-bit/

	counting inversions from merge sort :-
		time complexity : O(nlogn)
		auxiliary space complexity : O(n)
		https://www.geeksforgeeks.org/counting-inversions/

		// merge_sort(arr,0,n-1) will sort the vector in O(nlogn) and return the inversions in the old vector

*/

void solve()
{
	vector<int> v = {5,4,3,2,1};
	int n=v.size();
	cout<<merge_sort(v,0,n-1);
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