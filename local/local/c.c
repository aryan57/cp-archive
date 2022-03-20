/*
	group : local
	name : c.c
	srcPath : /home/aryan/cp-workspace/c.c
	url : /home/aryan/cp-workspace/c.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

extern int errno;

typedef struct __Node{
	struct __Node *next;
	int value;
} Node;

typedef struct {
	Node *last_node;
} Cl;

int cl_insert(Cl *list,int value){

	Node *node = (Node*)malloc(sizeof(Node));
	node->value=value;
	if(list->last_node==NULL){
		list->last_node=node;
		node->next=node;
		return 0;
	}
	node->next=list->last_node->next;
	list->last_node->next=node;
	list->last_node=node;
	return 0;
}

int cl_remove(Cl *list){
	if(list->last_node==NULL){
		return -1;
	}
	if(list->last_node->next==NULL){
		return -1;
	}

	int ans = list->last_node->next->value;

	if(list->last_node==list->last_node->next){
		free(list->last_node->next);
		list->last_node=NULL;
	}else{
		Node* temp = list->last_node->next;
		list->last_node->next=temp->next;
		free(temp);
	}

	return ans;
}

Cl cl_split(Cl *list,Node* new_last){
	Cl ans;
	ans.last_node=NULL;

	// if list was empty or
	// new last is same as old
	// new Cl will be empty
	if(list->last_node==NULL || new_last->value==list->last_node->value){
		return ans;
	}


	Node* here_first;
	Node* here_last;

	here_first = list->last_node->next;
	here_last=list->last_node;

	Node *temp=here_first;
	Node *here_new_last=NULL;
	while (temp!=here_last)
	{
		if(temp->value==new_last->value){
			here_new_last=temp;
			break;
		}
		temp=temp->next;
	}
	
	// not found
	if(here_new_last==NULL){
		return ans;
	}

	here_last->next=here_new_last->next;
	here_new_last->next=here_first;
	list->last_node=here_new_last;
	ans.last_node=here_last;
	return ans;
}

int main()
{
	
	Cl* list = (Cl*)malloc(sizeof(Cl));
	list->last_node=NULL;

	cl_insert(list,1);
	cl_insert(list,2);
	cl_insert(list,3);
	cl_insert(list,4);

	int front = cl_remove(list);
	printf("%d\n",front);
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->value=3;
	Cl new_cl = cl_split(list,new_node);

	int tt=4;
	Node* temp = list->last_node->next;
	while (tt--)
	{
		printf("%d ",temp->value);
		temp=temp->next;
	}

	printf("^\n");

	{

	int tt=4;
	Node* temp = new_cl.last_node->next;
	while (tt--)
	{
		printf("%d ",temp->value);
		temp=temp->next;
	}

	printf("^\n");
	}

	return 0;
}