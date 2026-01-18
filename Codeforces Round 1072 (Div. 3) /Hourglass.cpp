# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n, k, m; cin >> n >> k >> m;
    int time = m - (k * (m / k));
    if(n <= k) {
        cout << max(0, n - time) << "\n";
    } else {
        if((m / k) & 1) cout << max(0, k - time);
        else cout << max(0, n - time);
        cout << "\n";
    }
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