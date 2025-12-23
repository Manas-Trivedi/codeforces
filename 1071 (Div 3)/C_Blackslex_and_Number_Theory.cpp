# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    int minVal = INT_MAX, maxVal = INT_MAX;
    vi nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    for(int i = 0; i < n; i++) minVal = min(minVal, nums[i]);
    for(int i = 0; i < n; i++) if(nums[i] != minVal) maxVal = min(maxVal, nums[i]);
    int low = minVal + 1, high = maxVal - 1, mid;
    bool check = false;
    while(low <= high) {
        mid = (low + high) / 2;
        bool flag = true;
        for(int i = 0; i < n; i++) {
            if(nums[i] == minVal || nums[i] % (nums[i] - minVal) == minVal && (nums[i] - minVal) >= mid) continue;
            else {
                flag = false;
                break;
            }
        }
        // cout << "mid, flag = " << mid << " , " << flag << "\n";
        if(flag) {
            low = mid + 1;
            check = true;
        }
        else high = mid - 1;
    }
    if(check) cout << high << "\n";
    else cout << minVal << "\n";
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