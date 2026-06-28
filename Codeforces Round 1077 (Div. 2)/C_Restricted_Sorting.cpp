#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int min_val = 1e9 + 7;
    int max_val = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < min_val) min_val = a[i];
        if (a[i] > max_val) max_val = a[i];
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    bool already_sorted = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            already_sorted = false;
            break;
        }
    }
    if (already_sorted) {
        cout << -1 << endl;
        return;
    }
    int low = 1, high = 1e9;
    int ans = 0;
    while (low <= high) {
        int k = low + (high - low) / 2;
        long long iso_lower = (long long)max_val - k + 1;
        long long iso_upper = (long long)min_val + k - 1;
        bool possible = true;
        if (iso_lower <= iso_upper) {
            for (int i = 0; i < n; ++i) {
                if (a[i] >= iso_lower && a[i] <= iso_upper) {
                    if (a[i] != b[i]) {
                        possible = false;
                        break;
                    }
                }
            }
        }
        if (possible) {
            ans = k;
            low = k + 1;
        } else {
            high = k - 1;
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}