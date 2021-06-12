/*
	group : HackerRank - GOC-CDC Series #10
	name : Matching Array.cpp
	srcPath : /home/aryan/Documents/cp/Matching_Array.cpp
	url : https://www.hackerrank.com/contests/goc-cdc-series-10/challenges/matching-array
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll pos[1000005];
ll ma[1000005];
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n;
    cin>>n;
    ll a[n];
    ll b[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(ll i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for (ll i = 0; i < n; i++)
    {
        pos[a[i]] = i+1;
    }
    vector <ll> v;
    for (ll i = 0; i < n; i++)
    {
        v.push_back(pos[b[i]]);
    }


    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ma[v[i]] = ma[v[i]-1]+1;
        ans = max(ans, ma[v[i]]);
    }
    cout<< n - ans;
}