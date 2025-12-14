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
        if(x == 1) x = 2;
        if(i == 0) nums[i] = x;
        else {
            if(x % nums[i - 1] == 0) {
                nums[i] = x + 1;
            } else {
                nums[i] = x;
            }
        }
    }
    for(int i = 0; i < n; i++) cout << nums[i] << " ";
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