/*
	group : Codeforces - Codeforces Round #733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))
	name : E. Minimax.cpp
	srcPath : /home/aryan/Documents/cp/E_Minimax.cpp
	url : https://codeforces.com/contest/1530/problem/E
*/
/*
    author : aryan57
    created : 17-July-2021 21:47:28 IST
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
    string s;
    cin >> s;

    int cnt[26] = {};
    int tcnt[26] = {};
    int nz = 0;

    F(i, 0, sz(s) - 1)
    {
        cnt[s[i] - 'a']++;
        tcnt[s[i] - 'a']++;
    }

    int first = -1;
    int next = -1;

    F(i, 0, 25)
    {
        if (cnt[i] == 0)
            continue;

        if (first == -1)
        {
            first = i;
        }
        else if (next == -1)
            next = i;

        if (cnt[i] == 1)
        {
            string ans = "";
            ans += 'a' + i;
            cnt[i] = 0;
            F(j, 0, 25)
            {
                while (cnt[j] > 0)
                {
                    ans += 'a' + j;
                    cnt[j]--;
                }
            }

            cout << ans;
            cout << "\n";
            return;
        }
    }

    if (next == -1)
    {
        cout << s;
        cout << "\n";
        return;
    }

    string ans = "";
    ans += 'a' + first;
    ans += 'a' + first;
    cnt[first]--;
    cnt[first]--;

    F(i, first + 1, 25)
    {
        while (cnt[i] > 0 && cnt[first] > 0)
        {
            ans += 'a' + i;
            ans += 'a' + first;
            cnt[i]--;
            cnt[first]--;
        }
    }

    if (cnt[first] == 0)
    {
        F(i, 0, 25)
        {
            while (cnt[i] > 0)
            {
                ans += 'a' + i;
                cnt[i]--;
            }
        }

        cout << ans;
        cout << "\n";
        return;
    }

    F(i, 0, 25)
    cnt[i] = tcnt[i];

    vector<int> temp;
    F(i, 0, 25)
    {
        if (cnt[i] == 0)
            continue;
        temp.push_back(i);
    }

    if (sz(temp) == 2)
    {
        string ans = "";
        ans += 'a' + temp[0];
        cnt[temp[0]]--;

        while (cnt[temp[1]] > 0)
        {
            ans += 'a' + temp[1];
            cnt[temp[1]]--;
        }
        while (cnt[temp[0]] > 0)
        {
            ans += 'a' + temp[0];
            cnt[temp[0]]--;
        }

        cout << ans;
        cout << "\n";
        return;
    }

    ans = "";
    ans += 'a' + temp[0];
    cnt[temp[0]]--;
    ans += 'a' + temp[1];
    cnt[temp[1]]--;
    while (cnt[temp[0]] > 0)
    {
        ans += 'a' + temp[0];
        cnt[temp[0]]--;
    }

    ans += 'a' + temp[2];
    cnt[temp[2]]--;

    while (cnt[temp[1]] > 0)
    {
        ans += 'a' + temp[1];
        cnt[temp[1]]--;
    }
    F(i, 0, 25)
    {
        while (cnt[i] > 0)
        {
            ans += 'a' + i;
            cnt[i]--;
        }
    }

    cout << ans;
    cout << "\n";
    return;
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