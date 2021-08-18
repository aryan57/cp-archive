/*
	group : Codeforces - Codeforces Round #513 by Barcelona Bootcamp (rated, Div. 1 + Div. 2)
	name : D. Social Circles.cpp
	srcPath : /home/aryan/Documents/cp/D_Social_Circles.cpp
	url : https://codeforces.com/contest/1060/problem/D
*/
/*
    author : aryan57
    created : 09-June-2021 03:36:43 IST
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

void solve_LOG()
{
    int n;
    cin>>n;
    set<pair <int,int> ,greater<pair <int,int> >> l,r;

    vector <int> a(n+1),b(n+1);

    F(i,1,n)
    {
        int x,y;
        cin>>x>>y;
        l.insert({x,i});
        r.insert({y,i});
        a[i]=x;
        b[i]=y;
    }

    int cost=0;

    while (sz(l)>1 && sz(r)>1)
    {
        assert(sz(l)==sz(r));

        auto il=l.begin();
        auto ir=r.begin();

        // dbg(l,r);

        int idl=(*il).Y;
        int idr=(*ir).Y;

        int x=(*il).X;
        int y=(*ir).X;

        if(idl==idr)
        {
            cost+=1+max(x,y);
            l.erase(il);
            r.erase(ir);
            continue;
        }

        idl=(*il).Y;
        idr=(*ir).Y;

        x=(*il).X;
        y=(*ir).X;

        // dbg(x,y,idl,idr);
        
        cost+=max(x,y)+1;

        int new_id=min(idl,idr);
        int new_left=a[idr];
        assert(b[idr]==y);
        int new_right=b[idl];
        assert(a[idl]==x);

        l.erase({a[idl],idl});
        l.erase({a[idr],idr});
        r.erase({b[idl],idl});
        r.erase({b[idr],idr});

        a[new_id]=new_left;
        b[new_id]=new_right;


        l.insert({new_left,new_id});
        r.insert({new_right,new_id});

        // dbg(l,r);


    }

    cost+=max((*l.begin()).X,(*r.begin()).X)+1;
    cout<<cost;
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
//	parsed : 09-June-2021 03:26:11 IST