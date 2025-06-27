#include "../start/graph.h"
#include <iostream>
#include <algorithm>
#include <stack>

void Graph::add_edge(const std::string& u, const std::string& v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight}); // undirected graph
}

bool Graph::station_exists(const std::string& station) const {
    return adj.find(station) != adj.end();
}

void Graph::print_stations() const {
    int index = 1;
    for (const auto& pair : adj) {
        std::cout << index++ << ". " << pair.first << "\n";
    }
}

std::vector<std::string> Graph::bfs(const std::string& src, const std::string& dest) {
    std::unordered_map<std::string, bool> visited;
    std::unordered_map<std::string, std::string> parent;
    std::queue<std::string> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        std::string current = q.front(); q.pop();
        if (current == dest) break;

        for (const auto& neighbor : adj[current]) {
            if (!visited[neighbor.first]) {
                visited[neighbor.first] = true;
                parent[neighbor.first] = current;
                q.push(neighbor.first);
            }
        }
    }

    std::vector<std::string> path;
    if (!visited[dest]) return path;

    for (std::string at = dest; at != src; at = parent[at]) {
        path.push_back(at);
    }
    path.push_back(src);
    std::reverse(path.begin(), path.end());
    return path;
}

std::vector<std::string> Graph::dijkstra(const std::string& src, const std::string& dest, int& distance) {
    std::unordered_map<std::string, int> dist;
    std::unordered_map<std::string, std::string> parent;
    std::set<std::pair<int, std::string>> pq;

    for (const auto& pair : adj) {
        dist[pair.first] = INT_MAX;
    }
    dist[src] = 0;
    pq.insert({0, src});

    while (!pq.empty()) {
        std::pair<int, std::string> top = *pq.begin();
int d = top.first;
std::string u = top.second;

        pq.erase(pq.begin());

        for (const auto& neighbor : adj[u]) {
    std::string v = neighbor.first;
    int w = neighbor.second;

            if (dist[u] + w < dist[v]) {
                pq.erase({dist[v], v});
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.insert({dist[v], v});
            }
        }
    }

    distance = dist[dest];
    std::vector<std::string> path;
    if (distance == INT_MAX) return path;

    for (std::string at = dest; at != src; at = parent[at]) {
        path.push_back(at);
    }
    path.push_back(src);
    std::reverse(path.begin(), path.end());
    return path;
}

