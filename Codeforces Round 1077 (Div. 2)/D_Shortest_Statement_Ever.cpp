#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Result {
    ll cost, p, q;
};

Result solve_case(ll x, ll y, bool p_ge_x, bool q_ge_y) {
    ll dp[33][2][2];
    pair<int, int> choice[33][2][2];
    pair<int, int> prev_c[33][2][2];

    for(int i=0; i<33; i++)
        for(int j=0; j<2; j++)
            for(int k=0; k<2; k++) dp[i][j][k] = INF;

    dp[0][0][0] = 0;

    for (int b = 0; b < 32; b++) {
        int xb = (x >> b) & 1;
        int yb = (y >> b) & 1;

        for (int c1 = 0; c1 < 2; c1++) {
            for (int c2 = 0; c2 < 2; c2++) {
                if (dp[b][c1][c2] == INF) continue;
                for (int pb = 0; pb <= 1; pb++) {
                    for (int qb = 0; qb <= 1; qb++) {
                        if (pb && qb) continue;
                        for (int nc1 = 0; nc1 < 2; nc1++) {
                            for (int nc2 = 0; nc2 < 2; nc2++) {
                                int dxb = p_ge_x ? (pb + 2 * nc1 - xb - c1) : (xb + 2 * nc1 - pb - c1);
                                int dyb = q_ge_y ? (qb + 2 * nc2 - yb - c2) : (yb + 2 * nc2 - qb - c2);

                                if ((dxb == 0 || dxb == 1) && (dyb == 0 || dyb == 1)) {
                                    ll new_cost = dp[b][c1][c2] + ((ll)(dxb + dyb) << b);
                                    if (new_cost < dp[b+1][nc1][nc2]) {
                                        dp[b+1][nc1][nc2] = new_cost;
                                        choice[b+1][nc1][nc2] = {pb, qb};
                                        prev_c[b+1][nc1][nc2] = {c1, c2};
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (dp[32][0][0] == INF) return {INF, 0, 0};

    ll res_p = 0, res_q = 0;
    int cur_c1 = 0, cur_c2 = 0;
    for (int b = 32; b > 0; b--) {
        auto ch = choice[b][cur_c1][cur_c2];
        auto pr = prev_c[b][cur_c1][cur_c2];
        if (ch.first) res_p |= (1LL << (b - 1));
        if (ch.second) res_q |= (1LL << (b - 1));
        cur_c1 = pr.first;
        cur_c2 = pr.second;
    }
    return {dp[32][0][0], res_p, res_q};
}

void solve() {
    ll x, y;
    if (!(cin >> x >> y)) return;

    Result best = {INF, 0, 0};
    bool flags[] = {true, false};
    for (bool f1 : flags) {
        for (bool f2 : flags) {
            Result cur = solve_case(x, y, f1, f2);
            if (cur.cost < best.cost) best = cur;
        }
    }
    cout << best.p << " " << best.q << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}