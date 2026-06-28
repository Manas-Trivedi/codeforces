# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

ll get_prefix_score(vector<int> a) {
    int n = a.size();
    ll total = 0;
    int current_mex = 0;
    int current_max = 0;
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++) {
        current_max = max(current_max, a[i]);
        if (a[i] < n) freq[a[i]]++;
        while (current_mex < n && freq[current_mex] > 0) {
            current_mex++;
        }
        total += (ll)current_max + current_mex;
    }
    return total;
}

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    ll ans = get_prefix_score(nums);
    vector<int> s2 = nums;
    int mx = s2.back();
    s2.pop_back();
    s2.insert(s2.begin(), mx);
    ans = max(ans, get_prefix_score(s2));
    vector<int> unique_elements, duplicates;
    for(int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i-1]) duplicates.push_back(nums[i]);
        else unique_elements.push_back(nums[i]);
    }
    vector<int> s3 = unique_elements;
    s3.insert(s3.end(), duplicates.begin(), duplicates.end());
    ans = max(ans, get_prefix_score(s3));

    cout << ans << "\n";
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