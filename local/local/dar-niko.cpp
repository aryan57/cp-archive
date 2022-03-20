/*
	group : local
	name : dar-niko.cpp
	srcPath : /home/aryan/Dropbox/Documents from PC/free/darwin/15-feb/dar-niko.cpp
	url : /home/aryan/Dropbox/Documents from PC/free/darwin/15-feb/dar-niko.cpp
*/


// #include <bits/stdc++.h>
// using namespace std;
// // #define int long long
// typedef long long ll;
// typedef vector<int> vi;
// typedef pair<int, int> pi;
// #define F first
// #define S second
// #define PB push_back 3
// const int maxn = 1e6 + 5;
// // const int inf = 1e18;

// struct form
// {
//     int d, m, o;
// };
// struct player
// {
//     bool d, m, o;
// };

// int n, m;
// player players[23];
// bool ans = false;
// form arr[11];

// void work(int needDef, int needMid, int needOff, int dm, int mo, int od, int dmo)
// {

//     // dbg(needDef,needMid,needOff,dm,mo,od,dmo);
//     if (needMid <= 0 && needOff <= 0 && needDef <= 0)
//     {
//         ans = true;
//         return;
//     }
//     // else if (dm == 0 && mo == 0 && od == 0) {
//     if (dmo >= (max(0, needDef) + max(0, needMid) + max(0, needOff)))
//     {
//         ans = true;
//         return;
//     }
//     // }
//     // dbg(needDef,needMid,needOff,dm,mo,od,dmo);
//     for (int i = 0; i <= dm; i++)
//     {
//         for (int j = 0; j <= mo; j++)
//         {
//             for (int k = 0; k <= od; k++)
//             {
//                 if (dmo >= (max(0, needDef - i - od + k) + max(0, needMid - dm + i - j) + max(0, needOff - k - mo + j)))
//                 {
//                     ans = true;
//                     return;
//                 }
//             }
//         }
//     }
//     return;
// }

// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d-%d-%d", &arr[i].d, &arr[i].m, &arr[i].o);
//     }
//     cin >> m;
//     for (int i = 0; i < m; i++)
//     {
//         string s;
//         cin >> s;
//         for (int j = 0; j < s.size(); j++)
//         {
//             if (s[j] == 'O')
//                 players[i].d = 1;
//             if (s[j] == 'V')
//                 players[i].m = 1;
//             if (s[j] == 'N')
//                 players[i].o = 1;
//         }
//     }
//     int jd = 0, jm = 0, jo = 0, dm = 0, mo = 0, od = 0, dmo = 0;
//     for (int i = 0; i < m; i++)
//     {
//         if (players[i].d && !players[i].m && !players[i].o)
//             jd++;
//         if (!players[i].d && players[i].m && !players[i].o)
//             jm++;
//         if (!players[i].d && !players[i].m && players[i].o)
//             jo++;
//         if (players[i].d && players[i].m && !players[i].o)
//             dm++;
//         if (players[i].d && !players[i].m && players[i].o)
//             od++;
//         if (!players[i].d && players[i].m && players[i].o)
//             mo++;
//         if (players[i].d && players[i].m && players[i].o)
//             dmo++;
//     }
//     for (int j = 0; j < n; j++)
//     {
//         form f = arr[j];
//         ans = false;
//         int needDef = f.d, needMid = f.m, needOff = f.o;
//         needDef -= jd;
//         needMid -= jm;
//         needOff -= jo;
//         work(needDef, needMid, needOff, dm, mo, od, dmo);
//         if (ans == true)
//             cout << "DA\n";
//         else
//             cout << "NE\n";
//     }
// }


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back 3
const int maxn = 1e6 + 5;
// const int inf = 1e18;

struct form{
    int d,m, o;
};
struct player {
    bool d, m, o;
};

int n, m; player players[23]; bool ans=false;
form arr[11];

void work(int needDef, int needMid, int needOff, int dm, int mo, int od, int dmo) {
    if (needMid <= 0 && needOff <= 0 && needDef <= 0) {
        ans = true;
        return;
    }
    else if (dm == 0 && mo == 0 && od == 0) {
        if (dmo >= (max(0, needDef) + max(0, needMid) + max(0, needOff))) {
            ans = true;
            return;
        }
    }
    for (int i=0; i <=dm; i++) {
        work(needDef-i, needMid-dm+i, needOff, 0, mo, od, dmo);
    }
    for (int i=0; i <=mo; i++) {
        work(needDef, needMid-i, needOff-mo+i, dm, 0, od, dmo);
    }
    for (int i=0; i <=od; i++) {
        work(needDef-od+i, needMid, needOff-i, dm, mo, 0, dmo);
    }
    return;
}

int main() {
    cin >> n;
    for (int i=0; i <n; i++) {
        scanf("%d-%d-%d",&arr[i].d, &arr[i].m, &arr[i].o);
    }
    cin>> m;
    for (int i=0; i <m; i++) {
        string s; cin >> s;
        for (int j =0; j < s.size(); j++) {
            if (s[j] == 'O') players[i].d = 1;
            if (s[j] == 'V') players[i].m = 1;
            if (s[j] == 'N') players[i].o = 1;
        }
    }
    int jd =0, jm = 0, jo = 0, dm =0, mo = 0, od = 0, dmo = 0;
    for (int i =0; i <m; i++) {
        if (players[i].d && !players[i].m && !players[i].o) jd++;
        if (!players[i].d && players[i].m && !players[i].o) jm++;
        if (!players[i].d && !players[i].m && players[i].o) jo++;
        if (players[i].d && players[i].m && !players[i].o) dm ++;
        if (players[i].d && !players[i].m && players[i].o) od ++;
        if (!players[i].d && players[i].m && players[i].o) mo++;
        if (players[i].d && players[i].m && players[i].o) dmo ++;
    }
    for (int j =0; j <n; j++) {
        form f = arr[j];
        ans = false;
        int needDef = f.d, needMid = f.m, needOff = f.o;
        needDef -= jd; needMid -= jm; needOff -= jo;
        work(needDef, needMid, needOff, dm, mo, od, dmo);
        if (ans == true) cout << "DA\n";
        else cout << "NE\n";
    }

}
