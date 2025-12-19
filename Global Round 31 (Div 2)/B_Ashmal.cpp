# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    string res = "", cmp = "";
    set<string> st;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        if(res.empty()) res += s;
        else {
            if(s + res < res + s) {
                res = s + res;
            } else {
                res = res + s;
            }
        }
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
    cin >> t;
    while(t--) {
        // cout << "Test Case: " << t << "\n";
        solve();
    }
    return 0;
}