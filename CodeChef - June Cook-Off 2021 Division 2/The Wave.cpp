/*
	group : CodeChef - June Cook-Off 2021 Division 2
	name : The Wave.cpp
	srcPath : /home/aryan/Documents/cp/The_Wave.cpp
	url : https://www.codechef.com/COOK130B/problems/WAV2
*/
/*
    author : aryan57
    created : 20-June-2021 21:31:36 IST
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
    int n,q;
    cin>>n>>q;

    vector <int> a(n);
    // multiset<int> s;
    for(int  &x : a)
    {
        cin>>x;
        // s.insert(x);
    }

    sort(all(a));

    while(q--)
    {
        int x;
        cin>>x;

        auto it=lower_bound(all(a),x);
        int cnt=0;
        if(it!=a.end())
        {
            if(*it==x)
            {
                cout<<0;
                cout<<"\n";
                continue;
            }

            it--;
            cnt=it-a.begin()+1;

        }else
        {
            cnt=n;
        }

        cout<<(cnt%2 ==0? "POSITIVE":"NEGATIVE");
        cout<<"\n";
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
//	parsed : 20-June-2021 21:30:13 IST