# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    vi nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    int seq = 1, maxSeq = 0;
    for(int i = 1; i < n; i++) {
        if(nums[i] == nums[i - 1]) continue;
        else if(nums[i] - 1 == nums[i - 1]) seq++;
        else {
            maxSeq = max(seq, maxSeq);
            seq = 1;
        }
    }
    maxSeq = max(seq, maxSeq);
    cout << maxSeq << "\n";
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