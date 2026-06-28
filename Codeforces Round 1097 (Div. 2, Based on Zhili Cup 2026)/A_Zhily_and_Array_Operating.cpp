# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    vector<long long> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int cnt = nums[n - 1] > 0;
    for(int i = n - 2; i >= 0; i--) {
        nums[i] = nums[i + 1] > 0 ? 1ll * nums[i] + nums[i + 1] : nums[i];
        if(nums[i] > 0) cnt++;
    }
    cout << cnt << "\n";
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