# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n, m, h; cin >> n >> m >> h;
    vi nums(n);
    bool flag = false;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        if(nums[i] > h) flag = true;
    }
    unordered_map<int, int> ops;
    if(!flag) {
        while(m--) {
            int b, c; cin >> b >> c;
            if(ops.count(b - 1)) ops[b - 1] += c;
            else ops[b - 1] = nums[b - 1] + c;

            if(ops[b - 1] > h) ops.clear();
        }
    }
    for(int i = 0; i < n; i++) {
        if(ops.count(i)) cout << ops[i] << " ";
        else cout << nums[i] << " ";
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