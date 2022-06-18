/**
 *    author:  Aryan Agarwal
 *    created: 18.06.2022 15:02:00 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,k;
    cin>>n>>k;

    vector <string> v(n);
    for(auto &x : v)cin>>x;
    string ok;
    cin>>ok;

	set<string> xx(v.begin(),v.end());
	v.clear();
	for(auto s : xx){
		v.push_back(s);
	}


    auto f = [&]()->int{
        int time=0;
        int wrong=0;
        for(int i=0;i<n;i++){
            time++;
            if(v[i]==ok){
                break;
            }
            wrong++;
            if(wrong==k){
                time+=5;
                wrong=0;
            }
        }
        return time;
    };

    sort(v.begin(),v.end(),[&ok](const string &a,const string &b){
        if(a.size()!=b.size())return a.size()<b.size();
        if(a==ok)return true;
        return false;
    });

    int best = f();

    sort(v.begin(),v.end(),[&ok](const string &a,const string &b){
        if(a.size()!=b.size())return a.size()<b.size();
        if(a==ok)return false;
        return true;
    });

    int worst=f();

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