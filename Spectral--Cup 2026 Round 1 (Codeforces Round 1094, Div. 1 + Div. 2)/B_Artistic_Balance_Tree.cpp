# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    int n, m; cin >> n >> m;
    vi nums(n);
    int posCount = 0;
    long long sum = 0ll;
    vector<int> evenPos;
    vector<int> oddPos;
    int evenNeg = INT_MIN, oddNeg = INT_MIN;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        if(nums[i] >= 0) {
            posCount++;
            if(i & 1) evenPos.push_back(nums[i]);
            else oddPos.push_back(nums[i]);
        } else {
            if(i & 1) evenNeg = max(evenNeg, nums[i]);
            else oddNeg = max(oddNeg, nums[i]);
        }
        sum += nums[i] * 1ll;
    }
    int odd = 0, even = 0;
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        if(x & 1) odd++;
        else even++;
    }
    if(posCount == 0) {
        if(even > 0) sum -= evenNeg;
        if(odd > 0) sum -= oddNeg;
    } else {
        if(even > 0) {
            if(evenPos.size() > 0) {
                sort(evenPos.begin(), evenPos.end());
                for(int i = 1; i <= even; i++) {
                    if(i <= evenPos.size()) sum -= evenPos[evenPos.size() - i];
                    else break;
                }
            }
            else sum -= evenNeg;
        }
        if(odd > 0) {
            if(oddPos.size() > 0) {
                sort(oddPos.begin(), oddPos.end());
                for(int i = 1; i <= odd; i++) {
                    if(i <= oddPos.size()) sum -= oddPos[oddPos.size() - i];
                    else break;
                }
            }
            else sum -= oddNeg;
        }
    }
    cout << sum << endl;
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