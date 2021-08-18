/*
	group : Google Coding Competitions - Round D 2021 - Kick Start 2021
	name : Final Exam.cpp
	srcPath : /home/aryan/Documents/cp/Final_Exam.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/00000000004361e3/000000000082bffc
*/
/*
    author : aryan57
    created : 11-July-2021 12:38:17 IST
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

void solve_GOOGLE()
{
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> s;

    F(i, 0, n - 1)
    {
        int l, r;
        cin >> l >> r;
        s.insert({l, r});
    }

    vector<int> ans(m);

    F(i, 0, m - 1)
    {
        int z;
        cin >> z;

        auto it = s.lower_bound({z, -INF});
        auto it2 = it;
        it2--;

        if (it == s.end())
        {

            auto p2 = *it2;

            int n2 = p2.Y;
            if (p2.Y >= z)
            {
                ans[i] = z;
                s.erase(it2);

                pair<int, int> x1 = {p2.X, z - 1};
                pair<int, int> x2 = {z + 1, p2.Y};

                if (x1.X <= x1.Y)
                    s.insert(x1);
                if (x2.X <= x2.Y)
                    s.insert(x2);
                continue;
            }
            else
            {
                ans[i] = n2;
                s.erase(it2);
                if (p2.X <= p2.Y - 1)
                    s.insert({p2.X, p2.Y - 1});
                continue;
            }
        }
        else if (it == s.begin())
        {

            auto p1 = *it;
            int n1 = p1.X;
            ans[i] = n1;
            s.erase(it);
            if (p1.X + 1 <= p1.Y)
                s.insert({p1.X + 1, p1.Y});
        }
        else
        {
            auto p1 = *it;
            auto p2 = *it2;

            if (p1.X == z)
            {
                ans[i] = z;
                s.erase(it);
                if (z + 1 <= p1.Y)
                    s.insert({z + 1, p1.Y});
                continue;
            }
            if (p2.Y >= z)
            {
                ans[i] = z;
                s.erase(it2);

                pair<int, int> x1 = {p2.X, z - 1};
                pair<int, int> x2 = {z + 1, p2.Y};

                if (x1.X <= x1.Y)
                    s.insert(x1);
                if (x2.X <= x2.Y)
                    s.insert(x2);
                continue;
            }

            int n1 = p1.X;
            int n2 = p2.Y;

            if (abs(z - n1) < abs(z - n2))
            {
                ans[i] = n1;
                s.erase(it);
                if (p1.X + 1 <= p1.Y)
                    s.insert({p1.X + 1, p1.Y});
                continue;
            }
            else
            {
                ans[i] = n2;
                s.erase(it2);
                if (p2.X <= p2.Y - 1)
                    s.insert({p2.X, p2.Y - 1});
                continue;
            }
        }
    }

    for (int x : ans)
        cout << x << " ";
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
        cout << "Case #" << i << ": ";
        solve_GOOGLE();
    }
    return 0;
}
//	parsed : 11-July-2021 11:02:42 IST