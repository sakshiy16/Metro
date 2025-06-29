# Compiler
CXX = g++
# Compiler Flags
CXXFLAGS = -Wall -Wextra -std=c++17
# Source Files
SRC = src/graph.cpp src/interface.cpp
# Output Executable
TARGET = metro

# Build Rule
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean Rule
clean:
	del $(TARGET).exe
