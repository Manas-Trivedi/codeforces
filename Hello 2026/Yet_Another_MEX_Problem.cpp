#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    vector<int> freq(n + 2, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < n + 1) {
            freq[a[i]]++;
        }
    }
    int total_mex = 0;
    while (freq[total_mex] > 0) {
        total_mex++;
    }
    cout << min(total_mex, k - 1) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}