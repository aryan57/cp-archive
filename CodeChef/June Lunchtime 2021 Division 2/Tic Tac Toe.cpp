/*
	group : CodeChef - June Lunchtime 2021 Division 2
	name : Tic Tac Toe.cpp
	srcPath : /mnt/c/Users/aryan/Desktop/cp/Tic_Tac_Toe.cpp
	url : https://www.codechef.com/LTIME97B/problems/TICTACTO
*/
/*
    credits: https://www.youtube.com/watch?v=X3o-X5yAzR4
    author : aryan57
    created : 26-June-2021 22:52:31 IST
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
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int> > point(n*m+1);
    F(i,1,n*m)
    {
        cin>>point[i].X>>point[i].Y;
    }

    string ans="Draw";
    int l=1;
    int r=n*m;

    while (l<=r)
    {
        int mid=(l+r)/2;

        vector< vector<int> > g(n+1,vector <int> (m+1,n*m+10));
        vector< vector<int> > pre(n+1,vector <int> (m+1,0));

        F(i,1,mid)
        {
            g[point[i].X][point[i].Y]=i%2;
        }
        bool ok = false;
        F(i,1,n)
        {
            F(j,1,m)
            {
                pre[i][j]+=g[i][j];
                pre[i][j]+=pre[i-1][j];
                pre[i][j]+=pre[i][j-1];
                pre[i][j]-=pre[i-1][j-1];

                if(i-(k-1)<1 || j-(k-1)<1)continue;

                int s=pre[i][j];
                s+=pre[i-(k-1)-1][j-(k-1)-1];
                s-=pre[i-(k-1)-1][j];
                s-=pre[i][j-(k-1)-1];

                if(s==0)
                {
                    ok=true;
                    ans="Bob";
                    break;
                }
                if(s==k*k)
                {
                    ok=true;
                    ans="Alice";
                    break;
                }
            }

            if(ok)break;
        }

        if(ok)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }

    cout<<ans;cout<<"\n";
    
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