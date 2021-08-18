/*
	group : HackerRank - Testing 1622293244
	name : Personalized Typewriter.cpp
	srcPath : /home/aryan/Documents/cp/Personalized_Typewriter.cpp
	url : https://www.hackerrank.com/contests/testing-1622293244/challenges/personalized-typewriter
*/
/*
    author : aryan57
    created : 16-July-2021 15:14:30 IST
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


/* 
    dsu d(int n)
    // It creates an undirected graph with n vertices and 0 edges.
    // 0<=n<=1e8
    // O(n)

    int d.merge(int a, int b)
    // It adds an edge (a, b)
    // If the vertices a and b were in the same connected component, it returns the representative of this connected component. Otherwise, it returns the representative of the new connected component.
    // 0<=a<n   0<=b<n
    // O(alpha(n)) amortized

    bool d.same(int a, int b)
    // Returns whether the vertices a and b are in the same connected component
    // 0<=a<n   0<=b<n
    // O(alpha(n)) amortized

    int d.leader(int a)
    // Returns the representative of the connected component that contains the vertex a
    // 0<=a<n
    // O(alpha(n)) amortized

    int d.size(int a)
    // Returns the size of the connected component that contains the vertex a.
    // 0<=a<n
    // O(alpha(n)) amortized

    vector<vector<int>> d.groups()
    // Returns the list of the "list of the vertices in a connected component"
    // O(n)
*/
struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

int f(string t,string s)
{
    int dis[26][26]={};
    F(i,0,sz(t)-1)
    {
        F(j,i+1,sz(t)-1)
        {
            dis[t[i]-'a'][t[j]-'a']=j-i;
            dis[t[j]-'a'][t[i]-'a']=j-i;
        }
    }

    int ans=0;

    F(i,1,sz(s)-1)
    {
        ans+=dis[s[i]-'a'][s[i-1]-'a'];
    }

    return ans;
}

struct node
{
    char c;
    int mn=-INF;
    int mx=INF;

};


void solve_LOG()
{
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;

    vector< vector<int> > v(m);
    F(i,0,m-1)
    {
        v[i].push_back({i});
    }


    int cnt[m][m]={};
    F(i,1,n-1)
    {
        int mn=min(s[i]-'a',s[i-1]-'a');
        int mx=max(s[i]-'a',s[i-1]-'a');
        cnt[mn][mx]++;
    }

    set<pair <int,pair <int,int>  >> ss; 

    F(i,0,m-1)
    {
        F(j,i+1,m-1)
        {
            if(cnt[i][j])ss.insert({-cnt[i][j],{i,j}});
        }
    }

    // dbg(ss);

    for(auto it = ss.begin();it!=ss.end();it++)
    {
        auto z=*it;
        int x = z.Y.X;
        int y = z.Y.Y;

        // dbg(x,y);

        int rx=-1;
        int cx=-1;
        int ry=-1;
        int cy=-1;

        for(int i=0;i<sz(v);i++)
        {
            for(int j=0;j<sz(v[i]);j++)
            {
                if(v[i][j]==x)
                {
                    rx=i;
                    cx=j;
                }
                if(v[i][j]==y)
                {
                    ry=i;
                    cy=j;
                }
            }
        }

        if(rx==ry)continue;

        // x...y
        vector <int> d1=v[rx];
        d1.insert(d1.end(),all(v[ry]));
        vector <int> d2=v[ry];
        d2.insert(d2.end(),all(v[rx]));

        int dist1[m][m]={};
        F(i,0,sz(d1)-1)
        {
            F(j,i+1,sz(d1)-1)
            {
                dist1[d1[i]][d1[j]]=j-i;
                dist1[d1[j]][d1[i]]=j-i;
            }
            
        }
        int dist2[m][m]={};
        F(i,0,sz(d2)-1)
        {
            F(j,i+1,sz(d2)-1)
            {
                dist2[d2[i]][d2[j]]=j-i;
                dist2[d2[j]][d2[i]]=j-i;
            }
            
        }

        int c1=0;
        int c2=0;

        for(auto it2=it;it2!=ss.end();it2++)
        {
            auto z=*it2;
            int x = z.Y.X;
            int y = z.Y.Y;

            c1+=dist1[x][y];
            c2+=dist2[x][y];
        }

        if(c1<c2)
        {
            v[rx].insert(v[rx].end(),all(v[ry]));
            v[ry].clear();
        }else
        {
            v[ry].insert(v[ry].end(),all(v[rx]));
            v[rx].clear();
        }

        // dbg(x,y,rx,ry,cx,cy,d1,d2);
        // dbg(v);
    }
    // dbg(v);
    string t="";

    for(int i=0;i<sz(v);i++)
    {
        for(int j=0;j<sz(v[i]);j++)
        {
            t+=v[i][j] + 'a';
        }
    }

    // dbg(t);

    // t="ecbad";

    cout<<f(t,s);
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
//	parsed : 16-July-2021 14:59:10 IST