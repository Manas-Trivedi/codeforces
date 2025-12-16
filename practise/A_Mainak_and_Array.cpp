# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    vi nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int maxDiff = nums[n - 1] - nums[0], diff;
    // change first
    for(int i = 0; i < n - 1; i++) {
        diff = nums[n - 1] - nums[i];
        maxDiff = max(maxDiff, diff);
    }
    // change last
    for(int i = 1; i < n; i++) {
        diff = nums[i] - nums[0];
        maxDiff = max(maxDiff, diff);
    }
    // change both
    for(int i = 1; i < n; i++) {
        diff = nums[i - 1] - nums[i];
        maxDiff = max(maxDiff, diff);
    }
    cout << maxDiff << "\n";
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