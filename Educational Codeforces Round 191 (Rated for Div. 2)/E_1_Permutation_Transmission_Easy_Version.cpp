#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
vector<string> s;
vector<int> col_mask;
vector<int> target_counts;
vector<int> current_mask_values;
int ans;
void backtrack(int bit_idx, int assigned_strings) {
    if (bit_idx == k) {
        vector<int> freq(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int val = current_mask_values[i];
            if (val < 1 || val > n) return;
            freq[val]++;
        }
        for (int i = 1; i <= n; i++) {
            if (freq[i] != 1) return;
        }
        ans++;
        return;
    }
    for (int str_idx = 0; str_idx < k; str_idx++) {
        if (!(assigned_strings & (1 << str_idx))) {
            bool possible = true;
            for (int i = 0; i < n; i++) {
                if (col_mask[i] & (1 << str_idx)) {
                    current_mask_values[i] |= (1 << bit_idx);
                }
            }
            for (int i = 0; i < n; i++) {
                if (current_mask_values[i] > n) {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                backtrack(bit_idx + 1, assigned_strings | (1 << str_idx));
            }
            for (int i = 0; i < n; i++) {
                if (col_mask[i] & (1 << str_idx)) {
                    current_mask_values[i] &= ~(1 << bit_idx);
                }
            }
        }
    }
}

void solve() {
    cin >> n;
    k = 0;
    while ((1 << k) <= n) {
        k++;
    }

    s.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> s[i];
    }
    col_mask.assign(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (s[j][i] == '1') {
                col_mask[i] |= (1 << j);
            }
        }
    }

    ans = 0;
    current_mask_values.assign(n, 0);

    backtrack(0, 0);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}