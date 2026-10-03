// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/count-set-bits-19/problem?isFullScreen=true
// Problem     Count Set Bits 19
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:50 p.m.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>

int main() {
    unsigned long long n;
    std::cin >> n;

    int count = 0;

    while (n) {
        n = n & (n - 1);
        count++;
    }

    std::cout << count;

    return 0;
}
