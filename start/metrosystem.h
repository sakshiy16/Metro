#ifndef METROSYSTEM_H
#define METROSYSTEM_H

#include "graph.h"
#include <string>

class MetroSystem {
public:
    MetroSystem();
    void load_line_data(const std::string& filename);
    void load_all_lines();
    void display_all_stations() const;
    void find_shortest_path_by_distance(const std::string& src, const std::string& dest);
    void find_shortest_path_by_stops(const std::string& src, const std::string& dest);
    void show_fare_estimate(int distance) const;
    bool is_valid_station(const std::string& name) const;

private:
    Graph graph;
};

#endif
