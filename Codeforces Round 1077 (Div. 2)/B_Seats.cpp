# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ones = 0;
    for(char c : s) if(c == '1') ones++;
    if(ones == 0) {
        cout << (n + 2) / 3 << "\n";
        return;
    }

    int ans = ones;
    int i = 0;
    while(i < n) {
        if(s[i] == '1') {
            i++;
            continue;
        }
        int j = i;
        while(j < n && s[j] == '0') j++;
        int len = j - i;
        bool left = (i > 0 && s[i - 1] == '1');
        bool right = (j < n && s[j] == '1');

        if(left && right) ans += len / 3;
        else ans += (len + 1) / 3;

        i = j;
    }
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