// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/3n1-problem-4/problem?isFullScreen=true
// Problem     3N+1 PROBLEM 4
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:51 p.m.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long i, j;
    cin >> i >> j;

    long long a = i, b = j;

    if (a > b)
        swap(a, b);

    int mx = 0;

    for (long long n = a; n <= b; n++) {
        long long x = n;
        int count = 1;

        while (x != 1) {
            if (x % 2 == 0)
                x = x / 2;
            else
                x = 3 * x + 1;

            count++;
        }

        mx = max(mx, count);
    }

    cout << i << " " << j << " " << mx;

    return 0;
}
