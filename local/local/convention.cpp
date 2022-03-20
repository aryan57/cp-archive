/*
	group : local
	name : convention.cpp
	srcPath : /home/aryan/Dropbox/Documents from PC/free/darwin/15-feb/convention.cpp
	url : /home/aryan/Dropbox/Documents from PC/free/darwin/15-feb/convention.cpp
*/
/*
	group : USACO - USACO 2018 December Contest, Silver
	name : Problem 2. Convention II.cpp
	srcPath : /home/aryan/Desktop/Problem_2_Convention_II.cpp
	url : http://usaco.org/index.php?page=viewproblem2&cpid=859
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.02.2022 02:05:55 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

struct cow
{
	int seniority,arrival,taken;
};

struct cmp {
	bool operator()(const cow& x, const cow& y) const { return x.seniority < y.seniority; }
};

void solve()
{
	// freopen("convention2.in","r",stdin);
	// freopen("convention2.out","w",stdout);
	int n;
	cin>>n;
	vector<cow> v(n);
	int T=1e9;
	for(int i=0;i<n;i++){
		v[i].seniority=n-i;
		cin>>v[i].arrival>>v[i].taken;
		T=min(T,v[i].arrival);
	}
	sort(v.begin(),v.end(),[](const cow &a,const cow &b)->bool{
		return a.arrival<b.arrival;
	});
	priority_queue<cow,vector<cow>,cmp> pq;
	int ind=0;
	int ans=0;
	while (true)
	{
		while (ind<n && v[ind].arrival<=T)
		{
			pq.push(v[ind]);
			ind++;
		}
		if(pq.empty())break;
		ans=max(ans,T-pq.top().arrival);
		T+=pq.top().taken;
		pq.pop();
	}
	cout<<ans<<endl;
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
//	parsed : 15-February-2022 02:05:42 IST


/*

#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
const int maxn = 1e5 + 5;
typedef pair<int, pi> pii;

int n, ans = 0;
pii cows[maxn]; // {arrival, {seniority, eat time} }
pi seniorityToCow[maxn];

signed main() {
    //freopen("convention2.in", "r", stdin);
    //freopen("convention2.out", "w", stdout);
    cin >> n;
    for (int i=0; i <n; i++) {
        int a,t; cin >> a >> t;
        cows[i] = {a, {i, t}};
        seniorityToCow[i] = {a,t};
    }
    sort(cows, cows+n);
    int lastTime = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i=0; i <n; i++) {
        int a = cows[i].F, s = cows[i].S.F, t = cows[i].S.S;
        if (a <= lastTime) pq.push({lastTime, {s, t}});
        else {pq.push({a, {s, t}}); lastTime = max(lastTime, a+t);}

    }
    int currTime = 0;
    while (!pq.empty()) {
        pii c = pq.top(); pq.pop();
        //cout << currTime << endl;
        //cout << c.F << " " << c.S.F << " " << c.S.S << endl;
        if (c.F <= lastTime) ans = max(currTime-seniorityToCow[c.S.F].F, ans);
        currTime = max(currTime, c.F) + c.S.S;
    }
    cout << ans << "\n";
}

*/