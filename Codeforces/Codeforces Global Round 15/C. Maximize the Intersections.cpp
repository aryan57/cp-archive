/*
	group : Codeforces - Codeforces Global Round 15
	name : C. Maximize the Intersections.cpp
	srcPath : /home/aryan/cp-workspace/C_Maximize_the_Intersections.cpp
	url : https://codeforces.com/contest/1552/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 26.07.2021 15:21:44 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool f(vector<int> &v){
    int n=v.size();
    for(int i=0;i<n;i++){
        rotate(v.begin(),v.begin()+i,v.end());
        if(is_sorted(v.begin(),v.end()))return true;
    }

    return false;
}

void solve()
{
    int n,k;
    cin>>n>>k;

    vector<bool> used(2*n + 1);
    vector<pair<int,int>> lines(n);
    vector<int> points_ava;

    for(int i=0;i<k;i++){
        cin>>lines[i].first>>lines[i].second;
        used[lines[i].first]=true;
        used[lines[i].second]=true;
    }

    for(int i=1;i<=2*n;i++)
    {
        if(!used[i])points_ava.push_back(i);
    }

    int ind=k;
    for(int i=0;i<n-k;i++){
        lines[ind++] = {points_ava[i],points_ava[i+n-k]};
    }

    int cnt=0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            
            vector<int> temp;
            temp.push_back(lines[i].first);
            temp.push_back(lines[j].first);
            temp.push_back(lines[i].second);
            temp.push_back(lines[j].second);
            if(f(temp))cnt++;

            temp.clear();

            temp.push_back(lines[i].first);
            temp.push_back(lines[j].second);
            temp.push_back(lines[i].second);
            temp.push_back(lines[j].first);
            if(f(temp))cnt++;

        }
    }

    cout<<cnt<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    cin>>_t;
    while(_t--)solve();
    return 0;
}
//	parsed : 26-July-2021 12:24:15 IST