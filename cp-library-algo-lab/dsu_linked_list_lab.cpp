/*
    author : Aryan Agarwal, 19CS30005
    created : 21-October-2020 15:04:06 IST
*/
#include <iostream>
using namespace std;

struct node
{
    int size;
    int val;
    node* next;
    node* head;
};

node* make_set(int v)
{
    node* new_node=(node*)malloc(sizeof(node));

    new_node->size=1;
    new_node->val=v;
    new_node->head=new_node;
    new_node->next=NULL;

    return new_node;
}

node* find_set(node* x)
{
    return x->head;

}

void union_set(node* x,node* y)
{
    node* a=find_set(x);
    node* b=find_set(y);

    if(a!=b)
    {
       if(a->size<b->size)
       {
           node* w=a;
           while (w!=NULL)
           {
               w->head=b;
               w=w->next;
           }
           
           b->size+=a->size;
       }
       else
       {
           node* w=b;
           while (w!=NULL)
           {
               w->head=a;
               w=w->next;
           }
           a->size+=b->size;
       }
       
    }
}

int main()
{

    // FILE *f1=NULL;
    // FILE *f2=NULL;

    // f1=fopen("in.txt","r");
    // f2=fopen("out.txt","w");
    // fscanf(f1,"%d %d",&a,&b);
    // fprintf(f2,"%d:",a);

    // if(f1==NULL)cout<<"-1"<<endl;

    int n=10;

    node** address_of_node=(node**)malloc(n*sizeof(node*));

    for(int i=1;i<=n;i++)
    {
        address_of_node[i-1]=(node*)malloc(1*sizeof(node));
    }

    for(int i=1;i<=n;i++)
    {
        address_of_node[i-1]=make_set(i);
    }

    cout<<find_set(address_of_node[4])->val<<"\n";
    cout<<find_set(address_of_node[5])->val<<"\n";

    union_set(address_of_node[4],address_of_node[5]);

    cout<<find_set(address_of_node[4])->val<<"\n";
    cout<<find_set(address_of_node[5])->val<<"\n";

    // fclose(f1);
    // fclose(f2);
    
    return 0;
}