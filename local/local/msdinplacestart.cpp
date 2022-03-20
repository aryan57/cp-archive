/*
	group : local
	name : msdinplacestart.cpp
	srcPath : /home/aryan/Dropbox/Documents from PC/free/frost/radix-sort/msdinplacestart.cpp
	url : /home/aryan/Dropbox/Documents from PC/free/frost/radix-sort/msdinplacestart.cpp
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <iostream>
#include <assert.h>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

//--------------------------------------------//
// helper function to generage a random array //
// useful for testing your program            //
//--------------------------------------------//

void getRandomArray(vector<unsigned long int> &A)
{

    for (unsigned int i = 0; i < A.size(); i++)
        A[i] = (unsigned long int)rand() * (unsigned long int)rand() * (unsigned long int)rand();
}

int mx_digits=0;
int get_digit(unsigned long int x,int d){
    d=mx_digits+1-d; // d from front is totoal_digits+1-d from back
    assert(d>=1);
    d--;
    while (d--)x/=10;
    return x%10;
}
int partition(vector<unsigned long int> &A,int l,int r,int d,int dmn,int dmx)
{
    int n=A.size();
    if(l<0 || l>=r || r>=n || dmn<0 || dmn>=dmx || dmx>9 || d<0)return 0;
    int m = (dmn+dmx)/2;
    int swaps=0;
    int i=l,j=r;
    while (i<j)
    {
        if(get_digit(A[i],d)<=m){
            if(get_digit(A[j],d)<=m)i++;
            else i++,j--;
        }else{
            if(get_digit(A[j],d)<=m){
                unsigned long int temp = A[i];
                A[i]=A[j];
                A[j]=temp;
                i++;
                j--;
                swaps++;
            }
            else j--;
        }
    }
    int last=-1;
    for(int i=l;i<=r;i++){
        if(get_digit(A[i],d)<=m)last=i;
    }
    if(last!=-1){
        swaps+=partition(A,l,last,d,dmn,m);
        swaps+=partition(A,last+1,r,d,m+1,dmx);
    }else{
        swaps+=partition(A,l,r,d,m+1,dmx);
    }
    return swaps;
}
int MSDInplaceSort_helper(vector<unsigned long int> &A, int R,int digit,int l,int r){
    int n=A.size();
    if(digit>mx_digits || l<0 || r>=n || l>=r)return 0;
    int swaps=partition(A,l,r,digit,0,R-1);

    int last=l;
    for(int i=l+1;i<=r;i++){
        if(get_digit(A[i],digit)!=get_digit(A[i-1],digit)){
            swaps+=MSDInplaceSort_helper(A,R,digit+1,last,i-1);
            last=i;
        }
    }
    swaps+=MSDInplaceSort_helper(A,R,digit+1,last,r);
    return swaps;
}
int MSDInplaceSort(vector<unsigned long int> &A, int R){
    int n=A.size();
    unsigned long int mx=0;
    for(unsigned long int x : A)mx=max(mx,x);
    if(mx==0)mx_digits=1;
    else mx_digits=0;
    while (mx>0)
    {
        mx_digits++;
        mx/=10;
    }
    return MSDInplaceSort_helper(A,R,1,0,n-1);
}

#ifndef TESTING
int main()
{
    int n = (unsigned long int)rand() % 1000000;
    int R = 10;

    vector<unsigned long int> A;

    // set to false if you want to generate a random array
    // for testing
    bool read_input_from_cin = true;

    if (read_input_from_cin)
    {
        cin >> n; // read the size of array A

        A.resize(n);

        // read array A from standard input
        for (int i = 0; i < n; i++)
            cin >> A[i];
    }
    else
    {
        A.resize(n);
        getRandomArray(A);
    }

    // this is a function you need to implement
    int num_swaps = MSDInplaceSort(A, R);

    // print re-arranged A  to standard output
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << endl;
        if(i && A[i-1]>A[i]){
            assert(false);
        }
    }

    cout << num_swaps;

    return 0;
}

#endif
