# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    vi nums(n);

    vi diff(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    diff[0] = abs(nums[1] - nums[0]);
    diff[n - 1] = abs(nums[n - 1] - nums[n - 2]);
    for(int i = 1; i < n - 1; i++) {
        diff[i] = abs(nums[i] - nums[i - 1]) + abs(nums[i + 1] - nums[i]) - abs(nums[i + 1] - nums[i - 1]);
    }
    int maxDiff = -1;
    for(int i = 0; i < n; i++) {
        if(diff[i] > maxDiff) {
            maxDiff = diff[i];
        }
    }
    ll minSum = 0ll;
    for(int i = 1; i < n; i++) {
        minSum += abs(nums[i] - nums[i - 1]) * 1ll;
    }
    minSum -= maxDiff * 1ll;
    cout << minSum << "\n";
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