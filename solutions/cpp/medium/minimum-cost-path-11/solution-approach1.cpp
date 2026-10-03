// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/minimum-cost-path-11/problem?isFullScreen=true
// Problem     MINIMUM COST PATH 11
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:55 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<vector<long long>> dp(N, vector<long long>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> dp[i][j];
            if (i > 0 && j > 0) dp[i][j] += min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            else if (i > 0) dp[i][j] += dp[i-1][j];
            else if (j > 0) dp[i][j] += dp[i][j-1];
        }
    }
    cout << dp[N - 1][N - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    if (cin >> T) while (T--) solve();
    return 0;
}
