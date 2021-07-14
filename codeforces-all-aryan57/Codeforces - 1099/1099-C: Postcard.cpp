//https://codeforces.com/contest/1099/problem/C

/*
    author : Aryan Agarwal, IIT KGP
    created : 05-January-2021 14:57:08 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007; /*more than 1e9 */ /*7 + 1e9*/
// const int32_t M = 998244353; /*less than 1e9 */   /*1 + 7*17*(1<<23) */
const long double pie = acos(-1);

#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

void solve_LOG()
{
    string s;
    cin>>s;

    int n=sz(s);

    int k;
    cin>>k;

    int c=0,f=0,t=0;

    F(i,0,n-1)
    {
        if(s[i]=='*')f++;
        if(s[i]=='?')c++;
        if(s[i]!='?' && s[i]!='*')t++;
    }

    if(f==0)
    {
        if(k>=t-c && k<=t)
        {
            int cnt=t-k;
            int ind=0;
            string ans(k,'$');

            F(i,0,n-1)
            {
                if(s[i]=='?')
                {
                    if(cnt){ind--;cnt--;}
                }
                else
                {
                    ans[ind]=s[i];
                    ind++;
                }
                
            }

            cout<<ans;
            return;
        }
        
        cout<<"Impossible";
        return;
           
    }

    if(k<t-c-f)
    {
        cout<<"Impossible";
        return;
    }

    if(k<=t)
    {
        int cnt=t-k;
        int ind=0;
        string ans(k,'$');

        F(i,0,n-1)
        {
            if(s[i]=='?' || s[i]=='*')
            {
                if(cnt){ind--;cnt--;}
            }
            else
            {
                ans[ind]=s[i];
                ind++;
            }
            
        }

        cout<<ans;
        return;
    }

    bool ok =false;
    int ind=0;
    int pos =-1;
    string ans(k,'$');

    F(i,0,n-1)
    {
        if(s[i]=='?')
        {
            ind--;
            ans[ind]='$';
        }
        else if(s[i]=='*')
        {
            if(!ok)
            {
                pos=ind-1;
                ok=true;
            }else
            {
                ind--;
                ans[ind]='$';
            }
            
        }
        else
        {
            ans[ind]=s[i];
            ind++;
        }
        
    }

    string x="",y="";
    int cnt=0;

    F(i,0,k-1)
    {
        if(ans[i]=='$')
        {
            cnt=k-1-i+1;
            break;
        }

        if(i<=pos)
        {
            x+=ans[i];
        }
        else
        {
            y+=ans[i];
        }
        
    }

    // dbg(x,y,cnt);

    x=x+string(cnt,x[sz(x)-1]);

    cout<<x+y;

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
    // defualt mxn_sieve = 1e5
    sieve();
#endif
#ifdef ARYAN_SEG_SIEVE
    // default [L,R] = [1,1e5]
    segmented_sieve();
#endif
#ifdef ARYAN_FACT
    // default mxn_fact = 1e5
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