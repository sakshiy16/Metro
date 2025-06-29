# Metro Route Finder and Fare Calculator

This is a C++ console-based Metro application that allows users to:
- Find the **cheapest route** between two metro stations.
- Find the **shortest route** (minimum number of stations) between two metro stations.
- Manage a **smart card balance** for fare deduction.
- Recharge their smart card balance.

## 🚀 Features
- Fast pathfinding using **Dijkstra's algorithm** (for minimum fare).
- Quick traversal using **BFS** (for shortest route in terms of stations).
- Smart card system with **balance management**.
- Reads metro lines and station data from external files.
- Fare calculation is based on the colors of the metro lines.

## 🛠️ Tech Stack
- **C++**
- File Handling
- Graph Algorithms (Dijkstra, BFS)

## 📂 Project Structure
```plaintext
├── src/
│   ├── graph.cpp      # Graph building and pathfinding algorithms
│   ├── graph.h        # Graph structures and declarations
│   └── interface.cpp  # Main interface, smart card logic
├── lines.txt          # List of metro stations
├── connections.txt    # Metro connections with fare colors
├── fare.txt           # Stores current smart card balance
├── blueline.txt
├── bluelineext.txt
├── greenline.txt
├── redline.txt
├── yellowline.txt
├── orangeline.txt
├── violetline.txt
├── tour.txt
├── Makefile
├── metro.exe
```
## 📥 Setup Instructions
  ### 1. Clone the repository:
  ```plaintext
     git clone https://github.com/sakshiy16/Metro.git
     cd Metro/src
   ```
 ### 2. Compile the project:
 ```plaintext
    g++ interface.cpp graph.cpp -o metro
   ```
 ### 3. Run the project:
 ```plaintext
    ./metro
   ```
---

 ### Note:
  Ensure lines.txt, connections.txt, and fare.txt and other text files for color lines are in the same directory as the executable.

## ⚙️ Usage
When you run the program, you will see:
```plaintext
1. Find Cheapest Route
2. Find Shortest Route
3. Recharge Smart Card
4. Exit
Enter choice:
```
- Choose Option 1 to find the cheapest route and deduct fare.
- Choose Option 2 to find the shortest route (by number of stations).
- Choose Option 3 to recharge your smart card.


## 🧮 Fare Calculation
Fares are based on metro line colors:

- Yellow Line: 7 Rs/station

- Blue Line: 6 Rs/station

- Blue Line Extension: 5 Rs/station

- Green Line: 4 Rs/station

- Red Line: 5 Rs/station

- Orange Line: 10 Rs/station

- Violet Line: 6 Rs/station

## 📄 File Details
- lines.txt:
List of all metro stations.

- connections.txt:
Defines connections between stations with their corresponding metro line colors.

- fare.txt:
Stores the current balance of the smart card.

- yellowline.txt, bluelineext.txt, bluelinhe.txt, greenline.txt, redline.txt, orangeline.txt, violetline.txt:
Each file contains station-wise data for the respective metro line. These files may include details like station order, special notes, or additional data for each line that can be used for line-specific processing, visualization, or tours.

- tour.txt:
Appears to store tour-related data. This could include popular metro tours, suggested routes, or landmark-based navigation using the metro system.

- Makefile:
Contains build instructions to compile the project efficiently using make. Allows you to build the project with a simple make command.

## 👩‍💻 Author
- Sakshi Yadav
- GitHub: sakshiy16

## 📜 License
This project is open-source and available under the MIT License.
        
