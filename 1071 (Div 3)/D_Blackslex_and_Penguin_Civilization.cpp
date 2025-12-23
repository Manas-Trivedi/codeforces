# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    ll maxNum = 0ll;
    for(int i = 0; i < n; i++) maxNum += 1 << i;
    cout << maxNum << " ";
    int num2 = maxNum >> 1;
    cout << num2 << " ";
    int bits = n - 2;
    while(bits >= 0) {
        ll base = 0ll;
        for(int i = 0; i < bits; i++) base += 1 << i;
        for(ll i = 0ll; i <= (1 << (n - bits - 2ll)); i++) {
            ll num = i << (n - bits - 1ll);
            cout << num + base << " ";
        }
        bits--;
    }
    for(ll i = 2ll; i < maxNum; i += 2) cout << i << " ";
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