/*
	group : DMOJ - COCI '14 Contest 6
	name : #2 - Niko.cpp
	srcPath : /home/aryan/Desktop/_2_Niko.cpp
	url : https://dmoj.ca/problem/coci14c6p2
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.02.2022 01:22:19 IST
**/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int q;
	cin>>q;

	vector<vector <int> > vec(q);
	for(int i=0;i<q;i++){
		string s;
		cin>>s;
		s+='-';
		string temp="";
		for(char c : s){
			if(c=='-'){
				vec[i].push_back(stoi(temp));
				temp="";
			}else{
				temp+=c;
			}
		}
	}

	int m;
	cin>>m;

	int o=0,v=0,n=0,on=0,vn=0,ov=0,ovn=0;

	while (m--)
	{
		string s;
		cin>>s;
		sort(s.begin(),s.end());
		if(s=="O")o++;
		if(s=="V")v++;
		if(s=="N")n++;

		if(s=="NO")on++;
		if(s=="NV")vn++;
		if(s=="OV")ov++;

		if(s=="NOV")ovn++;
	}
	
	for(int i=0;i<q;i++){
		

		bool ok = false;

		for(int a=0;a<=on && !ok;a++){
			for(int b=0;b<=vn && !ok;b++){
				for(int c=0;c<=ov && !ok;c++){

					int reqo=vec[i][0];
					int reqv=vec[i][1];
					int reqn=vec[i][2];
					
					reqo-=min(reqo,o);
					reqn-=min(reqn,n);
					reqv-=min(reqv,v);

					reqo-=min(reqo,a);
					reqv-=min(reqv,b);
					reqo-=min(reqo,c);

					reqn-=min(reqn,on-a);
					reqn-=min(reqn,vn-b);
					reqv-=min(reqv,ov-c);

					if(reqo+reqn+reqv<=ovn){
						cout<<"DA\n";
						ok=true;
					}
				}
			}
		}

		if(!ok)cout<<"NE\n";
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 15-February-2022 01:22:03 IST