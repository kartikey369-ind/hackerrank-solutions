// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/check-k-th-bit-1/problem?isFullScreen=true
// Problem     Check K-th Bit
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:50 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (n & (1 << k))
        cout << 1;
    else
        cout << 0;

    return 0;
}
