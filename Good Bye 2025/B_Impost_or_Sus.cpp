# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    string s; cin >> s;
    int n = s.size();
    int steps = 0;
    if(s[0] == 'u') steps++;
    if(s[ n - 1] == 'u') steps++;
    s[0] = 's';
    s[n - 1] = 's';
    for(int i = 1; i < n - 1; i++) {
        if(s[i] == 'u') {
            if(s[i + 1] == 'u') {
                s[i + 1] = 's';
                steps++;
            }
        }
    }
    cout << steps << "\n";
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