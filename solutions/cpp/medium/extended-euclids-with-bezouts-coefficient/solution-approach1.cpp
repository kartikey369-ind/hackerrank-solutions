// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/extended-euclids-with-bezouts-coefficient/problem?isFullScreen=true
// Problem     EXTENDED EUCLIDS WITH BEZOUTS COEFFICIENT
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:54 p.m.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

long long extgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;
    long long g = extgcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

int main() {
    long long A, B;
    cin >> A >> B;

    long long x0, y0;
    long long D = extgcd(A, B, x0, y0);

    long long p = B / D;
    long long q = A / D;

    long long bestX = x0;
    long long bestY = y0;

    auto check = [&](long long k) {
        long long x = x0 + k * p;
        long long y = y0 - k * q;

        long long cur = llabs(x) + llabs(y);
        long long best = llabs(bestX) + llabs(bestY);

        if (cur < best || (cur == best && x <= y)) {
            bestX = x;
            bestY = y;
        }
    };

    long long k1 = -x0 / p;
    check(k1);
    check(k1 - 1);
    check(k1 + 1);

    long long k2 = y0 / q;
    check(k2);
    check(k2 - 1);
    check(k2 + 1);

    cout << bestX << " " << bestY << " " << D;

    return 0;
}
