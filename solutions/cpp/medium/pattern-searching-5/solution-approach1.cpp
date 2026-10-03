// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/pattern-searching-5/problem?isFullScreen=true
// Problem     PATTERN SEARCHING 5
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:53 p.m.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

int main() {
    string txt, pat;
    getline(cin, txt);
    getline(cin, pat);

    int n = txt.size(), m = pat.size();
    vector<int> lps(m, 0);

    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && pat[i] != pat[j])
            j = lps[j - 1];

        if (pat[i] == pat[j])
            j++;

        lps[i] = j;
    }

    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && txt[i] != pat[j])
            j = lps[j - 1];

        if (txt[i] == pat[j])
            j++;

        if (j == m) {
            cout << i - m + 1 << "\n";
            j = lps[j - 1];
        }
    }

    return 0;
}
