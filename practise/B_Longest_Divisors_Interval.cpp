# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

int solve() {
    ll num; cin >> num;
    int ans = 0;
    for(ll i = 1; i <= num; i++) {
        if(num % i == 0) {
            ans++;
        } else {
            break;  // First non-divisor - we're done
        }
    }
    cout << ans << "\n";
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
    cin >> t;
    while(t--) {
        // cout << "Test Case: " << t << "\n";
        solve();;
    }
    return 0;
}