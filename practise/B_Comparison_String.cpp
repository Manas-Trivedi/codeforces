# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int depth = 1, maxDepth = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i - 1]) depth++;
        else {
            maxDepth = max(maxDepth, depth);
            depth = 1;
        }
    }
    maxDepth = max(maxDepth, depth);
    cout << maxDepth + 1 << "\n";
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