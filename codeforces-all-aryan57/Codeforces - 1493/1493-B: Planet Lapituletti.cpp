//https://codeforces.com/contest/1493/problem/B

/*
    author : Aryan Agarwal, IIT KGP
    created : 06-March-2021 19:55:13 IST
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

void solve_LOL()
{
    int h,m;
    cin>>h>>m;

    string s;
    cin>>s;

    int H,M;

    H= stoi(s.substr(0,2));
    M= stoi(s.substr(3,2));

    while (true)
    {
        bool ok = true;

        string z="";

        if(H<10)z+='0'+to_string(H);
        else z+=to_string(H);

        z+=':';

        if(M<10)z+='0'+to_string(M);
        else z+=to_string(M);

        

        for(char x :z)
        {
            if(x=='3')ok=false;
            if(x=='4')ok=false;
            if(x=='6')ok=false;
            if(x=='7')ok=false;
            if(x=='9')ok=false;
        }

        string z1=z;
        reverse(all(z1));
        for(int i=0;i<sz(z1);i++)
        {
            if(z1[i]=='2')z1[i]='5';
            else if(z1[i]=='5')z1[i]='2';
        }

        // dbg(z,z1);

        int H1,M1;

        H1= stoi(z1.substr(0,2));
        M1= stoi(z1.substr(3,2));

        if(H1>=h || M1>=m)
        {
            ok=false;
        }

        // if(z[0]=='0' && z[4]!='0')ok=false;
        // if(z[0]=='1' && z[4]!='1')ok=false;
        // if(z[0]=='2' && z[4]!='5')ok=false;
        // if(z[0]=='5' && z[4]!='2')ok=false;
        // if(z[0]=='8' && z[4]!='8')ok=false;

        // if(z[1]=='0' && z[3]!='0')ok=false;
        // if(z[1]=='1' && z[3]!='1')ok=false;
        // if(z[1]=='2' && z[3]!='5')ok=false;
        // if(z[1]=='5' && z[3]!='2')ok=false;
        // if(z[1]=='8' && z[3]!='8')ok=false;

        if(ok)
        {
            cout<<z;
            cout<<"\n";
            return;
        }

        int carry=0;

        if(M==m-1)
        {
            M=0;
            carry++;

        }else
        {
            M++;
        }

        H+=carry;
        H%=h;

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
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}