# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vll;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n), b(n), c(n);
    for(int j = 0; j < n; j++) {
        int x; cin >> x;
        a[j] = {x, j};
    }
    for(int j = 0; j < n; j++) {
        int x; cin >> x;
        b[j] = {x, j};
    }
    for(int j = 0; j < n; j++) {
        int x; cin >> x;
        c[j] = {x, j};
    }
    sort(a.begin(), a.end(), comp);
    sort(b.begin(), b.end(), comp);
    sort(c.begin(), c.end(), comp);

    int maxVal = INT_MIN;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if(a[i].second != b[j].second && a[i].second != c[k].second && c[k].second != b[j].second) {
                    maxVal = max(maxVal, a[i].first + b[j].first + c[k].first);
                }
            }
        }
    }
    cout << maxVal << "\n";
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