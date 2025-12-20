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
        vi a(k);
        int loose = 0;
        for(int i = 30; i >= 0; i--) {
            if(n >> i & 1) {
                if(loose == k) {
                    for(int j = 0; j < k - 1; j++) a[j] += 1 << i;
                } else {
                    for(int j = 0; j < k; j++) if(j != loose) a[j] += 1 << i;
                    loose++;
                }
            } else {
                if(loose & 1) for(int j = 0; j < loose - 1; j++) a[j] += 1 << i;
                else for(int j = 0; j < loose; j++) a[j] += 1 << i;
            }
        }
        for(int i = 0; i < k; i++) cout << a[i] << " ";
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