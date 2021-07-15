/*
    author : Aryan Agarwal, 19CS30005
    created : 05-November-2020 10:08:07 IST
*/
#include <iostream>
using namespace std;

const int mxn = 1000;

struct heep
{
    int arr[mxn];
    int size;
};

void heapify(heep &h,int ind)
{
    int l = 2*ind;
    int r = 2*ind +1;
    int p=ind;

    int mx_ind = p;
    if(l<=h.size)if(h.arr[mx_ind]<h.arr[l]){mx_ind=l;}
    if(r<=h.size)if(h.arr[mx_ind]<h.arr[r]){mx_ind=r;}

    if(mx_ind==p)
    {
        return;
    }
    else
    {
        swap(h.arr[p],h.arr[mx_ind]);
        heapify(h,mx_ind);
        return;
    }
        
}

void build_heap(heep &h) //theta(n)
{
    for(int i=h.size/2;i>=1;i--)
    {
        heapify(h,i);
    }
}

void delete_max(heep &h)
{
    swap(h.arr[1],h.arr[h.size]);
    h.size--;
    heapify(h,1);
}

void insert_max(heep &h,int val)
{
    h.size++;
    h.arr[h.size]=val;

    if(h.size==1)return;

    int par=h.size/2;
    int child=h.size;
    
    while(h.arr[par]<h.arr[child])
    {
        swap(h.arr[par],h.arr[child]);
        par/=2;
        child/=2;
    }

}

int main()
{
    
/*
10
1 3 5 4 10 9 8 7 2 6
*/
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;

    heep h;
    h.size=n;

    for(int i=1;i<=n;i++)
    {
        cin>>h.arr[i];
    }
    
    build_heap(h);
    delete_max(h);
    insert_max(h,23);
    // for(int i=1;i<=h.size;i++)cout<<h.arr[i]<<" ";cout<<"\n";
    
    return 0;
}