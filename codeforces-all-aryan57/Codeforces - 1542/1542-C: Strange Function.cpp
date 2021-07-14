//https://codeforces.com/contest/1542/problem/C

/*
    author : aryan57
    created : 03-July-2021 19:11:22 IST
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
const long long INF = 1e17;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);


int ceil(int a, int b)
{
    return (a + b - 1) / b;
}

int f(int n,int l,int r)
{
    if(n>r)return 0;

    int y=(r/n)*n;
    int x=ceil(l,n)*n;

    int cnt=0;
    cnt+=(y-x+1)/n +1;
    
    if(cnt<0)cnt=0;

    return cnt;
}

int gcd(int a, int b) /*__gcd doesn't work for big no.s*/
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve_LOL()
{
    int n;
    cin>>n;

    // if(n==1)
    // {
    //     cout<<2;
    //     cout<<"\n";
    //     return;
    // }

    // int last=100;


    // vector < pair <int,int>  > p;
    // F(i,2,last)
    // {
    //     if(i==spf[i])p.push_back({i,i});
    // }


    // int ans=0;
    // ans+=2;
    // ans+=2*((n-1)-(f(2,2,n)));
    // ans%=M;
    // dbg(ans);
    // F(i,3,last)
    // {
    //     int start=1;
    //     for(auto &pp : p)
    //     {
    //         if(pp.X<i)
    //         {
    //             while ((pp.Y*pp.X)<i)
    //             {
    //                 // dbg(i,pp.Y);
    //                 pp.Y*=pp.X;
    //             }

    //             // dbg(pp);
    //             if(i%pp.Y)
    //             start*=pp.Y;
                
    //         }else
    //         {
    //             break;
    //         }
    //     }

    //     if(start>n)break;

    //     // if(start==2)continue;

    //     dbg(f(2,2,3));

    //     // int l=n-start+1;
    //     int x1=f(start,start,n)-f(i*start,start,n);

    //     // dbg(i,start,l,x1,ans);

    //     if(x1<0)continue;
        
    //     // l-=x1;
    //     // if(l<=0 || x1<0)break;

    //     ans+=(x1*i);
    //     ans%=M;

    //     dbg(i,start,x1,ans);

        
    // }

    // cout<<ans;
    // cout<<"\n";


    // n=2e4;
    // dbg(f(1,1,n));
    // dbg(f(1*2,1,n));

    // map<int,int> mp;

    // F(i,1,n)
    // {
    //     F(j,1,2*n+10)
    //     {
    //         if(i%j)
    //         {
    //             mp[j]++;
    //             break;
    //         }
    //     }
    // }

    // int ans2=0;

    // for(auto p : mp)
    // {
    //     dbg(p);
    //     // dbg(p.Y);

    //     ans2+=p.X*p.Y;
    //     ans2%=M;
    // }

    // cout<<ans2;cout<<"\n";

    // dbg(f(24,1,n));
    // dbg(f(60,1,n));
    
    int ans=0;
    int fact=1;
    F(i,2,100000)
    {

        
        if(fact>INF)break;
        int g=gcd(i,fact);

        int lcm=(fact*i)/g;

        int z=0;

        z+=f(fact,1,n);
        z-=f(lcm,1,n);

        z+=M;
        z%=M;

        // dbg(z,fact,lcm,i);

        ans+=(z*i)%M;
        ans%=M;

        fact=lcm;
    }

    ans-=2;
    ans+=M;
    ans%=M;

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
//	parsed : 03-July-2021 18:44:51 IST