/*
	group : Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
	name : E. Boring Segments.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Boring_Segments.cpp
	url : https://codeforces.com/contest/1555/problem/E
*/
/**
 *    author:  Aryan Agarwal
 *    created: 30.07.2021 22:04:50 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long

struct node{
    int l,r,w;
};

bool comp(node a, node b) {
    return a.l<b.l;
}
bool comp2(node a, node b) {
    return a.r<b.r;
}

void solve()
{
    int n,m;
    cin>>n>>m;

    vector<node> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].l>>v[i].r>>v[i].w;
    }

    sort(v.begin(),v.end(),comp);


    int inf=1e9;
    int ans=1e6;
    int l=0;
    int r=1e6;

    while(l<=r){
        int mid=(l+r)/2;
        multiset<node, decltype(comp2)*> s(comp2);
        multiset<int> w;
        bool ok = false;
        int i=0;
        for(;i<n;i++){
            if(v[i].l!=1)break;
            s.insert(v[i]);
            w.insert(v[i].w);
            if(v[i].r==m)ok=true;
        }
        for(;i<n;i++){
            while(!s.empty() && (*s.begin()).r<v[i].l){

                w.erase(w.find((*s.begin()).w));
                s.erase(s.begin());
            }

            int low=v[i].w-mid;
            int high=v[i].w+mid;

            auto it=w.lower_bound(low);
            if(it!=w.end() && *it<=high){
                s.insert(v[i]);
                w.insert(v[i].w);
                if(v[i].r==m)ok=true;
            }

        }

        if(ok){
            ans=min(ans,mid);
            r=mid-1;
        }else{
            l=mid+1;
        }

    }

    cout<<ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    // cin>>_t;
    while(_t--)solve();
    return 0;
}