/**
 *    author:  Aryan Agarwal
 *    created: 18.06.2022 15:02:00 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void solve()
{
    int n,k;
    cin>>n>>k;

    vector <string> v(n);
    for(auto &x : v)cin>>x;
    string ok;
    cin>>ok;

    auto f = [&](int bad)->int{
        return bad + 5*((bad-1)/k);
    };

    int less=0;
    int equal=0;

    int good=0;
    for(int i=0;i<n;i++){
        if(v[i]==ok)good++;
    }
    assert(good==1);

    for(int i=0;i<n;i++){
        if(v[i].size()<ok.size())less++;
        else if(v[i].size()==ok.size())equal++;
    }

    int best = f(less+1);
    int worst=f(less+equal);

    cout<<best<<" "<<worst<<"\n";

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t=1;
    cin>>_t;
    for (int i=1;i<=_t;i++){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}