// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/coin-change-problem-6-1/problem?isFullScreen=true
// Problem     COIN CHANGE PROBLEM 6
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

const int INF = 1e9;

void solve(int V, int N) {
    vector<int> C(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }

    // dp[i] stores minimum coins needed to make amount i
    vector<int> dp(V + 1, INF);
    // last_coin[i] stores the last coin added to reach amount i
    vector<int> last_coin(V + 1, -1);

    dp[0] = 0;

    for (int i = 1; i <= V; ++i) {
        for (int coin : C) {
            if (i >= coin && dp[i - coin] != INF) {
                if (dp[i - coin] + 1 < dp[i]) {
                    dp[i] = dp[i - coin] + 1;
                    last_coin[i] = coin;
                }
            }
        }
    }

    if (dp[V] == INF) {
        cout << -1 << "\n";
    } else {
        cout << dp[V] << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, N;
    while (cin >> V >> N) {
        solve(V, N);
    }

    return 0;
}
