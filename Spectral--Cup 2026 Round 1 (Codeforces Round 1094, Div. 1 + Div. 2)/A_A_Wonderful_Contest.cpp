# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x == 100) flag = true;
    }
    if(flag) cout << "Yes\n";
    else cout << "No\n";
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