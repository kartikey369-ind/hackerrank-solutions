// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/maximum-ascending-subarray-sum-1/problem?isFullScreen=true
// Problem     Maximum Ascending Subarray Sum 1
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:47 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
using namespace std;

int maxAscendingSum(vector<int>& arr) {
    int curr = arr[0];
    int ans = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > arr[i - 1])
            curr += arr[i];
        else
            curr = arr[i];

        ans = max(ans, curr);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxAscendingSum(arr);

    return 0;
}
