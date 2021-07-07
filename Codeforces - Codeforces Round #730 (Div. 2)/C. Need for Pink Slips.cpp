/*
	group : Codeforces - Codeforces Round #730 (Div. 2)
	name : C. Need for Pink Slips.cpp
	srcPath : /home/aryan/Documents/cp/C_Need_for_Pink_Slips.cpp
	url : https://codeforces.com/contest/1543/problem/C
*/
/*
    author : aryan57
    created : 07-July-2021 21:46:48 IST
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

long double ans;
long double c,m,p,v;

void f(int l)
{
    
    F(num,0,(int)pow(2,l)-1)
    {
        long double cc=c;
        long double mm=m;
        long double pp=p;
        bool ok = true;
        long double t=1.0;

        F(bit,0,l-1)
        {
            // if(l==2)dbg(bit,pp);

            if((num>>bit)&1)
            {
                if(cc< 1e-8 )
                {
                    ok=false;
                    break;
                }

                t*=cc;
                long double zz= min(cc,v);
                cc-=zz;

                if(mm> 1e-8)
                {
                    mm+=zz/2;
                    pp+=zz/2;

                }
                else
                {
                    pp+=zz;
                }
                
            }
            else
            {

                if(mm< 1e-8 )
                {
                    ok=false;
                    break;
                }
                t*=mm;
                long double zz= min(mm,v);
                mm-=zz;
                if(cc> 1e-8)
                {
                    cc+=zz/2;
                    pp+=zz/2;

                }
                else
                {
                    pp+=zz;
                }
            }
        }

        // if(l==2)dbg(ok,pp);

        if(ok)
        {
            // dbg(l+1,pp,t);
            ans+=(l+1)*(pp)*t;
        }
    }
}

void solve_LOL()
{
    
    cin>>c>>m>>p>>v;
    ans=p;
    F(i,1,20)
    {
        f(i);
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
    cout<<fixed<<setprecision(10);
    int _t=1;
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}
//	parsed : 07-July-2021 20:27:27 IST