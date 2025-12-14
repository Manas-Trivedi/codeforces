# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    vi nums(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        nums[i] = abs(x - (i + 1));
    }
    int result = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] != 0) result = gcd(result, nums[i]);
        if(result == 1) break;
    }
    cout << result << "\n";
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