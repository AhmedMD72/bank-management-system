CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

SRC = main.cpp $(wildcard src/*.cpp)

main:
	$(CXX) $(CXXFLAGS) $(SRC) -o main