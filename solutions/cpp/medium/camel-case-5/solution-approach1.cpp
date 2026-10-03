// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/camel-case-5/problem?isFullScreen=true
// Problem     CAMEL CASE 5
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
    int n;
    cin >> n;

    string line, pattern;
    cin >> line >> pattern;

    vector<string> ans;
    stringstream ss(line);
    string word;

    while (getline(ss, word, ',')) {
        string abbr = "";

        for (char c : word)
            if (isupper(c))
                abbr += c;

        int j = 0;

        for (char c : abbr) {
            if (j < pattern.size() && c == pattern[j])
                j++;
        }

        if (j == pattern.size())
            ans.push_back(word);
    }

    sort(ans.begin(), ans.end());

    if (ans.empty())
        cout << "No match found";
    else
        for (string x : ans)
            cout << x << "\n";

    return 0;
}
