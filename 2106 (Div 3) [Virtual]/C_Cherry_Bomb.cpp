# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n, k; cin >> n >> k;
    vi a(n);
    bool flag = true;
    bool sameSum = true;
    int sum = -1;
    int mini = INT_MAX, maxi = -1;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = x;
        mini = min(mini, x);
        maxi = max(maxi, x);
    }
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x != -1 ) {
            flag = false;
            if(sum == -1) sum = x + a[i];
            else if(a[i] + x != sum) sameSum = false;
        }
    }
    if(flag) cout << (mini + k) - maxi + 1 << "\n";
    else if(!flag && sameSum) {
        if(sum >= maxi && sum <= (mini + k)) cout << "1\n";
        else cout << "0\n";
    }
    else cout << "0\n";
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