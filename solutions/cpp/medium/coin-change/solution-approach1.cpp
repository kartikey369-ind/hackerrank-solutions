// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/coin-change/problem?isFullScreen=true
// Problem     The Coin Change Problem
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:54 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>

using namespace std;

long long getWays(int n, const vector<long long>& c) {
 
    vector<long long> dp(n + 1, 0);

    dp[0] = 1;

    for (long long coin : c) {
        for (int i = coin; i <= n; ++i) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (cin >> n >> m) {
        vector<long long> c(m);
        for (int i = 0; i < m; ++i) {
            cin >> c[i];
        }

        cout << getWays(n, c) << "\n";
    }

    return 0;
}
