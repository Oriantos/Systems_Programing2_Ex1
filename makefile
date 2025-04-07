CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Source files
SRCS = main.cpp Graph.cpp DataStrauctures.cpp Algorithms.cpp
TEST_SRCS = doctest.cpp Graph.cpp DataStrauctures.cpp Algorithms.cpp
VALGRIND=-v --leak-check=full --show-leak-kinds=all --error-exitcode=99

# Executables
MAIN_EXE = main
TEST_EXE = test

# Build main program
main: $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(MAIN_EXE) $(SRCS)

# Build test executable
test: $(TEST_SRCS)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXE) $(TEST_SRCS)

# Run valgrind on
valgrind: main
	valgrind $(VALGRIND_FLAGS) ./main

# Clean build artifacts
clean:
	rm -f $(MAIN_EXE) $(TEST_EXE)
