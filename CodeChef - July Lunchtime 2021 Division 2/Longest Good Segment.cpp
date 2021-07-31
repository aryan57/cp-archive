/*
	group : CodeChef - July Lunchtime 2021 Division 2
	name : Longest Good Segment.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Longest_Good_Segment.cpp
	url : https://www.codechef.com/LTIME98B/problems/LGSEG
*/
/**
 *    author:  Aryan Agarwal
 *    created: 31.07.2021 18:45:18 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

int f(vector<int> &a, int k,int s)
{

    int n=a.size();
    n-=2;
    if(n<=0)return 0;
    // dbg(a);
    vector<int> pre(n+2);

    for(int i=1;i<=n+1;i++){
        pre[i]+=pre[i-1]+a[i];
    }

    vector<pair<int,int>> to(n+2);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]>s)continue;
        auto it=upper_bound(pre.begin(),pre.end(),pre[i-1]+s)-pre.begin();
        assert(it>i && it<n+2);
        to[i] = {it,it-i};
        ans=max(ans,it-i);

    }

    int maxiter=1e7;
    
    vector<bool> vis(n+2);

    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        int cur=i;
        int sum=0;
        vector<int> temp;

        int bad=0;

        while(cur>=1 && cur<=n){

            if(vis[cur]){bad++; if(bad>k/2 && maxiter--<0)break;}

            vis[cur]=true;
            temp.push_back(to[cur].second);
            int zz=temp.size();
            sum+=temp[zz-1];
            if(zz>k)sum-=temp[zz-k-1];
            ans=max(ans,sum);
            cur=to[cur].first;
        }
    }

    // if(maxiter<=0)ans++;

    return ans;
}

void solve()
{
    int n,k,s;
    cin>>n>>k>>s;

    vector<int> a(n+2);

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    vector<int> temp;
    temp.push_back(0);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]>s){
            temp.push_back(s+1);
            ans=max(ans,f(temp,k,s));
            temp.clear();
            temp.push_back(0);
        }
        else temp.push_back(a[i]);
    }
    temp.push_back(s+1);
    ans=max(ans,f(temp,k,s));
    ans=min(ans,n);
    cout<<ans<<"\n";


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
//	parsed : 31-July-2021 18:17:32 IST