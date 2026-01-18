#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r;
    long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    int d = 0;
    while ((1LL << (d + 1)) <= n) {
        d++;
    }
    ll win = 0;
    for (int len = 1; len <= d; ++len) {
        int max_i = k - len;
        for (int i = 0; i <= min(len - 1, max_i); ++i) {
            win += nCr(len - 1, i);
        }
    }
    if (d + 1 <= k) {
        win++;
    }

    cout << n - win << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}