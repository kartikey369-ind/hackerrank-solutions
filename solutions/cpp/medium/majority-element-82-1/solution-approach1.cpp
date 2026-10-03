// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/majority-element-82-1/problem?isFullScreen=true
// Problem     Majority Element 82
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

int majorityElement(vector<int>& arr) {
    int candidate = 0, count = 0;

    for (int num : arr) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    count = 0;
    for (int num : arr) {
        if (num == candidate)
            count++;
    }

    if (count > arr.size() / 2)
        return candidate;
    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << majorityElement(arr);

    return 0;
}
