# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    ll n; cin >> n;
    ll mini = LLONG_MAX, maxi = LLONG_MIN;
    mini = n / 6ll;
    if((n - 8) % 6 == 0 || (n - 4) % 6 == 0) mini++;
    maxi = n / 4ll;
    if(n < 4 || (n & 1)) cout << -1 << "\n";
    else if(n == 4 || n == 6) cout << "1 1\n";
    else cout << mini << " " << maxi << "\n";
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