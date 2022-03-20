/*
	group : local
	name : convex-hull.cpp
	srcPath : /home/aryan/Dropbox/Documents from PC/free/convex-hull/convex-hull.cpp
	url : /home/aryan/Dropbox/Documents from PC/free/convex-hull/convex-hull.cpp
*/
/*
	convex hull of given points in O(nlogn)
	where O(nlogn) time is taken in sorting
	and O(n) for calculating the hull
*/
#include <bits/stdc++.h>
using namespace std;

struct Point
{
	int x,y;
	Point(int _x=0,int _y=0){
		x=_x;
		y=_y;
	}
};

// orientation = 1 , means the ordered Points (a,b,c) make a clockwise turn
// orientation = -1 , means the ordered Points (a,b,c) make an anti-clockwise turn
// orientation = 0 , means the ordered Points (a,b,c) are in a straight line
int get_orientation(Point a,Point b,Point c){
	/*
		m1 = (by-ay)/(bx-ax)
		m2 = (cy-by)/(cx-bx)

		m1 - m2 = ((cx-bx)*(by-ay) - (bx-ax)*(cy-by))/((bx-ax)*(cx-bx))

		if m1-m2 = 0 , straight line 
		if m1-m2 = -ve , anti-clock 
		if m1-m2 = +ve , clock 
	*/

	int delta = (c.x-b.x)*(b.y-a.y) - (b.x-a.x)*(c.y-b.y);
	if(delta<0)delta=-1;
	if(delta>0)delta=1;
	return delta;
}

vector<Point> convex_hull(vector<Point> v){

	if(v.size()<=2)return v;

	auto dist = [](Point a,Point b)->bool{
		return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
	};
	
	// first sort the points to get lowermost,leftmost point
	sort(v.begin(),v.end(),[](const Point &a,const Point &b)->bool{
		if(a.y!=b.y)return a.y<b.y;
		return a.x<b.x;
	});
	Point corner = v[0];
	sort(v.begin(),v.end(),[&](const Point &a,const Point &b)->bool{
		int dir = get_orientation(corner,a,b);
		if(dir==-1)return true; // anticlock , ok
		if(dir==1)return false; // clock, so b will be before a
		
		// now since the points a and b are colinear with the corner point we can check the distance
		// points having same polar order are sorted in terms of distance from corner point
		return (dist(corner,a)<dist(corner,b));
	});

	// now all the points are sorted in the anticlockwise sense wrt corner point
	// i.e., sorted in polar order around the corner point
	vector<Point> new_points;
	new_points.push_back(corner);
	for(int i=1;i<v.size();i++){
		// since some points have same polar order, take only the one which is farthest from the corner point
		while (i+1<v.size() && get_orientation(corner,v[i],v[i+1])==0)i++;
		new_points.push_back(v[i]);
	}

	vector<Point> res;
	if(new_points.size()<3){
		// a closed figure requires atleast 3 points
		// so convex-hull impossible
		for(Point p : new_points)res.push_back(p);
		return res;
	}

	// do push pop according to graham's algo
	stack<Point> s;
	s.push(new_points[0]); 
	s.push(new_points[1]); 
	s.push(new_points[2]);

	for(int i=3;i<new_points.size();i++){
		while (s.size()>=2)
		{
			Point last = s.top();
			s.pop();
			Point second_last = s.top();
			s.push(last);

			int dir = get_orientation(second_last,last,new_points[i]);

			if(dir!=-1)s.pop();
			else break;
		}
		s.push(new_points[i]);
	}

	while (!s.empty())
	{
		res.push_back(s.top());
		s.pop();
	}
	reverse(res.begin(),res.end()); // to get points in clockwise sense
	return res;
}

int main()
{
	int x,y;
	vector<Point> v;
	while (cin>>x>>y)
	{
		v.push_back(Point(x,y));
	}
	vector<Point> ans = convex_hull(v);
	for(Point p : ans){
		cout<<p.x<<", "<<p.y<<"\n";
	}
	return 0;
}