// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/tug-of-war-11/problem?isFullScreen=true
// Problem     TUG OF WAR 11
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:56 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

// Helper function to generate all (count, sum) pairs for a subarray
void generateSubsets(const vector<int>& arr, vector<vector<int>>& subsets) {
    int size = arr.size();
    int totalMasks = 1 << size;
    for (int mask = 0; mask < totalMasks; ++mask) {
        int count = 0;
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            if (mask & (1 << i)) {
                count++;
                sum += arr[i];
            }
        }
        subsets[count].push_back(sum);
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    int totalSum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        totalSum += arr[i];
    }

    int mid = n / 2;
    vector<int> leftArr(arr.begin(), arr.begin() + mid);
    vector<int> rightArr(arr.begin() + mid, arr.end());

    // leftSubsets[k] stores all possible sums of subsets of size k from left half
    vector<vector<int>> leftSubsets(leftArr.size() + 1);
    // rightSubsets[k] stores all possible sums of subsets of size k from right half
    vector<vector<int>> rightSubsets(rightArr.size() + 1);

    generateSubsets(leftArr, leftSubsets);
    generateSubsets(rightArr, rightSubsets);

    // Sort and remove duplicates from rightSubsets for binary search
    for (int k = 0; k <= (int)rightArr.size(); ++k) {
        sort(rightSubsets[k].begin(), rightSubsets[k].end());
        rightSubsets[k].erase(unique(rightSubsets[k].begin(), rightSubsets[k].end()), rightSubsets[k].end());
    }

    int targetGroupSize = n / 2; // Size of group 1 (other group has size n - targetGroupSize)
    int minDiff = 2e9;

    // We select k elements from left half and (targetGroupSize - k) from right half
    for (int k = 0; k <= (int)leftArr.size(); ++k) {
        int r_k = targetGroupSize - k;
        if (r_k < 0 || r_k > (int)rightArr.size()) continue;

        const auto& rightVec = rightSubsets[r_k];
        if (rightVec.empty()) continue;

        for (int leftSum : leftSubsets[k]) {
            // Ideal sum for group 1 is totalSum / 2
            int idealRightSum = totalSum / 2 - leftSum;

            // Find closest element in rightVec using lower_bound
            auto it = lower_bound(rightVec.begin(), rightVec.end(), idealRightSum);

            if (it != rightVec.end()) {
                int group1Sum = leftSum + *it;
                int diff = abs(totalSum - 2 * group1Sum);
                minDiff = min(minDiff, diff);
            }
            if (it != rightVec.begin()) {
                auto prevIt = prev(it);
                int group1Sum = leftSum + *prevIt;
                int diff = abs(totalSum - 2 * group1Sum);
                minDiff = min(minDiff, diff);
            }
        }
    }

    cout << minDiff << "\n";
    return 0;
}
