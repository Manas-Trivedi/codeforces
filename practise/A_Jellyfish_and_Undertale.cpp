# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int a, b, n; cin >> a >> b >> n;
    ll sum = b * 1ll;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        sum += min(x, a - 1) * 1ll;
    }
    cout << sum << "\n";
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