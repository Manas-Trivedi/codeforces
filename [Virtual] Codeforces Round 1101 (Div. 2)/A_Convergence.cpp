# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    unordered_map<int, int> mpp;
    vi nums(n);
    int res = 0, maxNum = -1;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        mpp[nums[i]]++;
        if(mpp[nums[i]] > res) {
            res = mpp[nums[i]];
            maxNum = nums[i];
        }
    }
    int less = 0, great = 0;
    for(auto &it: mpp) {
        if(it.first < maxNum) less += it.second;
        else if(it.first > maxNum) great += it.second;
    }
    int diff = max(less, great);
    int calls = min(n / 2, diff);
    cout << calls << "\n";
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