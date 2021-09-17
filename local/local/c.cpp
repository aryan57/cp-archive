/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/c.cpp
	url : /home/aryan/Desktop/cp-workspace/c.cpp
*/
/**
 *    author:  Aryan Agarwal
 *    created: 13.09.2021 13:50:07 IST
**/
#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;

    node(int _v){
        val = _v;
        next=NULL;
    }
};

int main()
{
    float f = 123.87e-03;
    int n = 2021;
    double d = 123.456;
    char _ch = 'ascii';
    char c = 'x';
    char str1[] = "I am a string\n";
    char arr2[] = ""; // empty string

    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);

    // printing the linked list
    node* temp = head;
    while (temp!=NULL)
    {
        printf("%d ",temp->val);
        temp=temp->next;
    }
    printf("\n");

    return 0;
}