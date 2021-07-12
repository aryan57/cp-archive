/*
	group : local
	name : c2.cpp
	srcPath : /home/aryan/Documents/cp/c2.cpp
	url : /home/aryan/Documents/cp/c2.cpp
*/
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi;

void show_vi(vector<int> t){
    // //cout<<"show_vi"<<endl;
    for(int i = 0;i<t.size();i++){
        cout<<t[i]<<",";
    }
    cout<<endl;
}


vector<int> solve(int N,vector<int> A,int Q,vector<vector<int>> Query){

    // Part 1 start
    bool b = 1;
    vvi B;
    vector<int> umap;
    vector<int> ans;
    for(int i = 0;i<A.size();i++){
        B.push_back({A[i],i});
    }
    sort(B.begin(), B.end());
    umap.resize(B.size());
    for(int i = 0;i<B.size();i++){
        umap[B[i][1]] = i;
    }
    vi pref(B.size()+1);
    for(int i = 0;i<B.size();i++){
        pref[i+1] = pref[i]+B[i][0];
    }

    // part 1 end
    for(int i = 0;i<Q;i++){
        int l = Query[i][1];
        int C = Query[i][0];
        vvi t;
        for(int j = 2;j<2+l;j++){
            t.push_back({A[Query[i][j]-1],Query[i][j]-1});
        }
        sort(t.begin(), t.end());
        // part 2  start
        auto id = upper_bound(pref.begin(), pref.end(),C) - pref.begin();
        // part 2 end
        id--;
        int left = C-pref[id];
        id++;
        int cnt = 0;
        vector<int> s(t.size());
        // part 3 start
        while(1){
            while(id<pref.size()&&left>=A[B[id-1][1]]){
                left-=A[B[id-1][1]];
                id++;
            }
            int j = 0;
            for(;j<t.size();j++){
                if(umap[t[j][1]]<(id-1)&&s[j]==0){
                    left+=A[t[j][1]];
                    s[j] = 1;
                    cnt++;
                    break;
                }
            }
            if(j==t.size()){
                break;
            }
        }
        // part 3 end
       ans.push_back(id-1-cnt);
    }
    return ans;
}


int main(){
    vi A = {7,3,6,8,2,1,4,9,5,10};
    vvi Q = {
            {10,2,2,5},
            {15,1,1},
            {20,3,1,2,3},
            {100,0}
        };
    show_vi(solve(A.size(),A,Q.size(),Q));
    return 0;
}