/*
	group : CodeChef - June Cook-Off 2021 Division 2
	name : Too Much Xor.cpp
	srcPath : /home/aryan/Documents/cp/Too_Much_Xor.cpp
	url : https://www.codechef.com/COOK130B/problems/TOOXOR
*/
/*
    author : aryan57
    created : 20-June-2021 21:52:00 IST
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

struct str
{
    int a,b,c;
};


void solve_LOL()
{
    int n;
    cin>>n;

    vector <int> a(n);
    set<int> s;
    bool ok = true;
    F(i,0,n-1)
    {
        cin>>a[i];
        s.insert(a[i]);

        if(i-2>=0 && a[i-2]!=a[i])ok=false;
    }

    if(n>1 && a[0]==a[1] && ok)ok=false;

    if(n==1 || ok)
    {
        cout<<0;
        cout<<"\n";
        return;
    }
    if(n==2)
    {
        cout<<(a[0]!=a[1]?0:-1);
        cout<<"\n";
        return;
    }
    if(n==3)
    {

        vector <int> v;
        v.push_back(0);
        F(i,1,3)
        {
            v.push_back(a[i-1]);
        }

        if(v[2]==0)
        {
            if(v[1])
            {
                cout<<"1\n";
                cout<<"1 2 3\n";
                return;
            }
            if(v[3])
            {
                cout<<"1\n";
                cout<<"3 2 1\n";
                return;
            }

            cout<<"-1\n";
            return;
        }
        else
        {
            if(v[1]==v[3])
            {
                if(v[1])
                {
                    cout<<"1\n";
                    cout<<"1 3 2\n";
                    return;
                }
                else
                {
                    cout<<"0\n";
                    return;
                }
            }
            cout<<"-1\n";
            return;
        }

    }

    vector <str> ans;
    if(sz(s)==1)
    {
        if(a[0]==0)
        {
            cout<<"-1\n";
            return;
        }

        str z;
        z.a=1;
        z.b=3;
        for(int i=2;i<=n;i+=2)
        {
            z.c=i;
            ans.push_back(z);
        }

        cout<<sz(ans);
        cout<<"\n";
        for(auto z : ans)
        {
            cout<<z.a<<" "<<z.b<<" "<<z.c<<"\n";
        }
        return;
    }

    unordered_map<int,int> last;
    int p=-1;
    int q=-1;

    for(int i=3;i<=n;i++)
    {
        if(i%2)
        {
            if(a[i-1]!=a[1-1])
            {
                p=1;
                q=i;
                break;
            }
        }
        else
        {
            if(a[i-1]!=a[2-1])
            {
                p=2;
                q=i;
                break;
            }

        }
    }


    assert(p!=-1 && q!=-1 && a[p-1]!=a[q-1]);

    
    F(i,1,n)
    {
        if(i%2!=p%2)
        {
            str z;
            z.a=p;
            z.b=q;
            z.c=i;
            ans.push_back(z);
        }
    }

    F(i,1,n)
    {
        if(i%2==p%2)
        {
            str z;
            if(p==1)
            {
                z.a=2;
                z.b=4;
            }
            else
            {
                z.a=1;
                z.b=3;
            }
            z.c=i;
            ans.push_back(z);
        }
    }


    cout<<sz(ans);
    cout<<"\n";
    for(auto z : ans)
    {
        cout<<z.a<<" "<<z.b<<" "<<z.c<<"\n";
    }
    

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
//	parsed : 20-June-2021 21:37:25 IST