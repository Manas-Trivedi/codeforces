#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    vector<int> uniq;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        uniq.push_back(a[i]);
    }
    sort(uniq.begin(), uniq.end());
    uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
    int D = uniq.size();

    struct Block {
        int type, L, R;
    };
    vector<Block> blocks;
    int start = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == n || a[i] != a[start]) {
            blocks.push_back({a[start], start, i - 1});
            start = i;
        }
    }

    int B = blocks.size();
    if (B == D) {
        cout << "YES\n";
        return;
    }

    map<int, int> b_count;
    for (const auto& b : blocks) {
        b_count[b.type]++;
    }

    set<int> broken;
    for (const auto& pair : b_count) {
        if (pair.second > 1) {
            broken.insert(pair.first);
        }
    }

    if (broken.size() > 4) {
        cout << "NO\n";
        return;
    }

    vector<bool> is_cand(n, false);
    for (int i = 0; i < B; ++i) {
        bool interesting = false;
        if (broken.count(blocks[i].type)) interesting = true;
        if (i > 0 && broken.count(blocks[i - 1].type)) interesting = true;
        if (i < B - 1 && broken.count(blocks[i + 1].type)) interesting = true;

        if (interesting) {
            is_cand[blocks[i].L] = true;
            is_cand[blocks[i].R] = true;
        }
    }

    vector<int> cands;
    for (int i = 0; i < n; ++i) {
        if (is_cand[i]) {
            cands.push_back(i);
        }
    }

    for (size_t i = 0; i < cands.size(); ++i) {
        for (size_t j = i + 1; j < cands.size(); ++j) {
            int u = cands[i];
            int v = cands[j];

            set<int> affected;
            if (u > 0) affected.insert(u - 1);
            if (u < n - 1) affected.insert(u);
            if (v > 0) affected.insert(v - 1);
            if (v < n - 1) affected.insert(v);

            int old_trans = 0;
            for (int idx : affected) {
                if (a[idx] != a[idx + 1]) old_trans++;
            }

            swap(a[u], a[v]);

            int new_trans = 0;
            for (int idx : affected) {
                if (a[idx] != a[idx + 1]) new_trans++;
            }

            swap(a[u], a[v]);

            int new_B = B - old_trans + new_trans;
            if (new_B == D) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
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