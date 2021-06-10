/*
	group : local
	name : x.cpp
	srcPath : /home/aryan/Documents/cp/x.cpp
	url : /home/aryan/Documents/cp/x.cpp
*/
#include <bits/stdc++.h>
#include "random"

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

vector<string> split(const string& s, char p) {
    vector<string> res(1);
    for (char c : s) {
        if (c == p) {
            res.emplace_back();
        } else {
            res.back() += c;
        }
    }
    return res;
}

struct Word {
    // ll len;
    ll cnt;
    string s;
};

string getFirst(string s) {
    if (s.size() < 3) {
        return s;
    }
    return s.substr(0, 3);
}

string getLast(string s) {
    if (s.size() < 3) {
        return s;
    }
    return s.substr(s.size() - 3, 3);
}

int count(const string& s, const string& p) {
    int cnt = 0;
    for (int i = 0; i + p.size() <= s.size(); i++) {
        if (s.substr(i, p.size()) == p) {
            cnt++;
        }
    }
    return cnt;
}

Word merge(const Word& a, const Word& b) {
    Word c;
    // c.len = a.len + b.len;
    c.s = a.s + b.s;
    c.cnt = a.cnt + b.cnt + count(getLast(a.s) + getFirst(b.s), "haha");
    if (c.s.size() >= 7) {
        c.s = getFirst(c.s) + "@" + getLast(c.s);
    }
    return c;
}

void solve() {
    int n;
    cin >> n;
    map<string, Word> vars;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        string var;
        cin >> var;
        string opr;
        cin >> opr;
        if (opr == "=") {
            string a, plus, b;
            cin >> a >> plus >> b;
            vars[var] = merge(vars[a], vars[b]);
        } else {
            string str;
            cin >> str;
            Word word;
            // word.len = str.length();
            word.cnt = count(str, "haha");
            word.s = str;
            vars[var] = word;
        }
        ans = vars[var].cnt;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}