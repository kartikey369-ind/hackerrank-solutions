// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/spirally-traverse-matrix/problem?isFullScreen=true
// Problem     SPIRALLY TRAVERSE MATRIX
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:56 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    bool first = true;

    while (top <= bottom && left <= right) {
        // 1. Move Left to Right
        for (int col = left; col <= right; ++col) {
            if (!first) cout << " ";
            cout << matrix[top][col];
            first = false;
        }
        top++;

        // 2. Move Top to Bottom
        for (int row = top; row <= bottom; ++row) {
            if (!first) cout << " ";
            cout << matrix[row][right];
            first = false;
        }
        right--;

        // 3. Move Right to Left (check if top boundary hasn't passed bottom)
        if (top <= bottom) {
            for (int col = right; col >= left; --col) {
                if (!first) cout << " ";
                cout << matrix[bottom][col];
                first = false;
            }
            bottom--;
        }

        // 4. Move Bottom to Top (check if left boundary hasn't passed right)
        if (left <= right) {
            for (int row = bottom; row >= top; --row) {
                if (!first) cout << " ";
                cout << matrix[row][left];
                first = false;
            }
            left++;
        }
    }

    cout << "\n";
    return 0;
}
