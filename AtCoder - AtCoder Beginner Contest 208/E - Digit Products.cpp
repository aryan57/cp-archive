/*
	group : AtCoder - AtCoder Beginner Contest 208
	name : E - Digit Products.cpp
	srcPath : /home/aryan/Documents/cp/E_Digit_Products.cpp
	url : https://atcoder.jp/contests/abc208/tasks/abc208_e
*/
/*
    author : aryan57
    created : 04-July-2021 18:07:19 IST
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


// Returns count of integers having zero upto given digits
int zeroUpto(int digits)
{
    // Refer below article for details
    // https://www.geeksforgeeks.org/count-positive-integers-0-digit/
    int first = (pow(10,digits)-1)/9;
    int second = (pow(9,digits)-1)/8;
    return 9 * (first - second);
}

int toInt(char c)
{
    return c-'0';
}
 
// counts numbers having zero as digits upto a given
// number 'num'
int countZero(string num)
{
    // k denoted the number of digits in the number
    int k = sz(num);
 
    // Calculating the total number having zeros,
    // which upto k-1 digits
    int total = zeroUpto(k-1);
 
    // Now let us calculate the numbers which don't have
    // any zeros. In that k digits upto the given number
    int non_zero = 0;
    for (int i=0; i<sz(num); i++)
    {
        // If the number itself contains a zero then
        // decrement the counter
        if (num[i] == '0')
        {
            non_zero--;
            break;
        }
 
        // Adding the number of non zero numbers that
        // can be formed
        non_zero += (toInt(num[i])-1) * (pow(9,k-1-i));
    }
 
    int no = 0, remaining = 0,calculatedUpto=0;
 
    // Calculate the number and the remaining after
    // ignoring the most significant digit
    for (int i=0; i<sz(num); i++)
    {
        no = no*10 + (toInt(num[i]));
        if (i != 0)
            calculatedUpto = calculatedUpto*10 + 9;
    }
    remaining = no-calculatedUpto;
 
    // Final answer is calculated
    // It is calculated by subtracting 9....9 (d-1) times
    // from no.
    int ans = zeroUpto(k-1) + (remaining-non_zero-1);
    return ans;
}

#define ARYAN_FACT
const int mxn_fact=20;
int fact[mxn_fact+1];

void fact_init()
{
    fact[0]=1;
    for (int i=1;i<=mxn_fact;i++)
        fact[i]=i*fact[i-1];
}

int n,k;
int ans=0;
vector <int > v(10);
string nn;

void f(int p,int start)
{

    int z=0;
    F(i,2,9)z+=v[i];

    while (z<=sz(nn))
    {
        int sum=0;
        F(i,1,9)sum+=v[i];
        int tot=fact[sum];
        F(i,1,9)tot/=fact[v[i]];
        
        ans+=tot;

        if(z==sz(nn))
        {
            vector <int> vv(v);

            for(char x : nn)
            {
                F(d,x-'0'+1,9)
                {
                    if(vv[d]<=0)continue;
                    vv[d]--;

                    int sum=0;
                    F(i,1,9)sum+=vv[i];
                    int tot=fact[sum];
                    F(i,1,9)tot/=fact[vv[i]];

                    ans-=tot;


                    vv[d]++;
                }

                if(vv[x-'0']<=0)break;
                vv[x-'0']--;
            }
        }

        v[1]++;
        z++;
    }

    v[1]=0;

    F(j,start,9)
    {
        int pww=j;
        int z=1;
        while (pww<=k && p*pww<=k)
        {
            v[j]+=z;
            f(p*pww,j+1);
            v[j]-=z;


            pww*=j;
            z++;
        }
    }
    
}

// void f2()
// {

//     int z=2;
//     while (z<sz(nn))
//     {
//         ans+=9*((int)pow(10,z-1)-(int)pow(9,z-1));
//         z++;
//     }
//     z=sz(nn);
//     F(i,0,z-1)
//     {
//         if(i==0)
//         {
//             ans+=(nn[i]-'1')*((int)pow(10,z-i-1)-(int)pow(9,z-i-1));
            
//         }
//         else
//         {
//             if(nn[i]=='0')continue;
//             ans+=(nn[i]-'1')*((int)pow(10,z-i-1)-(int)pow(9,z-i-1));
//             ans+=(1)*((int)pow(10,z-i-1));
//         }

//         dbg(i,ans);
//     }

//     ans++;
    
// }


void solve_LOG()
{
    
    cin>>n>>k;
    nn = to_string(n);
    // f2();
    // dbg(ans);
    f(1,2);
    ans+=countZero(nn);
    cout<<ans-1;
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
//	parsed : 04-July-2021 17:34:52 IST