# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    if(n == 2) cout << 2 << "\n";
    else if(n == 3) cout << 3 << "\n";
    else if(n % 2 == 0) cout << 0 << "\n";
    else cout << 1 << "\n";
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