//https://codeforces.com/contest/1521/problem/C

/*
    author : aryan57
    created : 07-May-2021 21:35:15 IST
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
    int n;
    cin>>n;

    vector<pair<int,int> > temp;
    int pos1=-1;

    for(int i=1;i<=n;i+=2)
    {
        int l=i;
        int r=i+1;

        if(r>n)
        {
            l--;
            r--;
        }

        cout<<"? 2 "<<l<<" "<<r<<" "<<1<<endl;
        int val;
        cin>>val;

        if(val==1)
        {
            pos1=l;
            break;
        }
        if(val==2)
        {
            temp.push_back({l,r});
        }
    }

    if(pos1==-1)
    {
        for(auto p : temp)
        {
            int l=p.Y;
            int r=p.X;

            cout<<"? 2 "<<l<<" "<<r<<" "<<1<<endl;
            int val;
            cin>>val;

            if(val==1)
            {
                pos1=l;
                break;
            }
        }
    }

    assert(pos1!=-1);

    int ans[n+1]={};
    ans[pos1]=1;

    F(j,1,n)
    {
        if(j==pos1)continue;

        int l=pos1;
        int r=j;

        cout<<"? 1 "<<l<<" "<<r<<" "<<n-1<<endl;
        int val;
        cin>>val;
        ans[j]=val;
    }

    cout<<"! ";
    F(i,1,n)cout<<ans[i]<<" ";
    cout<<"\n";
}

signed main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
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