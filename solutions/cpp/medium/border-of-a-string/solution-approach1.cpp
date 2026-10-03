// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/border-of-a-string/problem?isFullScreen=true
// Problem     Border of a String
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:52 p.m.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    vector<int> lps(n, 0);

    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && s[i] != s[j])
            j = lps[j - 1];

        if (s[i] == s[j])
            j++;

        lps[i] = j;
    }

    cout << s.substr(0, lps[n - 1]);

    return 0;
}
