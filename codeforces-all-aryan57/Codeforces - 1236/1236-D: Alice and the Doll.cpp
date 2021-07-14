//https://codeforces.com/contest/1236/problem/D

/*
    author : aryan57
    created : 24-June-2021 15:40:25 IST
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
    int n,m;
    cin>>n>>m;

    vector<pair<int,int> > block;

    // int g[n][m]={};
    

    int k;
    cin>>k;
    int tot=n*m;

    F(i,1,k)
    {
        int x,y;
        cin>>x>>y;
        // g[x-1][y-1]=1;
        block.push_back({x,y});
        tot--;
    }

    // F(i,0,n-1)
    // {
    //     F(j,0,m-1)
    //     {
    //         cout<<(g[i][j]?'#':'*');
    //     }cout<<"\n";
    // }

    F(j,0,m+1)
    {
        block.push_back({0,j});
        block.push_back({n+1,j});
    }
    F(i,1,n)
    {
        block.push_back({i,0});
        block.push_back({i,m+1});
    }

    vector <int> row[n+2];
    vector <int> col[m+2];

    for(auto p : block)
    {
        row[p.X].push_back(p.Y);
        col[p.Y].push_back(p.X);
    }

    F(i,0,n+1)sort(all(row[i]));
    F(j,0,m+1)sort(all(col[j]));

    int x=1;
    int y=1;

    vector <int> hx={0,1,0,-1};
    vector <int> hy={1,0,-1,0};
    int d=0;
    pair <int,int> rr={0,n+1};
    pair <int,int> cc={0,m+1};
    tot--;
    while(tot>=0)
    {
        // dbg(x,y,tot);
        // dbg(rr,cc);

        bool ok=false;

        F(k,0,3)
        {
            int new_d=(d+k)%4;
            if((new_d-d)%2==0 && new_d!=d)continue;

            int r=-1;
            int c=-1;

            if(hy[new_d]==1)
            {
                auto it=upper_bound(all(row[x]),y);
                r=x;
                c=(*it)-1;
                c=min(c,cc.Y-1);
                if(c<=y)continue;
            }
            else if(hy[new_d]==-1)
            {
                auto it=upper_bound(all(row[x]),y);
                it--;
                r=x;
                c=(*it)+1;
                c=max(c,cc.X+1);
                if(c>=y)continue;
                
            }
            else if(hx[new_d]==1)
            {
                auto it=upper_bound(all(col[y]),x);
                r=(*it)-1;
                c=y;
                r=min(r,rr.Y-1);
                if(r<=x)continue;
            }
            else if(hx[new_d]==-1)
            {
                auto it=upper_bound(all(col[y]),x);
                it--;
                r=(*it)+1;
                c=y;
                r=max(r,rr.X+1);
                if(r>=x)continue;
            }

            
            
                tot-=abs(x-r)+abs(y-c);
                x=r;
                y=c;
                ok=true;
                d=new_d;

                if(hy[new_d]==1)
                {
                    rr.X=r;
                }
                else if(hy[new_d]==-1)
                {
                    rr.Y=r;
                    
                }
                else if(hx[new_d]==1)
                {
                    cc.Y=c;
                }
                else if(hx[new_d]==-1)
                {
                    cc.X=c;
                }
                break;
            
        }

        // dbg(x,y);
        // dbg(rr,cc);

        if(!ok)
            break;
    }

    assert(tot>=0);

    cout<<(tot==0?"Yes":"No");
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
//	parsed : 24-June-2021 14:30:24 IST