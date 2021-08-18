/*
	group : Codeforces - Codeforces Round #705 (Div. 2)
	name : C. K-beautiful Strings.cpp
	srcPath : /home/aryan/Documents/cp/C_K_beautiful_Strings.cpp
	url : https://codeforces.com/problemset/problem/1493/C
*/
/*
    author : aryan57
    created : 05-June-2021 19:16:35 IST
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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    if(n%k)
    {
        cout<<"-1\n";
        return;
    }

    string ans="";
    int cnt[26]={};
    string zz="";
    vector<int> kmods(26);
    F(i,0,n-1)
    {

        F(z,s[i]-'a'+1,25)
        {
            int tempcnt[26]={};
            int tot=0;
            tempcnt[z]++;
            F(j,0,25)
            {

                tempcnt[j]+=cnt[j];
                int rem=tempcnt[j]%k;
                if(rem>0)tempcnt[j]+=k-rem;
                tot+=tempcnt[j];
            }

            if(tot>n)continue;

            tempcnt[0]+=n-tot;

            ans=zz;
            ans+='a'+z;
            tempcnt[z]--;

            F(j,0,25)
            {
                ans+=string(tempcnt[j]-cnt[j],'a'+j);
            }
            break;

        }
        cnt[s[i]-'a']++;
        zz+=s[i];
        if(cnt[s[i]-'a']%k==0)kmods[s[i]-'a']=0;
        else kmods[s[i]-'a']=1;
    }

    if(accumulate(all(kmods),0)==0)
    {
        cout<<s;
        cout<<"\n";
        return;
    }

    if(ans.empty())
    {
        cout<<"-1\n";
        return;
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
//	parsed : 05-June-2021 19:04:34 IST