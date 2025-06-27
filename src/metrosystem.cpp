#include "../start/metrosystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

MetroSystem::MetroSystem() {}

void MetroSystem::load_line_data(const std::string& filename) {
    std::ifstream file("data/" + filename);
    std::string prev, current;
    int weight = 1;

    if (!file.is_open()) {
        std::cerr << "Error opening line file: " << filename << "\n";
        return;
    }

    if (!std::getline(file, prev)) return;
    while (std::getline(file, current)) {
        graph.add_edge(prev, current, weight);
        prev = current;
    }
    file.close();
}

void MetroSystem::load_all_lines() {
    std::ifstream config("data/lines.txt");
    std::string line_file;

    if (!config.is_open()) {
        std::cerr << "Error: lines.txt not found in /data.\n";
        return;
    }

    while (std::getline(config, line_file)) {
        load_line_data(line_file);
    }
}

void MetroSystem::display_all_stations() const {
    graph.print_stations();
}

bool MetroSystem::is_valid_station(const std::string& name) const {
    return graph.station_exists(name);
}

void MetroSystem::find_shortest_path_by_distance(const std::string& src, const std::string& dest) {
    int distance = 0;
    auto path = graph.dijkstra(src, dest, distance);

    if (path.empty()) {
        std::cout << "No path found.\n";
        return;
    }

    std::cout << "\nShortest path (by distance):\n";
    for (const auto& station : path) {
        std::cout << station << " -> ";
    }
    std::cout << "END\nDistance: " << distance << " units\n";
    show_fare_estimate(distance);
}

void MetroSystem::find_shortest_path_by_stops(const std::string& src, const std::string& dest) {
    auto path = graph.bfs(src, dest);

    if (path.empty()) {
        std::cout << "No path found.\n";
        return;
    }

    std::cout << "\nShortest path (by stops):\n";
    for (const auto& station : path) {
        std::cout << station << " -> ";
    }
    std::cout << "END\nStops: " << path.size() - 1 << "\n";
}

void MetroSystem::show_fare_estimate(int distance) const {
    int fare = 0;
    if (distance <= 2) fare = 10;
    else if (distance <= 5) fare = 20;
    else if (distance <= 12) fare = 30;
    else fare = 40;

    std::cout << "Estimated Fare: ₹" << fare << "\n";
}

