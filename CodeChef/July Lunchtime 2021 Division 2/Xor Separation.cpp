/*
	group : CodeChef - July Lunchtime 2021 Division 2
	name : Xor Separation.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Xor_Separation.cpp
	url : https://www.codechef.com/LTIME98B/problems/XORSPRT
*/
/**
 *    author:  Aryan Agarwal
 *    created: 31.07.2021 19:49:28 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
int M = 1e9 + 7;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void solve()
{
    int n;
    cin >> n;

    assert(n <= 20);
    
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    int ans = 0;
    for (int num = 0; num < (int)pow(2, n); num+=2)
    {
        int x = 0;
        bool ok = true;
        int pw = 1;
        for (int bit = 0; bit < n; bit++)
        {
            if ((num >> bit) & 1)
            {
                if (x % pw)
                {
                    ok = false;
                    break;
                }
                x = a[bit];
                pw *= 2;
            }
            else
                x ^= a[bit];
        }
        if (x % pw)
        {
            ok = false;
        }

        if(ok){
            string str = bitset<4>(num). to_string();
            // dbg(str,x,pw,num);
            ans++;
            ans%=M;
        }
    }

    cout<<ans<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    cin >> _t;
    while (_t--)
        solve();
    return 0;
}
//	parsed : 31-July-2021 19:49:17 IST