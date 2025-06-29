#include "graph.h"
#include <queue>
#include <iostream>
#include <climits>
#include <fstream>

vector<vector<pair<int, ll>>> adj(200);
vector<string> stations;

void build_graph() {
    ifstream fin("lines.txt");
    string stationName;
    while (getline(fin, stationName)) {
        stations.push_back(stationName);
    }
    fin.close();

    // Example hardcoded graph, update with your actual connections
    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});
    adj[1].push_back({2, 15});
    adj[2].push_back({1, 15});
    // Add more connections here
}

pair<vector<int>, ll> dijkstra(int src, int dest) {
    vector<ll> dist(200, LLONG_MAX);
    vector<int> parent(200, -1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();

        if (u == dest) break;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            ll weight = edge.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    vector<int> path;
    for (int at = dest; at != -1; at = parent[at])
        path.insert(path.begin(), at);

    return {path, dist[dest]};
}

pair<vector<int>, ll> bfs(int src, int dest) {
    vector<bool> visited(200, false);
    vector<int> parent(200, -1);
    queue<int> q;

    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == dest) break;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    vector<int> path;
    for (int at = dest; at != -1; at = parent[at])
        path.insert(path.begin(), at);

    return {path, (ll)(path.size() - 1)};
}



