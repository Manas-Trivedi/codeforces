#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    string s;
    cin >> s;


    vi open_indices, close_indices;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            open_indices.push_back(i);
        } else {
            close_indices.push_back(i);
        }
    }
    int target_keep = n - k;
    int min_cost = 1e9;
    int best_x = -1, best_y = -1;
    int O_total = open_indices.size();
    int C_total = close_indices.size();

    for (int x = 0; x <= O_total; ++x) {
        int y = target_keep - x;
        if (y >= 0 && y <= C_total) {


            int open_ptr = O_total - x;
            int close_ptr = 0;
            int unmatched_open = 0;
            int matches = 0;

            while (open_ptr < O_total || close_ptr < y) {
                if (open_ptr < O_total && (close_ptr == y || open_indices[open_ptr] < close_indices[close_ptr])) {
                    unmatched_open++;
                    open_ptr++;
                } else {
                    if (unmatched_open > 0) {
                        unmatched_open--;
                        matches++;
                    }
                    close_ptr++;
                }
            }

            int current_cost = 2 * matches;
            if (current_cost < min_cost) {
                min_cost = current_cost;
                best_x = x;
                best_y = y;
            }
        }
    }
    string ans = string(n, '1');
    for (int i = O_total - best_x; i < O_total; ++i) {
        ans[open_indices[i]] = '0';
    }
    for (int i = 0; i < best_y; ++i) {
        ans[close_indices[i]] = '0';
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}