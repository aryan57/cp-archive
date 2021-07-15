/*
    author : Aryan Agarwal, 19CS30005
    created : 29-October-2020 11:24:54 IST
*/
#include <bits/stdc++.h>
using namespace std;

// set+of_edges E
// set+of_edges F
void kruksal(int n, int m, set<int> E, set<int> &F)
{
    //  sort the m edges inE by weight in non-decreasing order
    F.clear();
    // initial(n);
    // initialise n disjoint set by 1 vertex each

    while (F.size() < n - 1)
    {
        pair<int, int> e;
        // edge = edge with least weight not yet considered
        // i,j = indices of vertices connected by edge 'e'

        // p,q are set pointers
        // p = find(i)
        // q = find(j)

        // if (!equal(p, q))
        // {
        //     merge(p, q);
        //     add 'e' to F
        // }
    }
}

int main()
{

    return 0;
}