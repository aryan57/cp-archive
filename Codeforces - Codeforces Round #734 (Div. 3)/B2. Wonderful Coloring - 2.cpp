/*
	group : Codeforces - Codeforces Round #734 (Div. 3)
	name : B2. Wonderful Coloring - 2.cpp
	srcPath : /home/aryan/Documents/cp/B2_Wonderful_Coloring_2.cpp
	url : https://codeforces.com/contest/1551/problem/B2
*/
/*
    author : aryan57
    created : 23-July-2021 20:30:22 IST
*/
#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
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
    int n, k;
    cin >> n >> k;

    vector<int> pos[n + 1];
    vector<int> a(n + 1);

    F(i, 1, n)
    {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    int ans = 0;
    vector<int> vec(n + 1);

    int l = 1;
    int r = n;

    while (l <= r)
    {
        int m = (l + r) / 2;

        int len = (m + k - 1) / (k);

        dbg(len,m);

        int cnt=0;
        vector <int> temp(n+1);
        int ind=1;
        F(i,1,n)
        {
            F(j,0,sz(pos[i])-1)
            {
                temp[pos[i][j]]=ind;
                ind++;
                cnt++;
                if(cnt==k*len)break;
                if(ind==k+1)
                {
                    ind=1;
                }

                if(j==k-1)break;
            }
            if(cnt==k*len)break;
        }



        if (cnt == k * len)
        {
            F(i, 1, n)
            {
                vec[i] = temp[i];
            }

            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    F(i, 1, n)
    cout << vec[i] << " ";
    cout << "\n";
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
    int _t = 1;
    cin >> _t;
    for (int i = 1; i <= _t; i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}
//	parsed : 23-July-2021 20:11:59 IST