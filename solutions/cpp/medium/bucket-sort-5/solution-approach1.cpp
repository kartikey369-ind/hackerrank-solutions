// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/bucket-sort-5/problem?isFullScreen=true
// Problem     BUCKET SORT 5
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:48 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> a(n);

    bool lessThanOne = true;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] >= 1.0)
            lessThanOne = false;
    }

    if (lessThanOne) {
        vector<vector<double>> bucket(n);

        for (int i = 0; i < n; i++) {
            int index = a[i] * n;
            bucket[index].push_back(a[i]);
        }

        for (int i = 0; i < n; i++)
            sort(bucket[i].begin(), bucket[i].end());

        for (int i = 0; i < n; i++) {
            for (double x : bucket[i])
                cout << fixed << setprecision(2) << x << " ";
        }
    } else {
        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++) {
            if (a[i] == (int)a[i])
                cout << (int)a[i] << " ";
            else
                cout << fixed << setprecision(2) << a[i] << " ";
        }
    }

    return 0;
}
