# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;

    int xo = 0, nz = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x > 0) nz++;
        xo ^= x;
    }
    if(nz == 0) cout << 0 << endl;
    else if(xo == 0) {
        cout << "1\n";
        cout << "1 " << n << "\n";
    } else {
        if(n % 2 == 0) {
            cout << "2\n";
            cout << 1 << " " << n << "\n";
            cout << 1 << " " << n << "\n";
        } else {
            cout << "4\n";
            cout << 1 << " " << n << "\n";
            cout << 1 << " " << n - 1 << "\n";
            cout << n - 1 << " " << n << "\n";
            cout << n - 1 << " " << n << "\n";
        }
    }
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