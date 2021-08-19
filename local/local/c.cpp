/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/c.cpp
	url : /home/aryan/Desktop/cp-workspace/c.cpp
*/
/**
 *    author:  Aryan Agarwal
 *    created: 19.08.2021 12:26:59 IST
**/
#include <bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	Node* next;

	Node(){
		val=0;
		next=NULL;
	}
	Node(int x){
		val=x;
		next=NULL;
	}
};



signed main()
{

	/*
	*/

	Node* head = NULL;

	cout<<head->val<<"\n";

	// 1,2,3,4,5,6


	Node* head = new Node(1);
	Node* temp = head;


	for(int i=2;i<=5;i++){
		temp->next = new Node(i);
		temp=temp->next;
	}

	int n=0;
	temp=head;
	while(temp!=NULL){
		n++;
		temp=temp->next;
	}

	/*
		falsy value -> 0,NULL,nullptr
		truly value ->
	*/

	if(n==0){
		cout<<"-1\n";
		return 0;
	}

	int k = n/2+1;

	int cur=0;
	temp=head;
	while(temp!=NULL){
		cur++;
		if(cur==k){
			cout<<temp->val<<"\n";
			break;
		}

		temp=temp->next;
	}

	return 0;
}