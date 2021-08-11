/*
	group : CodeChef - August Challenge 2021 Division 2 (Unrated)
	name : Geometry 1.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Geometry_1.cpp
	url : https://www.codechef.com/AUG21B/problems/GEO1
*/
/**
 *    author:  Aryan Agarwal
 *    created: 11.08.2021 00:40:00 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

struct point{
	int x,y;
};

long double area(const vector<point>& fig) {
    long double res = 0;
    for (unsigned i = 0; i < fig.size(); i++) {
        point p = i ? fig[i - 1] : fig.back();
        point q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return fabs(res) / 2;
}

void solve()
{
	int n,q;
	cin>>n>>q;

	vector<point> fig(n);
	for(int i=0;i<n;i++){
		cin>>fig[i].x>>fig[i].y;
	}

	long double Area=area(fig);
	long double Perimeter=0.0;
	long double X1=0.0;
	long double X2=0.0;

	vector<long double> d(n);

	for(int i=0;i<n;i++){
		
		d[i] = sqrt(
				(fig[(i+1)%n].y-fig[i].y)*(fig[(i+1)%n].y-fig[i].y)
				+
				(fig[(i+1)%n].x-fig[i].x)*(fig[(i+1)%n].x-fig[i].x)
				);
		
		Perimeter+=d[i];
	}

	for(int i=0;i<n;i++){

		int x1=fig[i].x;
		int x2=fig[(i+1)%n].x;
		int x3=fig[(i+2)%n].x;
		int y1=fig[i].y;
		int y2=fig[(i+1)%n].y;
		int y3=fig[(i+2)%n].y;

		long double a=0.0;
		a+=x1*(y2-y3);
		a+=x2*(y3-y1);
		a+=x3*(y1-y2);

		a=fabs(a);

		long double sintheta = a/(d[i]*d[(i+1)%n]);

		long double costheta = ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3) - (x3-x1)*(x3-x1) - (y3-y1)*(y3-y1))/(2*d[i]*d[(i+1)%n]);

		X1+=sintheta;
		X2+=((1+costheta)*(1+costheta))/sintheta;

	}
	while(q--){
		int v,t;
		cin>>v>>t;
		int d=v*t;

		long double ans=0.0;

		ans+=Area;
		ans+=d*Perimeter;
		ans+=d*d*X1*0.5;
		ans+=d*d*X2*0.5;

		cout<<ans<<"\n";
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout<<fixed<<setprecision(10);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 10-August-2021 23:35:56 IST