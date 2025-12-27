# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {
    string s, word; cin >> s >> word;
    int n = s.size();
    multiset<char> st;
    for(int i = 0; i < word.size(); i++) st.emplace(word[i]);
    int idx = word.size() - 1;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == word[idx]) {
            idx--;
            st.erase(st.find(s[i]));
        }
        else if(st.find(s[i]) != st.end()) break;
    }
    if(idx == -1) cout << "YES\n";
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