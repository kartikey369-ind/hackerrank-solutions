// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/division-using-binary-search/problem?isFullScreen=true
// Problem     Division Using Binary Search
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:48 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
using namespace std;

int main() {
    int dividend, divisor;
    cin >> dividend >> divisor;

    bool negative = false;

    if (dividend < 0) {
        dividend = -dividend;
        negative = !negative;
    }

    if (divisor < 0) {
        divisor = -divisor;
        negative = !negative;
    }

    int quotient = 0;

    while (dividend >= divisor) {
        dividend = dividend - divisor;
        quotient++;
    }

    if (negative)
        quotient = -quotient;

    cout << quotient;

    return 0;
}
