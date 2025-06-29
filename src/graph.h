#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;
using ll = long long;

struct Edge {
    int to;
    ll fare;
};

extern vector<vector<Edge>> adj;
extern vector<string> stations;
extern map<string, ll> colorFare;

void build_graph();
pair<vector<int>, ll> dijkstra(int src, int dest);
pair<vector<int>, ll> bfs(int src, int dest);

#endif


