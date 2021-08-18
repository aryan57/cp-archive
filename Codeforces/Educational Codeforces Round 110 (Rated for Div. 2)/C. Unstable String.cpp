/*
	group : Codeforces - Educational Codeforces Round 110 (Rated for Div. 2)
	name : C. Unstable String.cpp
	srcPath : /home/aryan/Documents/cp/C_Unstable_String.cpp
	url : https://codeforces.com/contest/1535/problem/C
*/
/*
    author : aryan57
    created : 04-June-2021 20:23:54 IST
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

    int n=sz(s);

    string s1="";
    string s2="";

    vector <int> p1,p0;
    F(i,0,n-1)
    {
        if(i%2)s1+='1',s2+='0';
        else s1+='0',s2+='1';

        if(s[i]=='1')
        {
            p1.push_back(i);
        }
        if(s[i]=='0')
        {
            p0.push_back(i);
        }
    }

    vector <int> une1,une2;

    F(i,0,n-1)
    {
        if(s[i]=='?')continue;
        if(s[i]!=s1[i])une1.push_back(i);
        if(s[i]!=s2[i])une2.push_back(i);
    }

    dbg(s1,s2);

    int cnt=0;

    F(i,0,n-1)
    {
        int pos1=lower_bound(all(p1),i)-p1.begin();
        int pos0=lower_bound(all(p0),i)-p0.begin();

        if(pos1==sz(p1) && pos0==sz(p0))
        {
            cnt+=((n-i)*(n-i+1))/2;
            break;
        }
        int par=1;
        int ind=-1;

        if((pos0==sz(p0)) ||(pos1<sz(p1) && p1[pos1]<p0[pos0]))
        {
            ind=p1[pos1];
            if(s1[ind]=='1')par=1;
            else par=2;
        }
        else
        {
            ind=p0[pos0];
            if(s1[ind]=='0')par=1;
            else par=2;

        }

        dbg(i,par,ind,cnt);

        if(par==1)
        {
            int pos=lower_bound(all(une1),ind)-une1.begin();
            int last=n;
            if(pos!=sz(une1))
            {
                last=une1[pos];
            }

            dbg(i,pos,last);

            int len=last-i;
            cnt+=len;
        }
        else
        {
            int pos=lower_bound(all(une2),ind)-une2.begin();
            int last=n;
            if(pos!=sz(une2))
            {
                last=une2[pos];
            }

            int len=last-i;
            cnt+=len;
        }

        dbg(cnt);
    }

    cout<<cnt;
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
//	parsed : 04-June-2021 20:23:50 IST