# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
    cin >> t;
    while(t--) {
        int maxi = INT_MIN;
        int n; cin >> n;
        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            maxi = max(x, maxi);
        }
        cout << maxi << "\n";
    }
    return 0;
}