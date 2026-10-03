// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/counting-sort-12/problem?isFullScreen=true
// Problem     counting sort 12
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:48 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
using namespace std;

vector<int> countingSort(vector<int> arr) {
    vector<int> count(100, 0);

    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }

    vector<int> result;
    for (int i = 0; i < 100; i++) {
        while (count[i] > 0) {
            result.push_back(i);
            count[i]--;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = countingSort(arr);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}
