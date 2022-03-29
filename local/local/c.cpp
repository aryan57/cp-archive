/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Dropbox/Documents from PC/free/marwah/ass/c.cpp
	url : /home/aryan/Dropbox/Documents from PC/free/marwah/ass/c.cpp
*/
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

void merge(vector <pair<string,int>> &a,int left,int mid,int right)
{
	int i=left;
	int j=mid+1;
	int k=0;
	vector <pair<string,int>> temp(right-left+1);

	while (i<=mid && j<=right){

		// using less-than-equal-to
		// because if some name has same 
		// 2nd attribute then, name which comes
		// first will be putted earlier
		if(a[i].second<=a[j].second) temp[k++]=a[i++];
		else temp[k++]=a[j++];
	}

	while (i<=mid) temp[k++]=a[i++];
	while (j<=right) temp[k++]=a[j++];
	for(int i=left;i<=right;i++) a[i]=temp[i-left];
}

// taking the vector as a refrence, so need of
// returning the sorted vector, vector will be
// sorted inplace
void merge_sort(vector <pair<string,int>> &a,int left,int right)
{
	if(left>=right)return;
	int mid=(left+right)/2;
	merge_sort(a,left,mid);
	merge_sort(a,mid+1,right);
	merge(a,left,mid,right);
}

int main()
{
	string name;
	int attr1,attr2;

	// making the array as a pair
	// of string and integer where
	// the string represents the anme and the integer
	// represents the 2nd attribute
	vector<pair<string,int>> names;

	// read every line from std-in
	while (cin>>name>>attr1>>attr2)
	{
		// add to the array if the first attribute is 0
		if(attr1==0){
			names.push_back({name,attr2});
		}
	}

	int n=names.size();
	// call the merge sort function
	merge_sort(names,0,n-1);

	// now print the sorted names
	for(int i=0;i<n;i++){
		cout<<names[i].first<<"\n";
	}
	
	return 0;
}