# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n, x; cin >> n >> x;
    int val = 0, flag = 0;
    if(n == 1) cout << "0\n";
    else {
        for(int i = 0; i < n - 1; i++) {
            if(val == x) {
                val = n - 1;
                flag = 1;
            }
            cout << val << " ";
            val += pow(-1, flag);
        }
        if(x < n) cout << x << "\n";
        else cout  << n - 1 << "\n";
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