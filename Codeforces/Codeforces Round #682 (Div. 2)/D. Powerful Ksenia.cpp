/*
	group : Codeforces - Codeforces Round #682 (Div. 2)
	name : D. Powerful Ksenia.cpp
	srcPath : /home/aryan/Documents/cp/D_Powerful_Ksenia.cpp
	url : https://codeforces.com/contest/1438/problem/D
*/
/*
    author : aryan57
    created : 10-July-2021 14:50:37 IST
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

struct z
{
    int i=0;
    int j=0;
    int k=0;
};


void solve_LOG()
{
    int n;
    cin>>n;

    vector <z> ans;
    set <pair <int,int> > v;
    vector <int> a(n);
    F(i,0,n-1)
    {
        int x;
        cin>>x;
        a[i]=x;
        v.insert({x,i});
    }
    vector<pair<int,int> > p;
    vector<pair<int,int> > p2;

    while (sz(v)>=2)
    {
        auto it=v.begin();
        auto it2=v.begin();
        it2++;

        if((*it).X==(*it2).X)
        {
            p.push_back({(*it).Y,(*it2).Y});
            v.erase(it);
            v.erase(it2);
        }else
        {
            p2.push_back(*it);
            v.erase(it);
        }
    }
    while (sz(v)>=1)
    {
        auto it=v.begin();
        
        p2.push_back(*it);
        v.erase(it);
        
    }

    if(sz(p2)%2)
    {
        if(sz(p2)==1)
        {
            for(auto pp : p)
            {
                ans.push_back({p2[0].Y,pp.X,pp.Y});
            }
        }
        else
        {
            int last=-1;

            // dbg(sz(ans),p2,p);

            for(int i=0;;)
            {
                if(i+2>=sz(p2))break;
                ans.push_back({p2[i].Y,p2[i+1].Y,p2[i+2].Y});
                p.push_back({p2[i].Y,p2[i+1].Y});
                last=p2[i+2].Y;
                i+=2;
            }
            assert(last!=-1);
            for(auto pp : p)
            {
                ans.push_back({last,pp.X,pp.Y});
            }
        }
    }
    else
    {
        if(sz(p2)==0)
        {
            F(i,1,sz(p)-1)
            {
                ans.push_back({p[0].X,p[i].X,p[i].Y});
            }
        }
        else
        {
            int last=-1;

            for(int i=0;;)
            {
                if(i+2>=sz(p2))
                {
                    assert(i+1<sz(p2));
                    last=p2[i+1].Y;
                    break;
                }
                ans.push_back({p2[i].Y,p2[i+1].Y,p2[i+2].Y});
                p.push_back({p2[i].Y,p2[i+1].Y});
                i+=2;
            }
            assert(last!=-1);
            for(auto pp : p)
            {
                ans.push_back({last,pp.X,pp.Y});
            }
        }
    }

    if(sz(ans)>n)
    {
        cout<<"NO\n";
        return;
    }
    for(auto zz : ans)
    {
        a[zz.i]=a[zz.j]=a[zz.k]=(a[zz.i]^a[zz.j]^a[zz.k]);
    }

    sort(all(a));
    F(i,0,n-2)
    {
        if(a[i]!=a[i+1])
        {
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
    cout<<sz(ans);
    cout<<"\n";
    for(auto zz : ans)
    {
        cout<<zz.i+1<<" "<<zz.j+1<<" "<<zz.k+1<<"\n";
    }
    
    
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
    // cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOG();
    }
    return 0;
}
//	parsed : 10-July-2021 13:59:32 IST