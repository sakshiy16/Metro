#include "graph.h"
#include <iostream>
#include <fstream>
using namespace std;

ll balance = 0;

void recharge_card() {
    cout << "Enter recharge amount: ";
    ll amount;
    cin >> amount;
    balance += amount;
    ofstream fout("fare.txt");
    fout << balance;
    fout.close();
    cout << "Recharge successful! Current balance: " << balance << endl;
}

void load_balance() {
    ifstream fin("fare.txt");
    if (fin) fin >> balance;
    fin.close();
}

void print_path(const vector<int>& path) {
    for (size_t i = 0; i < path.size(); ++i) {
        cout << stations[path[i]];
        if (i != path.size() - 1) cout << " -> ";
    }
    cout << endl;
}

int main() {
    build_graph();
    load_balance();

    int choice;
    do {
        cout << "\n1. Find Cheapest Route\n2. Find Shortest Route\n3. Recharge Smart Card\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            string srcName, destName;
            cout << "Enter source station name: ";
            cin >> ws;
            getline(cin, srcName);
            cout << "Enter destination station name: ";
            getline(cin, destName);

            int src = -1, dest = -1;
            for (size_t i = 0; i < stations.size(); ++i) {
                if (stations[i] == srcName) src = i;
                if (stations[i] == destName) dest = i;
            }

            if (src == -1 || dest == -1) {
                cout << "Invalid station name entered!\n";
                continue;
            }

            pair<vector<int>, ll> result = (choice == 1) ? dijkstra(src, dest) : bfs(src, dest);
            cout << "Route: ";
            print_path(result.first);
            cout << ((choice == 1) ? "Total Fare: " : "Number of Stations: ") << result.second << endl;

            if (choice == 1 && balance >= result.second) {
                balance -= result.second;
                ofstream fout("fare.txt");
                fout << balance;
                fout.close();
                cout << "Fare deducted. Remaining balance: " << balance << endl;
            } else if (choice == 1 && balance < result.second) {
                cout << "Insufficient balance!\n";
            }

        } else if (choice == 3) {
            recharge_card();
        }

    } while (choice != 4);

    return 0;
}




