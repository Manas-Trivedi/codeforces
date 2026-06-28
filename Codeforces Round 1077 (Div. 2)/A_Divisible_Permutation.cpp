# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    if(n == 2) cout << "1 2";
    else {
        for(int i = 0; i < ceil(n / 2); i++) {
            cout << (int) ceil(n / 2.0) - i << " ";
            if(i != ceil(n / 2)) cout << (int) ceil(n / 2.0) + i + 1 << " ";
        }
        if(n % 2 != 0) cout << 1;
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