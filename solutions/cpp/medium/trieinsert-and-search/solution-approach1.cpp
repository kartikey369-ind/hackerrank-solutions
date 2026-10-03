// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/trieinsert-and-search/problem?isFullScreen=true
// Problem     Trie(Insert and Search)
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:53 p.m.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* child[26];
    bool end;

    Node() {
        end = false;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

void insert(Node* root, string s) {
    Node* cur = root;

    for (char c : s) {
        int x = c - 'a';

        if (cur->child[x] == NULL)
            cur->child[x] = new Node();

        cur = cur->child[x];
    }

    cur->end = true;
}

bool search(Node* root, string s) {
    Node* cur = root;

    for (char c : s) {
        int x = c - 'a';

        if (cur->child[x] == NULL)
            return false;

        cur = cur->child[x];
    }

    return cur->end;
}

int main() {
    int n;
    cin >> n;

    string line;
    cin >> line;

    Node* root = new Node();

    string word = "";

    for (char c : line) {
        if (c == ',') {
            insert(root, word);
            word = "";
        } else {
            word += c;
        }
    }

    insert(root, word);

    string s;
    cin >> s;

    cout << (search(root, s) ? 1 : 0);

    return 0;
}
