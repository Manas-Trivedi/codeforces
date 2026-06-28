# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    vi nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int valid = -1;
    for(int i = 0; i < n; i++) {
        if(nums[i] == n - i) valid++;
        else break;
    }
    int l = valid + 1, r = n + 1;
    for(int i = valid + 1; i < n; i++) {
        if(nums[i] == n - (valid + 1)) r = i;
    }
    for(int i = 0; i <= valid; i++) {
        cout << nums[i] << " ";
    }
    if(valid != n - 1) {
        for(int i = r; i >= l; i--) cout << nums[i] << " ";
        for(int i = r + 1; i < n; i++) cout << nums[i] << " ";
    }
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