# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    string s; cin >> s;
    int yCount = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'Y') yCount++;
    }
    if(yCount > 1) cout << "NO\n";
    else cout << "YES\n";
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