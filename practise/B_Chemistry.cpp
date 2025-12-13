# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

/*
ttrraakkttoorr
t: 4
r: 4
a: 2
k: 2
o: 2
*/

void solve() {
    int n; cin >> n;
    int k; cin >> k;
    string s; cin >> s;
    unordered_map<char, int> mpp;
    int odd = 0;
    for(int i = 0; i < n; i++) {
        mpp[s[i]]++;
        if(mpp[s[i]] & 1) odd++;
        else odd--;
    }
    if(k == odd || k == odd - 1) cout << "YES\n";
    else if(k > odd) cout << "YES\n";
    else cout << "NO\n";
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