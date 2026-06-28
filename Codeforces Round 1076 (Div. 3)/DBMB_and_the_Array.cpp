# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n, s, x; cin >> n >> s >> x;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        sum += k;
    }
    if(sum > s || (s - sum) % x != 0) cout << "NO\n";
    else cout << "YES\n";
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