# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

const int INF = 1e9;

map<ll, int> memo;

int check(int n, int k) {
    if(n == k) return 0;
    else if(n < k || n == 1) return INF;

    if(memo.count(n)) return memo[n];

    int res = 1 + min(check(n / 2, k), check((n + 1) / 2, k));

    return memo[n] = res;
}

void solve() {
    int n, k; cin >> n >> k;
    memo.clear();
    int result = check(n, k);
    if(result >= INF) cout << -1 << "\n";
    else cout << result << "\n";
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