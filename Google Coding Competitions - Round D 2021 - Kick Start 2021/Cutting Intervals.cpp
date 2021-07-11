/*
	group : Google Coding Competitions - Round D 2021 - Kick Start 2021
	name : Cutting Intervals.cpp
	srcPath : /home/aryan/Documents/cp/Cutting_Intervals.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/00000000004361e3/000000000082b933
*/
/*
    author : aryan57
    created : 11-July-2021 13:27:30 IST
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

void solve_GOOGLE()
{
    int n,c;
    cin>>n>>c;

    map<int,int> mp;

    F(i,0,n-1)
    {
        int l,r;
        cin>>l>>r;
        if(l!=r)
        {
            mp[l+1]++;
            mp[r]--;

        }
    }

    // dbg(mp);

    pair <int,int> prev;
    bool first=false;

    vector<pair<int,int> > temp;

    for(auto &p: mp)
    {
        if(!first)
        {
            prev=p;
            first=true;
            continue;
        }

        // dbg(p,prev);

        p.Y+=prev.Y;
        temp.push_back({prev.Y,p.X-prev.X});
        prev=p;
    }
    sort(all(temp),greater<pair <int,int> > ());
    // dbg(temp);

    int ans=n;

    for(auto p : temp)
    {
        int cut=min(c,p.Y);
        // if(cut==0)break;
        c-=cut;
        ans+=(cut)*(p.X);
    }

    cout<<ans;
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
        cout<<"Case #"<<i<<": ";
        solve_GOOGLE();
    }
    return 0;
}