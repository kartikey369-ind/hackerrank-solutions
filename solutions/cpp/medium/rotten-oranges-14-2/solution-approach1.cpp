// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/rotten-oranges-14-2/problem?isFullScreen=true
// Problem     ROTTEN ORANGES 14
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:55 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve(int N, int M) {
    vector<vector<int>> g(N, vector<int>(M));
    queue<pair<int, int>> q;
    int fresh = 0, time = 0;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 2) q.push({i, j});
            else if (g[i][j] == 1) fresh++;
        }
    }

    while (!q.empty() && fresh > 0) {
        int sz = q.size();
        time++;
        while (sz--) {
            int r = q.front().first, c = q.front().second;
            q.pop();

            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < N && nc >= 0 && nc < M && g[nr][nc] == 1) {
                    g[nr][nc] = 2;
                    fresh--;
                    q.push({nr, nc});
                }
            }
        }
    }

    cout << (fresh == 0 ? time : -1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    while (cin >> N >> M) {
        solve(N, M);
    }

    return 0;
}
