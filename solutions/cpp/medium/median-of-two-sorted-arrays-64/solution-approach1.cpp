// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/median-of-two-sorted-arrays-64/problem?isFullScreen=true
// Problem     MEDIAN OF TWO SORTED ARRAYS 64
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:48 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m), c;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    int i = 0, j = 0;

    while (i < n && j < m) {
        if (a[i] <= b[j])
            c.push_back(a[i++]);
        else
            c.push_back(b[j++]);
    }

    while (i < n)
        c.push_back(a[i++]);

    while (j < m)
        c.push_back(b[j++]);

    int total = n + m;

    if (total % 2 == 1) {
        cout << fixed << setprecision(1) << (double)c[total / 2];
    } else {
        double median = (c[total / 2 - 1] + c[total / 2]) / 2.0;
        cout << fixed << setprecision(1) << median;
    }

    return 0;
}
