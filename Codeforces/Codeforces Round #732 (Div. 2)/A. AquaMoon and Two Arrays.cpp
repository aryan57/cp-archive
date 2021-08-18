/*
	group : Codeforces - Codeforces Round #732 (Div. 2)
	name : A. AquaMoon and Two Arrays.cpp
	srcPath : /home/aryan/Documents/cp/A_AquaMoon_and_Two_Arrays.cpp
	url : https://codeforces.com/contest/1546/problem/0
*/
/*
    author : aryan57
    created : 11-July-2021 19:47:23 IST
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

    vector <int> a(n),b(n);
    
    int sa=0;
    int sb=0;

    set<int> p,nn;
    vector<pair<int,int> > ans;

    F(i,0,n-1)
    {
        cin>>a[i];
        sa+=a[i];
    }
    F(i,0,n-1)
    {
        cin>>b[i];
        sb+=b[i];
        if(a[i]>b[i])
        {
            nn.insert(i);
        }
        if(a[i]<b[i])
        {
            p.insert(i);
        }
    }

    if(sa!=sb)
    {
        cout<<"-1\n";
        return;
    }

    while (!p.empty() && !nn.empty())
    {
        
            ans.push_back({*nn.begin(),*p.begin()});
            a[*nn.begin()]--;
            a[*p.begin()]++;

            if(a[*p.begin()]==b[*p.begin()])
            {
                p.erase(p.begin());
            }
            if(a[*nn.begin()]==b[*nn.begin()])
            {
                nn.erase(nn.begin());
            }
        
    }

    F(i,0,n-1)if(a[i]!=b[i])
    {
        cout<<"-1\n";
        return;
    }

    cout<<sz(ans)<<"\n";
    for(auto z : ans)cout<<z.X+1<<" "<<z.Y+1<<"\n";
    
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