CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2
TARGET = main
SRCS = main.cpp dial.cpp
OBJS = $(SRCS:.cpp=.o)
all: build
build: $(TARGET)
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)
run: $(TARGET)
	./$(TARGET)
clean:
	rm -f $(TARGET)
.PHONY: all build run clean