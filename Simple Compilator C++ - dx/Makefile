CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRC_DIR = src
INC_DIR = include

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:.cpp=.o)

TARGET = simple_compiler

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS
