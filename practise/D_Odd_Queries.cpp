# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    int q; cin >> q;
    ll sum = 0ll;
    vi sums(n);
    for(int i = 0; i < n; i++) {
        ll num; cin >> num;
        sum += num;
        sums[i] = sum;
    }
    while(q--) {
        int l, r, k; cin >> l >> r >> k;
        ll l_sum = 0ll, r_sum = 0ll, total = 0ll;
        if(l > 1) l_sum = sums[l - 2];
        if(r < n) r_sum = sums[n - 1] - sums[r - 1];
        total = l_sum + r_sum + (1ll * k * (r - l + 1ll));
        if(total & 1) cout << "YES\n";
        else cout << "NO\n";
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