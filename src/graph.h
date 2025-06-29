#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <utility>

using namespace std;
using ll = long long;

extern vector<vector<pair<int, ll>>> adj;
extern vector<string> stations;

void build_graph();
pair<vector<int>, ll> dijkstra(int src, int dest);
pair<vector<int>, ll> bfs(int src, int dest);

#endif
