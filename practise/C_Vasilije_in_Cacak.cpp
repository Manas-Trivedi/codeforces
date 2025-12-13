# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    ll n; cin >> n;
    ll k, x; cin >> k >> x;
    ll minSum = (k * (k + 1ll)) / 2ll;
    ll maxSum = ((n * (n + 1ll)) - ((n - k) * (n + 1ll - k))) / 2ll;
    if(x >= minSum && x <= maxSum) cout << "YES\n";
    else cout << "NO\n";
    return;
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