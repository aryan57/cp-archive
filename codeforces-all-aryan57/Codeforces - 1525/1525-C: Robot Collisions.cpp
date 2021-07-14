//https://codeforces.com/contest/1525/problem/C

/*
    author : aryan57
    created : 16-May-2021 14:57:12 IST
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

void solve_LOL()
{
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<set<int> > l(2);
    vector<set<int> > r(2);
    vector <int> a(n);
    vector <char> d(n);
    unordered_map<int,int> pos;
    F(i,0,n-1)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }
    F(i,0,n-1)
    {
        cin>>d[i];
        if(d[i]=='L')
        {
            l[a[i]%2].insert(a[i]);
        }
        else
        {
            r[a[i]%2].insert(a[i]);
        }
    }

    vector <int> ans(n,-1);
    vector <std::set<int>::iterator> temp;

    F(par,0,1)
    {
        temp.clear();
        for(auto it2=l[par].begin();it2!=l[par].end();it2++)
        {
            int num=*it2;
            auto it=r[par].lower_bound(num);
            if(it==r[par].begin())continue;

            it--;
            int dif=*it2-*it;
            assert(dif%2==0 && dif>=0);
            ans[pos[*it]]=dif/2;
            ans[pos[*it2]]=dif/2;

            
            r[par].erase(it);


            temp.push_back(it2);
        }

        for(auto it : temp)
        {
            l[par].erase(it);
        }
    }
    F(par,0,1)
    {
        for(auto it2=l[par].begin();it2!=l[par].end();it2++,it2++)
        {
            auto it=it2;
            auto it1=it2;
            it1++;
            if(it1==l[par].end())break;

            int cnt=*it;
            int dif=(*it1-*it);

            cnt+=dif/2;
            assert(dif%2==0 && cnt>=0);

            ans[pos[*it]]=cnt;
            ans[pos[*it1]]=cnt;
        }
        if(sz(l[par])%2==1)
        {
            int num=*l[par].rbegin();
            l[par].clear();
            l[par].insert(num);
        }
        else
        {
            l[par].clear();
        }

        for(auto it2=r[par].rbegin();it2!=r[par].rend();it2++,it2++)
        {
            auto it=it2;
            auto it1=it2;
            it1++;
            if(it1==r[par].rend())break;

            int cnt=m-*it;
            assert(cnt>=0);
            int dif=(*it-*it1);
            cnt+=dif/2;
            assert(dif%2==0 && dif>=0);

            ans[pos[*it]]=cnt;
            ans[pos[*it1]]=cnt;
        }
        if(sz(r[par])%2==1)
        {
            int num=*r[par].begin();
            r[par].clear();
            r[par].insert(num);
        }
        else
        {
            r[par].clear();
        }
        
    }

    F(par,0,1)
    {
        if(l[par].empty()==false && r[par].empty()==false)
        {
            int x1=*l[par].begin();
            int x2=*r[par].rbegin();
            assert(x1<x2);
            int cnt=x1+m-x2+(x2-x1)/2;
            ans[pos[x1]]=cnt;
            ans[pos[x2]]=cnt;

            l[par].erase(l[par].begin());
            auto it=r[par].end();
            it--;
            r[par].erase(it);
        }
    }
    
    
    for(int x : ans)cout<<x<<" ";
    cout<<"\n";
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