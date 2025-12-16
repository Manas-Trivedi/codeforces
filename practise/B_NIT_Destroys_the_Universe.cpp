# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    int seq = 0;
    bool flag = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x == 0) {
            seq = flag ? seq + 1 : seq;
            flag = 0;
        } else flag = 1;
    }
    seq = flag ? seq + 1 : seq;
    cout << min(seq, 2) << "\n";
}

// 12
// 3 1 0 4 0 0 5 5 0 0 0

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
    cin >> t;
    int num = 1;
    while(num <= t) {
        // cout << "Test Case: " << t << "\n";
        solve();
        num++;
    }
    return 0;
}