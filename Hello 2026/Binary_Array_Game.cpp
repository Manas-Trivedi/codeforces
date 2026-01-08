# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    int first = -1, last = -1;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x == 0) {
            if(first == -1) first = i;
            last = i;
        }
    }
    if(first == -1 || (first != 0 || last != n - 1)) cout << "Alice\n";
    else cout << "Bob\n";
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