# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n, h, l; cin >> n >> h >> l;
    vi nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    int count = 0;
    set<pair<int, int>> st;
    for(int i = n - 1; i > 0; i--) {
        if(nums[i] > max(l, h)) continue;;
        for(int j = 0; j < n; j++) {
            if(nums[j] > l || j == i) break;
            pair<int, int> pr = {nums[i], nums[j]};
            if(st.find(pr) != st.end()) continue;
            else {
                count++;
                st.emplace(pr);
            }
        }
    }
    cout << count << "\n";
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