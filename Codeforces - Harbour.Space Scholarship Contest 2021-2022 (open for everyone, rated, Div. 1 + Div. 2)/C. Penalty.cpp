/*
	group : Codeforces - Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)
	name : C. Penalty.cpp
	srcPath : /home/aryan/Documents/cp/C_Penalty.cpp
	url : https://codeforces.com/contest/1553/problem/C
*/
/*
    author : aryan57
    created : 22-July-2021 20:37:55 IST
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
    string s;
    cin>>s;

    vector <int> pos;

    F(i,0,9)
    {
        if(s[i]=='?')pos.push_back(i);
    }

    int ans=10;

    F(num,0,(int)pow(2,sz(pos))-1)
    {
        string z=s;

        F(bit,0,sz(pos)-1)
        {
            if((num>>bit)&1)
            {
                z[pos[bit]]='1';
            }else
            {

                z[pos[bit]]='0';
            }
        }

        int x1=0;
        int y1=0;
        int x2=5;
        int y2=5;

        F(i,0,9)
        {
            assert(z[i]!='?');
            if(i%2==0)
            {
                if(z[i]=='1')x1++;
                x2--;
            }
            else
            {
                if(z[i]=='1')y1++;
                y2--;
            }

            pair <int,int> p1={x1,x1+x2};
            pair <int,int> p2={y1,y1+y2};


            if(p1.Y<p2.X || p2.Y<p1.X)
            {
                ans=min(ans,i+1);
            }

        }
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
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}
//	parsed : 22-July-2021 20:22:58 IST