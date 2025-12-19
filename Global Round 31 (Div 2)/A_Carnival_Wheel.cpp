# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int l, a, b; cin >> l >> a >> b;
    int val = a, maxVal = -1;
    for(int i = 0; i < l; i++) {
        val = (val + b) % l;
        maxVal = max(maxVal, val);
    }
    cout << maxVal << "\n";
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