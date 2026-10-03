// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/2026-competitive-coding-lab1/challenges/ford-fulkerson-algorithm-1/problem?isFullScreen=true
// Problem     FORD FULKERSON ALGORITHM
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-10-03, 08:54 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool bfs(const vector<vector<int>>& residualCapacity, int s, int t, vector<int>& parent) {
    int V = residualCapacity.size();
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; ++v) {
            
            if (!visited[v] && residualCapacity[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return false; 
}

long long fordFulkerson(int V, vector<vector<int>>& capacity, int s, int t) {
    vector<vector<int>> residualCapacity = capacity;
    
    vector<int> parent(V); 
    long long maxFlow = 0; 

    while (bfs(residualCapacity, s, t, parent)) {
        
        int pathFlow = 1e9 + 7;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualCapacity[u][v]);
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            residualCapacity[u][v] -= pathFlow;
            residualCapacity[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    if (!(cin >> V >> E)) return 0;

    vector<vector<int>> capacity(V, vector<int>(V, 0));

    for (int i = 0; i < E; ++i) {
        int u, v, cap;
        cin >> u >> v >> cap;
        capacity[u][v] += cap;
    }

    int source = 0;
    int sink = V - 1;

    cout << fordFulkerson(V, capacity, source, sink) << "\n";

    return 0;
}
