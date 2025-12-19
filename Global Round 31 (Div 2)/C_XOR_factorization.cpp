# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n, k; cin >> n >> k;
    if(k & 1) {
        for(int i = 1; i <= k; i++) cout << n << " ";
        cout << "\n";
    } else {
        long long a = 0ll, b = 0ll;
        int p = 31 - __builtin_clz(n);
        a = 1ll << p;
        int shift = p - 1;
        bool flag = 0;
        while(shift >= 0) {
            if(n & (1ll << shift)) {
                flag = 1;
                b += 1 << shift;
            } else {
                if(flag) {
                    a += 1 << shift;
                    b += 1 << shift;
                }
            }
            shift--;
        }
        cout << a << " " << b << " ";
        for(int i = 3; i <= k; i++) {
            cout << n << " ";
        }
        cout << "\n";
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