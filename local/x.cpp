/*
	group : local
	name : x.cpp
	srcPath : /home/aryan/Documents/cp/x.cpp
	url : /home/aryan/Documents/cp/x.cpp
*/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector <string> v={"a","b","ac","acac"};
    sort(v.begin(),v.end());

    for(auto s : v)
    {
        cout<<s<<" ";
    }    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    
}