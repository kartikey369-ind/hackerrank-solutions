// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/factorial-using-recursion-4/problem?isFullScreen=true
// Problem     Factorial using recursion 4
// Difficulty  Easy
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:44 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
using namespace std;

long long fact(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    if (cin >> n) {
        if (n < 0) {
            cout << "Invalid input" << endl;
        } else {
            cout << fact(n) << endl;
        }
    }
    return 0;
}
