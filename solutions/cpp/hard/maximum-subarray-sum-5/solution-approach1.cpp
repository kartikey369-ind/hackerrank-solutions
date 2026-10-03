// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/maximum-subarray-sum-5/problem?isFullScreen=true
// Problem     Maximum sub-array-sum
// Difficulty  Hard
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:46 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long max_so_far = arr[0];
        long long current_max = arr[0];

        for (int i = 1; i < n; i++) {
           
            current_max = max((long long)arr[i], current_max + arr[i]);
            
            max_so_far = max(max_so_far, current_max);
        }

        cout << max_so_far << "\n";
    }

    return 0;
}
