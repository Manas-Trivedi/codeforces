# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    vll nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    if(n == 1) {
        cout << "0\n";
        return;
    }
    int divs = 0; bool flag = false;
    for(int i = n - 2; i >= 0; i--) {
        if(nums[i+1] == 0) {
            cout << -1 << "\n";
            flag = true;
            break;
        }
        if(nums[i] > nums[i + 1]) {
            int pwr = log2(nums[i] / nums[i + 1]);
            divs += pwr + 1;
            nums[i] >>= pwr + 1;
        } if(nums[i] == nums[i + 1]) {
            divs++;
            nums[i] >>= 1;
        }
    }
    if(!flag) cout << divs << "\n";
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