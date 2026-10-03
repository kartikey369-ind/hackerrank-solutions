// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/water-jug-problem-5/problem?isFullScreen=true
// Problem     WATER JUG PROBLEM 5
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:54 p.m.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B, T;

    cin >> A >> B >> T;

    if (T <= max(A, B) && T % __gcd(A, B) == 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
