//https://codeforces.com/contest/931/problem/C

/*
    author : aryan57
    created : 09-June-2021 00:25:08 IST
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
    int n;
    cin>>n;
    int a[n];
    int s=0;
    F(i,0,n-1)
    {
        cin>>a[i];
        s+=a[i];
    }

    if(*max_element(a,a+n)-*min_element(a,a+n)<2)
    {
        cout<<n;
        cout<<"\n";
        for(int x : a)cout<<x<<" ";
        cout<<"\n";
        return;
    }

    int k=*min_element(a,a+n);

    int x[2]={};

    F(i,0,n-1)
    {
        if(a[i]==k)x[0]++;
        if(a[i]==k+1)x[1]++;
    }

    int c=2*x[0]+x[1];
    int ans=INF;
    int yy[3]={};
    for(int y2=0;y2<=c;y2++)
    {
        if((c-y2)%2)continue;
        int y1=(c-y2)/2;
        if(n-y1-y2<0)continue;

        int ss=0;
        ss+=y1*k;
        ss+=y2*(k+1);
        ss+=(n-y1-y2)*(k+2);

        // dbg(y1,y2,ss);

        if(s!=ss)continue;

        int z=0;
        z+=min(y1,x[0]);
        z+=min(y2,x[1]);
        z+=min(n-y1-y2,n-x[0]-x[1]);

        if(z<ans)
        {
            ans=z;
            yy[0]=y1;
            yy[1]=y2;
            yy[2]=n-y1-y2;
        }

    }

    cout<<ans;
    cout<<"\n";
    F(i,0,2)
    {
        F(j,1,yy[i])
        {
            cout<<k+i<<" ";
        }
    }cout<<"\n";
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
//	parsed : 09-June-2021 24:25:05 IST