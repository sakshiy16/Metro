#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <set>

class Graph {
public:
    void add_edge(const std::string& u, const std::string& v, int weight);
    std::vector<std::string> dijkstra(const std::string& src, const std::string& dest, int& distance);
    std::vector<std::string> bfs(const std::string& src, const std::string& dest);
    void print_stations() const;
    bool station_exists(const std::string& station) const;

private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adj;
};

#endif