// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/find-the-triplets-2/problem?isFullScreen=true
// Problem     Find the Triplets 2
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:50 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    sort(arr.begin(), arr.end());

    bool found = false;

    for (int i = 0; i < n - 2; i++) {

        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {

            long long sum = 1LL * arr[i] + arr[left] + arr[right];

            if (sum == x) {
                cout << arr[i] << " " << arr[left] << " " << arr[right] << endl;
                found = true;

                while (left < right && arr[left] == arr[left + 1])
                    left++;

                while (left < right && arr[right] == arr[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (sum < x) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    if (!found)
        cout << "No triplet found";

    return 0;
}
