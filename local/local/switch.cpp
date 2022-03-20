/*
	group : local
	name : switch.cpp
	srcPath : /home/aryan/Dropbox/Documents from PC/free/darwin/15-feb/switch.cpp
	url : /home/aryan/Dropbox/Documents from PC/free/darwin/15-feb/switch.cpp
*/
/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
// const int inf = 1e6 + 5;

int k;

const int mx = 25;
const int mxnum = 1<<mx;
bool visited[mxnum];
int steps[mxnum];

int work(int s) {
    return s==0;
}

int main() {
    cin >> k;
    int lights=0;
    int pw=1;
    for (int i =0; i <k; i++) {
        char a; cin >> a;
        if(a=='1'){
            lights+=pw;
        }
        pw*=2;
    }

    queue<int> q; q.push(lights);
    steps[lights] =0;
    //add
    visited[lights]=true;

    while (!q.empty()) {
        int c = q.front(); q.pop();
        if (work(c)) {
            printf("%d\n", steps[c]);
            return 0;
        }
        for (int i=0; i <k; i++) {
            if(!((c>>i)&1)) {
                int newlights = c;
                newlights |= (1<<i);
                int cnt = 0;
                if (visited[newlights] == false) {
                    for (int j=0; j <k; j++) {
                        if ((newlights>>j)&1) cnt ++;
                        else {
                            if (cnt >= 4) {
                                for (int a = j-cnt; a <j; a++) {
                                    newlights &= ~(1<<a);
                                }
                            }
                            cnt = 0;
                        }
                    }
                    if (cnt >= 4) {
                        for (int a = k-cnt; a <k; a++) {
                            newlights &= ~(1<<a);
                        }
                    }
                    if (visited[newlights] == false){
                        steps[newlights] = steps[c] + 1;
                        q.push(newlights);
                        visited[newlights]=true;

                    }
                }

            }
        }

    }


}
*/



#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
const int inf = 1e6 + 5;



int k; 
const int mx = 25;
const int mxnum = 1<<25;

int steps[mxnum];
bool visited[mxnum];

int work(int s) {
    return s==0;
}

int main() {
    cin >> k;
    int lights=0;
    int pw=1;
    for (int i =0; i <k; i++) {
        char a; cin >> a;
        if(a=='1'){
            lights+=pw;
        }
        pw*=2;
    }
    queue<int> q;
    q.push(lights);
    steps[lights] =0;
    visited[lights]=true;
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        if (work(c)) {
            printf("%d\n", steps[c]);
            return 0;
        }
        for (int i=0; i <k; i++) {
            if(!((c>>i)&1)) {
                int newlights = c;
                newlights |= (1<<i) ;
                int cnt = 0;
                if (!visited[newlights]) {
                    for (int j=0; j <k; j++) {
                        if ((newlights>>j)&1) cnt ++;
                        else {
                            if (cnt >= 4) {
                                for (int a = j-cnt; a <j; a++) {
                                    newlights &= ~(1<<a);
                                }
                            }
                            cnt = 0;
                        }
                    }
                    if (cnt >= 4) {
                        for (int a = k-cnt; a <k; a++) {
                            newlights &= ~(1<<a);
                        }
                    }
                    if(!visited[newlights]){
                        steps[newlights] = steps[c] + 1;
                        q.push(newlights);
                        visited[newlights]=true;
                    }
                }

            }
        }

    }


}