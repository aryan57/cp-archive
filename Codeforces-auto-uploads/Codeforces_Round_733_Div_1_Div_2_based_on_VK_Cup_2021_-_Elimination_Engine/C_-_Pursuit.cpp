/*
    author : aryan57
    created : 17-July-2021 20:22:03 IST
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
    multiset<int,greater<int>> sa[2],sb[2];
    vector <int> a(n),b(n);

    F(i,0,n-1)
    {
        cin>>a[i];
    }
    F(i,0,n-1)
    {
        cin>>b[i];
    }

    sort(all(a),greater<int> ());
    sort(all(b),greater<int> ());

    int cur=n-n/4;
    int ta=0;
    int tb=0;
    F(j,1,n)
    {
        if(j<=cur)
        {
            sa[1].insert(a[j-1]);
            sb[1].insert(b[j-1]);
            ta+=a[j-1];
            tb+=b[j-1];

        }
        else
        {
            sa[0].insert(a[j-1]);
            sb[0].insert(b[j-1]);
        }
    }

    if(ta>=tb)
    {
        cout<<0;
        cout<<"\n";
        return;
    }

    // dbg(ta,tb);

    F(ad,1,10*n)
    {
        

        sa[0].insert(100);
        cur=(n+ad) - (n+ad)/4;

        dbg(cur,sa[0],sa[1]);

        while (!sa[0].empty() && !sa[1].empty())
        {
            int x1=*sa[0].begin();
            int x2=*sa[1].rbegin();
            if(x1<=x2)break;
            sa[0].erase(sa[0].begin());
            auto it2=sa[1].end();
            it2--;
            sa[1].erase(it2);
            ta-=x2;
            sa[0].insert(x2);
            sa[1].insert(x1);
            ta+=x1;

            
        }
        dbg(cur,sa[0],sa[1]);
        while (!sa[0].empty() && sz(sa[1])<cur)
        {
            sa[1].insert(*sa[0].begin());
            ta+=*sa[0].begin();
            sa[0].erase(sa[0].begin());
        }
        dbg(cur,sa[0],sa[1]);
        while (!sa[0].empty() && !sa[1].empty())
        {
            int x1=*sa[0].begin();
            int x2=*sa[1].rbegin();
            if(x1<=x2)break;
            sa[0].erase(sa[0].begin());
            auto it2=sa[1].end();
            it2--;
            sa[1].erase(it2);
            ta-=x2;
            sa[0].insert(x2);
            sa[1].insert(x1);
            ta+=x1;

            
        }
        dbg(cur,sa[0],sa[1]);


        while (!sb[0].empty() && sz(sb[1])<cur)
        {
            sb[1].insert(*sb[0].begin());
            tb+=*sb[0].begin();
            sb[0].erase(sb[0].begin());
        }
        dbg(ad,ta,tb);

        if(ta>=tb)
        {
            cout<<ad;
            cout<<"\n";
            return;
        }

    }

    cout<<0;
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
//	parsed : 17-July-2021 20:15:01 IST