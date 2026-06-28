# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    vi nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    vi minLevel(n);
    ll excess = 0ll;
    minLevel[0] = nums[0];
    for(int i = 1; i < n; i++) {
        if(nums[i] >= minLevel[i - 1]) {
            excess += nums[i] - minLevel[i - 1];
            minLevel[i] = minLevel[i - 1];
        } else {
            int l = nums[i], h = minLevel[i - 1], m;
            while(l <= h) {
                m = l + (h - l) / 2;
                ll exc = excess + 1ll * i * (minLevel[i - 1] - m);
                if(exc + nums[i] >= m) {
                    l = m + 1;
                } else h = m - 1;
            }
            excess += (minLevel[i - 1] - h) * i * 1ll - (h - nums[i]);
            minLevel[i] = h;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << minLevel[i] << " ";
    }
    cout << "\n";
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