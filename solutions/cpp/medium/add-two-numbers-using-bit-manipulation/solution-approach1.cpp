// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/add-two-numbers-using-bit-manipulation/problem?isFullScreen=true
// Problem     Add Two Numbers Using Bit Manipulation
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
    int a, b;
    cin >> a >> b;

    while (b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }

    cout << a;

    return 0;
}
