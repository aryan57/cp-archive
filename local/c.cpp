/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/c.cpp
	url : /home/aryan/Desktop/cp-workspace/c.cpp
*/
/*
    author : aryan57
    created : 31-July-2021 20:32:52 IST
*/
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

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
        assert(it>i);
        to[i] = {it,it-i};
        ans=max(ans,it-i);

    }


    
    vector<bool> vis(n+2);

    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        int cur=i;
        int sum=0;
        vector<int> temp;
        while(cur>=1 && cur<=n){
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

    cout<<ans<<"\n";


}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
#endif
#ifdef ARYAN_SIEVE
    sieve();
#endif
#ifdef ARYAN_SEG_SIEVE
    segmented_sieve();
#endif
#ifdef ARYAN_FACT
    fact_init();
#endif
    // cout<<fixed<<setprecision(10);
    int _t=1;
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}