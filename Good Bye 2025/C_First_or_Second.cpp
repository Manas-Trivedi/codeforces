#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    if (n == 1) {
        cout << nums[0] << '\n';
        return;
    }

    ll best = 0;
    ll bestPlus = nums[0];

    for (int i = 1; i < n; ++i) {
        ll newBest = max(best - nums[i], bestPlus);
        ll newBestPlus = bestPlus + llabs(nums[i]);
        best = newBest;
        bestPlus = newBestPlus;
    }

    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}