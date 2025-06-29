#include "graph.h"
#include <queue>
#include <iostream>
#include <climits>
#include <fstream>
#include <sstream>

vector<vector<Edge>> adj(200);
vector<string> stations;
map<string, ll> colorFare;

void build_graph() {
    // Load stations
    ifstream fin("lines.txt");
    string stationName;
    while (getline(fin, stationName)) {
        stations.push_back(stationName);
    }
    fin.close();

    // Define fares for each color
    colorFare["yellowline"] = 7;
    colorFare["blueline"] = 6;
    colorFare["bluelineext"] = 5;
    colorFare["greenline"] = 4;
    colorFare["redline"] = 5;
    colorFare["orangeline"] = 10;
    colorFare["violetline"] = 6;

    // Load connections
    ifstream conn("connections.txt");
    string line;
    while (getline(conn, line)) {
        stringstream ss(line);
        string src, dest, color;
        ss >> src >> dest >> color;

        int srcIndex = -1, destIndex = -1;
        for (size_t i = 0; i < stations.size(); ++i) {
            if (stations[i] == src) srcIndex = i;
            if (stations[i] == dest) destIndex = i;
        }

        if (srcIndex != -1 && destIndex != -1) {
            ll fare = colorFare[color];
            adj[srcIndex].push_back({destIndex, fare});
            adj[destIndex].push_back({srcIndex, fare});
        }
    }
    conn.close();
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
            int v = edge.to;
            ll weight = edge.fare;

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
            int v = edge.to;
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





