# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -g -fsanitize=address -O1 -fno-omit-frame-pointer -std=c++17
LDFLAGS = -lSDL2

# Directories
SRC_DIR = src
OBJ_DIR = obj

# Source files (main.cpp + all .cpp files in src/)
SRCS = main.cpp $(wildcard $(SRC_DIR)/*.cpp)

# Object files (store .o files in obj/, stripping 'src/')
OBJS = $(OBJ_DIR)/main.o
OBJS += $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(wildcard $(SRC_DIR)/*.cpp))

# Executable name
EXEC = tetris

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Ensure obj/ directory exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile main.cpp separately
$(OBJ_DIR)/main.o: main.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile all other .cpp files inside src/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

.PHONY: all clean
