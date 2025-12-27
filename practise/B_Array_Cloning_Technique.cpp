# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    unordered_map<int, int> mpp;
    int freq = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        mpp[x]++;
        freq = max(freq, mpp[x]);
    }
    int copies = ceil(log2(n / freq));
    int swaps = n - freq;
    cout << (swaps + copies) << "\n";
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