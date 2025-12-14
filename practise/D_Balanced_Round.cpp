# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    int k; cin >> k;
    vi nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    if(n == 1) {
        cout << 0 << "\n";
        return;
    }
    sort(nums.begin(), nums.end());
    int seq = 1, maxSeq = 0;
    for(int i = 1; i < n; i++) {
        if(nums[i] - nums[i - 1] <= k) seq++;
        else {
            maxSeq = max(maxSeq, seq);
            seq = 1;
        }
    }
    maxSeq = max(maxSeq, seq);
    cout << n - maxSeq << "\n";
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