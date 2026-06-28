# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n, x, y, z; cin >> n >> x >> y >> z;
    ll a, b;
    // if using AI:
    if(n - (1ll * x * z) > 0) {
        a = z + (n - 1ll * x * z + x + 10ll * y - 1) / (x + 10ll * y);
    } else {
        a = (n + x - 1) / x;
    }
    // not using AI
    b = (n + x + y - 1) / (x + y);
    cout << min(a, b) << "\n";
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