/*
    author : aryan57
    created : 17-July-2021 20:51:34 IST
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

void solve2(vector <int> &v)
{
    int n=sz(v)-1;

    vector <int> a(n+1,-1);
    int cnt[n+1] = {};
    set<int> s;
    F(i,1,n)
    {
        s.insert(i);
    }
    int k=0;
    RF(i,n,1)
    {
        cnt[v[i]]++;
        if(cnt[v[i]]==1)
        {
            a[i]=v[i];
            s.erase(v[i]);
            k++;
        }
    }

    vector <int> epos;
    vector <int> upos;
    
    F(i,1,n)
    {
        if(a[i]==-1)
        {
            // auto it=s.begin();
            a[i]=*s.begin();
            if(a[i]==i)epos.push_back(i);
            else upos.push_back(i);
            s.erase(s.begin());
        }

        
    }

    if(sz(epos)==0)
    {
        cout<<k;
        cout<<"\n";
        F(i,1,n)cout<<a[i]<<" ";
        cout<<"\n";
        return;
    }

    if(sz(upos)>0)
    {
        for(int pos : epos)
        {
            swap(a[pos],a[upos[0]]);
            assert(a[pos]!=pos);
        }
        cout<<k;
        cout<<"\n";
        F(i,1,n)cout<<a[i]<<" ";
        cout<<"\n";
        return;
    }

    F(i,1,n)
    {
        if(i==n)cout<<1;
        else cout<<i+1<<" ";
    }cout<<"\n";

}

void solve_LOL()
{
    int n;
    cin>>n;

    vector <int> v(n+1);
    vector <int> a(n+1,-1);
    int cnt[n+1] = {};
    set<int> s;
    F(i,1,n)
    {
        s.insert(i);
    }
    int k=0;
    F(i,1,n)
    {
        cin>>v[i];
        cnt[v[i]]++;
        if(cnt[v[i]]==1)
        {
            a[i]=v[i];
            s.erase(v[i]);
            k++;
        }
    }

    vector <int> epos;
    vector <int> upos;
    
    F(i,1,n)
    {
        if(a[i]==-1)
        {
            // auto it=s.begin();
            a[i]=*s.begin();
            if(a[i]==i)epos.push_back(i);
            else upos.push_back(i);
            s.erase(s.begin());
        }

        
    }

    if(sz(epos)==0)
    {
        cout<<k;
        cout<<"\n";
        F(i,1,n)cout<<a[i]<<" ";
        cout<<"\n";
        return;
    }

    if(sz(upos)>0)
    {
        for(int pos : epos)
        {
            swap(a[pos],a[upos[0]]);
            assert(a[pos]!=pos);
        }
        cout<<k;
        cout<<"\n";
        F(i,1,n)cout<<a[i]<<" ";
        cout<<"\n";
        return;
    }

    solve2(v);

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
        solve_LOL();
    }
    return 0;
}
//	parsed : 17-July-2021 20:48:14 IST