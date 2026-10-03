// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/merging-two-sorted-arrays-2-2/problem?isFullScreen=true
// Problem     MERGING TWO SORTED ARRAYS 2
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:46 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();
    vector<int> merged;
    merged.reserve(n + m); 

    int i = 0; 
    int j = 0; 
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    while (i < n) {
        merged.push_back(arr1[i]);
        i++;
    }

    while (j < m) {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    int m;
    if (!(cin >> m)) return 0;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    vector<int> result = mergeSortedArrays(arr1, arr2);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}
