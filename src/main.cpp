#include "../start/metrosystem.h"
#include <iostream>

int main() {
    MetroSystem metro;
    metro.load_all_lines();

    int choice;
    std::string src, dest;

    while (true) {
        std::cout << "\n===== METRO ROUTE FINDER =====\n";
        std::cout << "1. Show All Stations\n";
        std::cout << "2. Shortest Path by Distance\n";
        std::cout << "3. Shortest Path by Stops\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore();  // flush newline

        if (choice == 0) break;

        switch (choice) {
            case 1:
                metro.display_all_stations();
                break;

            case 2:
            case 3:
                std::cout << "Enter source station: ";
                std::getline(std::cin, src);
                std::cout << "Enter destination station: ";
                std::getline(std::cin, dest);

                if (!metro.is_valid_station(src) || !metro.is_valid_station(dest)) {
                    std::cout << "Invalid station(s). Try again.\n";
                    break;
                }

                if (choice == 2)
                    metro.find_shortest_path_by_distance(src, dest);
                else
                    metro.find_shortest_path_by_stops(src, dest);
                break;

            default:
                std::cout << "Invalid choice.\n";
        }
    }

    std::cout << "Thank you for using Metro Route Finder!\n";
    return 0;
}
