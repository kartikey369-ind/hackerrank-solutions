// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/wild-card-matching-patterns/problem?isFullScreen=true
// Problem     WILD CARD PATTERNS
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:54 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <string>

using namespace std;

bool isMatch(const string& s, const string& p) {
    int sLen = s.length(), pLen = p.length();
    int sIdx = 0, pIdx = 0;
    int starIdx = -1, sTmpIdx = -1;

    while (sIdx < sLen) {
        if (pIdx < pLen && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
            sIdx++;
            pIdx++;
        } 
        else if (pIdx < pLen && p[pIdx] == '*') {
           
            starIdx = pIdx;
            sTmpIdx = sIdx;
            pIdx++;
        } 
        else if (starIdx != -1) {
            pIdx = starIdx + 1;
            sTmpIdx++;
            sIdx = sTmpIdx;
        } 
        else {
            return false;
        }
    }
    while (pIdx < pLen && p[pIdx] == '*') {
        pIdx++;
    }

    return pIdx == pLen;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, p;
    if (cin >> s >> p) {
        cout << (isMatch(s, p) ? 1 : 0) << "\n";
    }

    return 0;
}
