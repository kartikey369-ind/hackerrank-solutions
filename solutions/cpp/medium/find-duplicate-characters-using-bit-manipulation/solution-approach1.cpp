// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/find-duplicate-characters-using-bit-manipulation/problem?isFullScreen=true
// Problem     Find Duplicate Characters Using Bit Manipulation
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
    string s;
    cin >> s;

    int seen = 0, dup = 0, printed = 0;

    for (char c : s) {
        int x = c - 'a';

        if (seen & (1 << x))
            dup |= (1 << x);
        else
            seen |= (1 << x);
    }

    bool first = true;

    for (char c : s) {
        int x = c - 'a';

        if ((dup & (1 << x)) && !(printed & (1 << x))) {
            if (!first) cout << " ";
            cout << c;
            first = false;
            printed |= (1 << x);
        }
    }

    if (first)
        cout << "No duplicates";

    return 0;
}
