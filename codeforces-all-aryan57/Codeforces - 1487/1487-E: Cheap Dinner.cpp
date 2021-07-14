//https://codeforces.com/contest/1487/problem/E

/*
    author : Aryan Agarwal, IIT KGP
    created : 15-February-2021 23:07:19 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 150000;
const int mxm = 200000;
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

struct segtree{

    // for getting range [L,R], PASS [L,R+1],

    // any segment of l...r is [l,r)
    // 'r' is not included in any segmented
    // This segment tree is configured for min of a range, change according to your needs
     
    int size;
    vector <int>  arr;
 
    void init(int n){
        size=1;
        while(size<n)size*=2;
 
        arr.assign(2*size,0);
    }
 
    // always pass 0 based index 'i'
    // 'v' will be the final value of the element
    void set(int i, int v,int x,int lx,int rx){
        if(rx-lx==1){
            arr[x]=v;
            return;
        }
 
        int mid=(lx+rx)/2;
 
        if(i<mid){
            set(i,v,2*x+1,lx,mid);
        }
        else{
            set(i,v,2*x+2,mid,rx);
        }
 
        arr[x]=min(arr[2*x+1],arr[2*x+2]);
    }
 
    void set(int i, int v){
        set(i,v,0,0,size);
    }

    // always pass 0 based indexes of left & right [l,r)
    // 'x' is the current index
    // [lx,rx) is the current range
    // [l,r) is the final range

    int range(int l,int r,int x,int lx,int rx){
        if(l>=rx || r<=lx)return INF;
        if(lx>=l && rx<=r)return arr[x];
 
        int mid=(lx+rx)/2;
 
        int s1=range(l,r,2*x+1,lx,mid);
        int s2=range(l,r,2*x+2,mid,rx);
 
        return min(s1,s2);
 
    }
 
    int range(int l,int r){
        return range(l,r,0,0,size);
    }

    // https://codeforces.com/edu/course/2/lesson/4
    // https://cp-algorithms.com/data_structures/segment_tree.html
 
};

void solve_LOG()
{
    int n[4];

    F(i,0,3)cin>>n[i];

    vector <vector <int> > v(4,vector <int> (mxn));

    F(i,0,3)
    {
        F(j,0,n[i]-1)
        {
            cin>>v[i][j];
        }
    }

    int mm[3];
    vector <vector <pair <int,int> > > m(3,vector <pair <int,int> > (mxm));

    F(i,0,2)
    {
        cin>>mm[i];
        F(j,0,mm[i]-1)
        {
            cin>>m[i][j].X;
            cin>>m[i][j].Y;
            --m[i][j].X;
            --m[i][j].Y;
        }
    }

    vector <vector <int> > val(4,vector <int> (mxn,0));
    F(i,0,n[3]-1)
    {
        val[3][i]=v[3][i];
    }

    RF(i,2,0)
    {
        vector <set<int>> s(n[i]);

        F(j,0,mm[i]-1)
        {
            s[m[i][j].X].insert(m[i][j].Y);
        }

        vector<pair<int,int> > vv(n[i+1]);
        F(j,0,n[i+1]-1)
        {
            vv[j]={val[i+1][j],j};
        }

        sort(all(vv));

        vector <int> idx(n[i+1]);

        F(j,0,n[i+1]-1)
        {
            idx[j]=vv[j].Y;
        }


        fill(all(val[i]),INF);

        int last=0;
        while(last<n[i])
        {
            F(k,0,n[i+1]-1)
            {
                if(s[last].find(idx[k])==s[last].end())
                {
                    val[i][last]=val[i+1][idx[k]];
                    // if(i==1)dbg(last,idx[k]);
                    break;
                }
            }
            last++;
        }

        F(j,0,n[i]-1)
        {
            val[i][j]+=v[i][j];
            // dbg(val[i][j],i);
        }


    }

    int mnn=INF;

    F(i,0,n[0]-1)
    {
        mnn=min(mnn,val[0][i]);
    }

    // dbg(mnn);

    if(mnn>=INF)cout<<"-1\n";
    else cout<<mnn;

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