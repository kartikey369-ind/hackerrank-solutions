// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/hackerrank-in-a-string-1-2/problem?isFullScreen=true
// Problem     HackerRank in a String! 1
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

    string t = "hackerrank";
    int j = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == t[j])
            j++;

        if (j == t.length())
            break;
    }

    if (j == t.length())
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
